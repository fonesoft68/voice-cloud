#include "soapH.h"
#include "tasksolve.h"
#include "const.h"
#include <iostream>
#include <windows.h>
#include <shellapi.h>
#include <winuser.h>
#include <winbase.h>
#include <tchar.h>

using namespace std;

#pragma comment(lib,"Shell32.lib")

int ClientTask::parseTaskList(int start,int end)
{
	int line=1;
	char* buffer=(char*)malloc(BUFFER_SIZE);
	char* temp=(char*)malloc(BUFFER_SIZE);
	FILE* fpr=fopen("tasklist.txt","rt+");
	FILE* fpw=fopen("test_scp.txt","wt+");
	while (line<start)
	{
		fgets(buffer,BUFFER_SIZE,fpr);
		++line;
	}
	while (line<=end)
	{
		memset(buffer,0,BUFFER_SIZE);
		fgets(buffer,BUFFER_SIZE,fpr);
		memset(temp,0,BUFFER_SIZE);
		sprintf(temp,"wav\\%s",buffer);
		fputs(temp,fpw);
		cout<<buffer<<endl;
		++line;
	}
	fclose(fpr);
	fclose(fpw);
	free(buffer);
	free(temp);
	return 0;
}
int KWS::fetchFile(char* buf)
{

	return 0;
}
int KWS::solve()
{
	SHELLEXECUTEINFO  ShExecInfo  =  {0};  
	ShExecInfo.cbSize  =  sizeof(SHELLEXECUTEINFO);  
	ShExecInfo.fMask  =  SEE_MASK_NOCLOSEPROCESS;  
	ShExecInfo.hwnd  =  NULL;  
	ShExecInfo.lpVerb  =  _T("open");  
	ShExecInfo.lpFile  =  _T("D:\\WorkSpace\\Client_Multithread\\taskmodule\\kws\\KTest.exe");                          
	ShExecInfo.lpParameters  =  _T("b D:\\WorkSpace\\Client_Multithread\\test_scp.txt");              
	ShExecInfo.lpDirectory  =  _T("D:\\WorkSpace\\Client_Multithread\\taskmodule\\kws");  
	ShExecInfo.nShow  =  SW_SHOW;  
	ShExecInfo.hInstApp  =  NULL;
 
	if (ShellExecuteEx(&ShExecInfo))
	{
		cout<<"KWS successfully complete."<<endl;
	}else
	{
		cout<<"KWS failed.Error ID: "<<ShExecInfo.hInstApp<<endl;
	}
	WaitForSingleObject(ShExecInfo.hProcess,INFINITE);
	return 0;
}

int KWS::replyans(char* restr,int num)
{
	FILE* fp=fopen("D:\\WorkSpace\\Client_Multithread\\taskmodule\\kws\\output.txt","rt+");
	char* buf=(char*)malloc(BUFFER_SIZE);
	char* temp=(char*)malloc(BUFFER_SIZE);
	while(num!=0)
	{
		fgets(buf,BUFFER_SIZE,fp);
		int i=0;
		int j,k;
		int len=strlen(buf);
		int count=0;
		while (i<len)
		{
			j=i;
			while ((j<len)&&(buf[j]=='/'))
			{
				//printf("ok\n");
				j++;
			}
			if (j!=i)
			{
				j--;
			}
			if (j+1-i!=3)
			{
				for (k=i;k<=j;++k)
				{
					temp[count]=buf[k];
					count++;
				}
			}
			i=j+1;
		}
		temp[count]='\0';
		sprintf(restr,"%s",temp+4);
		num--;
	}
	free(buf);
	free(temp);
	return 0;
}

int Adder::solve()
{

}

int Adder::replyans(char* restr,int num)
{

}

