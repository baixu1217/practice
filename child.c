#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>

void myhandler(int sig)
{
	printf("my sig is %d\n",sig);
}

int main()
{
	signal(SIGCHLD,myhandler);
	pid_t cid;
	if((cid = fork())== 0)//child
	{
		printf("i am child!pid:%d\n",getpid());
		sleep(5);
		exit(1);
	}
	else
	{

	  	struct sigaction act;	
	  	act.sa_handler = myhandler;
	  	sigemptyset(&act.sa_mask);
	  	act.sa_flags = 0;
	  	sigaction(SIGCHLD,&act,NULL);
	  	while(1)
	  	{
	  		printf("i am parent,my pid is %d\n",getpid());
	  		sleep(1);
	  	}
	
	}
//	else //father
//	{
//		while(id = waitpid(id,NULL,0) > 0)
//		{
//			printf("wait child success:%d       pid:%d\n",id,getpid());
//		}
//		printf("child is quit!%d\n",getpid());
//	}
	return 0;
}
