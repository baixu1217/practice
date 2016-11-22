#include<iostream>
using namespace std;
#include<string.h>

template<typename T>
T Max(const T left,const T right)
{
	return (left > right) ? left:right;
}

template<>
char* Max<char*>(char* const str1,char* const str2)
{
	if(strcmp(str1,str2) == 0 || strcmp(str1,str2) == 1)
	{
		return str1;
	}
	else
	{
		return str2;
	}
}
int main()
{
	char* str1 = "hello";
	char* str2 = "world";
	cout<<Max<char*>(str1,str2)<<endl;
	return 0;
}