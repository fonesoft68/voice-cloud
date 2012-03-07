#include "soapH.h"
#include "Client_2.nsmap"
#include "dime.h"
#include "tasksolve.h"
#include "const.h"

#pragma comment(lib,"ws2_32.lib")

HANDLE QueueMutex;		//队列锁
HANDLE QueueEvent;		//队列事件
struct soap* queue[MAX_QUEUE];
int head=0;
int tail=0;

int busy=0;

//入队列操作
int enqueue(struct soap* soap)
{
	int status = SOAP_OK;
	int next;
	WaitForSingleObject(QueueMutex,INFINITE);
	//printf("One Socket enqueue.\n");
	next = tail +1;
	if (next >= MAX_QUEUE) 
		next = 0;
	if (next == head) 
		status = SOAP_EOM;
	else
	{
		queue[tail] =soap;
		tail = next;
	}
	SetEvent(QueueEvent);
	ReleaseMutex(QueueMutex);
	return status;
}

//出队列操作
struct soap* dequeue()
{
	struct soap* soap;
	WaitForSingleObject(QueueMutex,INFINITE);
	while (head == tail )
	{
		ReleaseMutex(QueueMutex);
		WaitForSingleObject(QueueEvent,INFINITE);
		WaitForSingleObject(QueueMutex,INFINITE);
	}
	//printf("%s\n","One Socket dequeue.");
	soap = queue[head++];
	if (head >= MAX_QUEUE)
	{
		head =0;
	}
	ReleaseMutex(QueueMutex);	
	return soap;
}

//线程入口函数
DWORD WINAPI process_queue(LPVOID pParm)
{
	struct soap * tsoap;
	for(;;)
	{
		tsoap = dequeue();
		if (!soap_valid_socket(tsoap->socket))
		{
			break;
		}
		if (soap_serve(tsoap) != SOAP_OK) // process RPC request 
			soap_print_fault(tsoap, stderr); // print error 
		fprintf(stderr, "request served\n");
		soap_destroy(tsoap);
		soap_end(tsoap);
		soap_done(tsoap);
		free(tsoap);
	}
	return 0;
}


int getNumber(char* s,int& idx)
{
	int i=idx;
	int len=strlen(s);
	int num=0;
	while (('0'<=s[i]) && (s[i]<='9'))
	{
		num=num*10+(s[i]-'0');
		++i;
		if (i==len)
		{
			break;
		}
	}
	idx=i+1;
	return num;
}


void add(char* task,char* result)
{
	int idx=0;
	int a=getNumber(task,idx);
	int b=getNumber(task,idx);
	char* buffer=(char*)malloc(BUFFER_SIZE);
	sprintf(buffer,"%d %d %d\n",a,b,a+b);
	strcat(result,buffer);
	free(buffer);
}

int solveTask(ClientTask* ct,int start,int end,char* restr)
{
	ct->parseTaskList(start,end);
	ct->solve();
	ct->replyans(restr,end-start+1);
	return 0;
}

int ns__TaskSolve(struct soap* soap,int taskId,struct soap_string task,struct soap_string& ret)
{
	busy=1;
	ret.str=(char*)soap_malloc(soap,BUFFER_SIZE);
	memset(ret.str,0,BUFFER_SIZE);
	if(task.size!=strlen(task.str))
	{
		sprintf(ret.str,"%s","1\nRecive size is not correct.\n");
	}
	else
	{
		//sprintf(ret.str,"%s","0\nRecive size is correct.\n");
		int idx=0;
		int start=getNumber(task.str,idx);
		int end=getNumber(task.str,idx);
		printf("Task Solve:\nstart:%d end:%d\n",start,end);
		switch (taskId)
		{
		case 0:
			break;
		case 4:
			solveTask(new KWS,start,end,ret.str);
			break;
		}
		printf("\n%s\n",ret.str);
	}
	ret.size=strlen(ret.str);
	busy=0;
	return SOAP_OK;
}

int ns__isBusy(struct soap* soap,void* v,int& flag)
{
	flag=busy;
	//printf("IsBusy : %d",flag);
	return SOAP_OK;
}

int main() 
{
   struct soap soap; 
   struct soap* tsoap;
   int m, s; // master and slave sockets 
   soap_init1(&soap, SOAP_IO_KEEPALIVE | SOAP_IO_CHUNK);
   
   // set DIME callbacks
   soap.fdimewriteopen = dime_write_open;
   soap.fdimewriteclose = dime_write_close;
   soap.fdimewrite = dime_write;
  
   HANDLE hthreads[MAX_THR];

   //锁和事件的初始化
   QueueMutex=CreateMutex(NULL,false,NULL);
   QueueEvent=CreateEvent(NULL,false,false,NULL);
   m = soap_bind(&soap, NULL, port , BACKLOG); 
   if (m < 0) 
      soap_print_fault(&soap, stderr); 
   else
   { 
      fprintf(stderr, "Socket connection successful: master socket = %d\n", m); 
	  //生成服务线程
	  int i;
	  for(i = 0; i <MAX_THR; i++)

	  {
		  fprintf(stderr,"Starting thread %d \n",i);
		  hthreads[i]=CreateThread(NULL,0,process_queue,NULL,0,NULL);
	  }
	  for ( i = 1; ; i++) 
      {
		  //接受客户端的连接
		  s = soap_accept(&soap);
		  if (!soap_valid_socket(s)) 
		  {
			  if (soap.errnum) 
			  {
				  soap_print_fault(&soap,stderr);
				  continue;
			  }else
			  {
				  fprintf(stderr,"Server timed out ");
				  break;
			  }
		  }
		  //客户端的IP地址
         //fprintf(stderr, "%d: accepted connection from IP=%d.%d.%d.%d socket=%d\n", i, 
           // (soap.ip >> 24)&0xFF, (soap.ip >> 16)&0xFF, (soap.ip >> 8)&0xFF, soap.ip&0xFF, s); 
         tsoap = soap_copy(&soap);
		 //请求的套接字进入队列，如果队列已满则循环等待
		 while(enqueue(tsoap) == SOAP_EOM)
			 Sleep(1000); 
		 
      } 
	  //服务结束后的清理工作
	  int j;
	  for(j = 0; j < MAX_THR; j++)
	  {
		  while (enqueue(NULL) == SOAP_EOM) 
		  {
			  Sleep(1000);
		  }
	  }
	  for(j=0; j< MAX_THR; j++)
	  {
		  fprintf(stderr,"Waiting for thread %d to terminate ..",i);
		  WaitForSingleObject(hthreads[j],INFINITE);
		  CloseHandle(hthreads[j]);
		  fprintf(stderr,"terminated ");
	  }
	  CloseHandle(QueueMutex);
	  CloseHandle(QueueEvent);
   } 
   soap_done(&soap); // close master socket and detach environment 
} 







