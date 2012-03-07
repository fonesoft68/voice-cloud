#include "soapH.h"
#include "Client_USCORE1.nsmap"
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <signal.h> 
#include <string.h>
#define MAXLINE 1024
struct taskrecfunc
{
	char *funname;
	int (*funcptr)();
}symtab[]={
	{"soap_call_ns1__ReceiveTaskList",soap_call_ns1__ReceiveTaskList},
	{"soap_call_ns2__ReceiveTaskList",soap_call_ns2__ReceiveTaskList},
	{"soap_call_ns3__ReceiveTaskList",soap_call_ns3__ReceiveTaskList},
	{"soap_call_ns1__TaskSolve",soap_call_ns1__TaskSolve},
	{"soap_call_ns2__TaskSolve",soap_call_ns2__TaskSolve},
	{"soap_call_ns3__TaskSolve",soap_call_ns3__TaskSolve},
	{"soap_call_ns1__isBusy",soap_call_ns1__isBusy},
	{"soap_call_ns2__isBusy",soap_call_ns2__isBusy},
	{"soap_call_ns3__isBusy",soap_call_ns3__isBusy},
};
int main()
{
	int cur_client=3;
	int i;
	struct ns1__TaskSolveResponse tasksolveresponse;
	int taskId;
	char *taskstring;
	int result;
	FILE *fp_user=fopen("/home/owenwj/prog/client/Userinfo.txt","rt+");
	FILE *fp_task;
	FILE *fp_result;
	char *buf_user;
	char *buf_result;
	struct ns1__soap_string tasklist;
	char *temptask;
	int pid;
	int cur_line=1;
	int tot_line=-1;
	int cli_core_num[cur_client];
	int flag[cur_client];
	struct soap soap;
	taskId=0;
	for (i=0;i<cur_client;i++)
	{
		cli_core_num[i]=1;
		flag[i]=1;
	}
	soap_init(&soap);
	buf_user=(char *)malloc(30);
	bzero(buf_user,30);
	buf_result=(char *)malloc(30);
	bzero(buf_result,strlen(buf_result));
	temptask=(char *)malloc(20);
	bzero(temptask,strlen(temptask));
	tasklist.str=(char *)malloc(10000);
	bzero(tasklist.str,strlen(tasklist.str));
	while(!feof(fp_user))
	{
		bzero(buf_user,30);
		fgets(buf_user,31,fp_user);
		printf("%s\n",buf_user);
		if(strlen(buf_user)==0)
		{
			break;
		}
		//printf("%s",buf_user);
		buf_user[strlen(buf_user)-1]='\0';
		strcpy(buf_result,buf_user);
		strcat(buf_user,".txt");
		strcat(buf_result,"_result.txt");
		if((fp_task=fopen(buf_user,"rt+"))==NULL)
		{
			printf("fail to open task file!");
			exit(1);
		}
		if((fp_result=fopen(buf_result,"wt+"))==NULL)
		{
			printf("fail to open result file!");
			exit(1);
		}
		tot_line=-1;
		while(!feof(fp_task))
		{
			fgets(temptask,20,fp_task);
			tot_line++;
			strcat(tasklist.str,temptask);
			bzero(temptask,strlen(temptask));
		}
		//printf("%s",tasklist.str);
        tasklist.size=strlen(tasklist.str);
		for(i=0;i<cur_client;i++)
		{
			symtab[i].funcptr(&soap,NULL,NULL,&tasklist,NULL);
			printf("task sent to client %d successful!\n",i);
		}
		bzero(tasklist.str,strlen(tasklist.str));
		while(cur_line<=tot_line)
		{
			for(i=0;i<cur_client;i++)
			{
				if(cur_line>tot_line)break;
				//soap_call_ns1__isBusy(&soap,NULL,NULL,&flag[i]);
				symtab[2*cur_client+i].funcptr(&soap,NULL,NULL,&flag[i]);
				//printf("%d:%d\n",i+1,flag[i]);
				if(flag[i]==0)
				{
					
					int start=cur_line;
					cur_line+=cli_core_num[i];
					int end=cur_line;
					printf("%d:%d\n",i,start);
					pid=fork();
					if(pid<0)
					{
						printf("error in fork!");
					}
					else if(pid==0)
					{
						struct ns1__soap_string taskline;
						taskline.str=(char *)malloc(1024);
						if(cur_line>tot_line)
						{
							sprintf(taskline.str,"%d %d",start,tot_line);
						}
						else
						{
							sprintf(taskline.str,"%d %d",start,end-1);
						}
						taskline.size=strlen(taskline.str);
						//result=soap_call_ns1__TaskSolve(&soap,NULL,NULL,taskId,&taskline,&tasksolveresponse);
						result=symtab[cur_client+i].funcptr(&soap,NULL,NULL,taskId,&taskline,&tasksolveresponse);
						fputs(tasksolveresponse.ret->str,fp_result);
						//printf("%s",tasksolveresponse.ret->str);
						exit(1);
					}
					else
					{
						//signal(SIGCHLD,SIG_IGN);
					}
				}
			}
		}
		bzero(buf_user,30);
		fgets(buf_user,30,fp_user);
		fclose(fp_task);
	}
	printf("done!\n");
	soap_destroy(&soap);
	soap_end(&soap);
	soap_done(&soap);
	fclose(fp_user);
	fclose(fp_result);
	return 0;
}

