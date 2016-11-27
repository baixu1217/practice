#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include"stack1.h"

int main()
{
	Stack<int> s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);

	while(!s.Empty())
	{
		cout<<s.Top()<<endl;
		s.Pop();
	}
	cout<<endl;
	getchar();
	return 0;
}