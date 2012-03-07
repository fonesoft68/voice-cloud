//gsoap ns service name: Client_2
//gsoap ns service style: rpc
//gsoap ns service namespace: http://10.42.43.42:8080/Client_2.wsdl
//gsoap ns service location: http://10.42.43.42:8080/
//gsoap ns service encoding: encoded
//gsoap ns schema namespace: urn:Client_2

struct ns__data
{ unsigned char *__ptr; /* points to data */
  int __size;		/* size of data */
  char *id;		/* dime attachment ID (set to NULL to obtain unique cid) */
  char *type;		/* dime attachment content type */
  char *options;	/* dime attachment options (optional) */
};

struct soap_string
{
	int size;
	char* str;
};


int ns__ReceiveTaskList(struct ns__data data, struct soap_string& rest);				//接受单个用户提交的任务列表
int ns__TaskSolve(int taskId,struct soap_string task,struct soap_string& ret);
int ns__isBusy(void*,int& flag);