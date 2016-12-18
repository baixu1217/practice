#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#define ParityTransposition(x) ((x & (0x55555555))<<1)|((x & (0xAAAAAAAA))>>1)

int main()
{
	int num = 0;
	printf("Please enter an integer;\n");
	scanf("%d",&num);
	num = ParityTransposition(num);
	printf("After transformation the number is:\n%d",num);
	printf("\n");
	
	system("pause");
	return 0;
}

//Write a macro to exchange a number of odd bits and even bits.