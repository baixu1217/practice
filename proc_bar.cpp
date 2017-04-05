#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>

int main()
{
	int i = 0;
	char bar[102] = {0};
	char flag[]={'|','/','-','\\'};
	while(i <= 100)
	{
		bar[i] = '#';
		printf("[%-100s][%d%%]  [%c]\r",bar,i,flag[i%4]);
		fflush(stdout);
		i++;
		Sleep(100);
	}
	printf("\n");
    return 0;
}