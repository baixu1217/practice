#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

int main()
{
	Stack<int> stack;
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);
	cout<<stack.Size()<<endl;
	cout<<stack.Top()<<endl;
	stack.Pop();
	stack.Pop();
	cout<<stack.Top()<<endl;
	stack.Pop();
	cout<<stack.Top()<<endl;
	stack.Pop();
	cout<<stack.Empty()<<endl;
	getchar();
	return 0;
}


