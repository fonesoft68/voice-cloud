

class ClientTask
{
public:
	int parseTaskList(int start,int end);
	virtual int fetchFile(char* buf)=0;
	virtual	int solve()=0;
	virtual	int replyans(char* restr,int num)=0;

};

class KWS:public ClientTask
{
public:
	int fetchFile(char* buf);
	int solve();
	int replyans(char* restr,int num);
};

class Adder:public ClientTask
{
public:
	int fetchFile(char* buf);
	int solve();
	int replyans(char* restr,int num);
};