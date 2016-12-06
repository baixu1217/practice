#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include"Singleton.h"

int main()
{

	Singleton* s = Singleton::Instance();
	Singleton* s1 = Singleton::Instance();//创建不出来

	return 0;
}