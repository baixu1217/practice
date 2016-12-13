#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<stdarg.h>

int Sum(int val,...)
{
	va_list va;
	va_start(va,val);
	int sum = 0;
	for(size_t i = 0; i < val; ++i)
	{
		sum += va_arg(va,int);
	}
	va_end(va);
	return sum;
}

int main()
{
	cout<<Sum(2,3,4)<<endl;
    return 0;
}