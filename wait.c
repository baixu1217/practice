#include<stdio.h>
#include<sys/types.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	pid_t id = fork();
	if(id < 0)
	{
		printf("%s fork error!\n",__FUNCTION__);
		return 1;
	}
	else if(id == 0)
	{
		printf("child is run! pid:%d\n",getpid());
		sleep(5);
		exit(127);
	}
	else
	{
		int status = 0;
		pid_t ret = waitpid(-1,&status,0);
		printf("this is test for wait!\n");
		if(WIFEXITED(status))
		{
			printf("wait success! exitcode:%d \n",WEXITSTATUS(status));
		}
		else
		{
			printf("wait failed!\n");
			return 1;
		}
	}
	return 0;
}
