#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	int a,b;
	srand(time(NULL));
	int i;
	FILE* fp=fopen("task.txt","wt+");
	for (i=0;i<100000;++i)
	{
		a=rand() % 100;
		b=rand() % 100;
		fprintf(fp,"%d %d\n",a,b);
	};
	fclose(fp);
	return 0;
}
		