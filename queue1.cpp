#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include"queue1.h"

int main()
{
	Queue<int> q;
	Queue<int> q1;

	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	cout<<q.Back()<<endl;
	while(!q.Empty())
	{
		cout<<q.Front()<<" ";
		q1.Push(q.Front());
		q.Pop();
	}
	
	cout<<q.Size()<<endl;
	//(1)
	//while(!q1.Empty())
	//{
	//	cout<<q1.Front()<<" ";
	//	q1.Pop();
	//}
	//(2)
	swap(q,q1);
	while(!q.Empty())
	{
		cout<<q.Front()<<" ";
		q1.Push(q.Front());
		q.Pop();
	}
	cout<<endl;
	getchar();
	return 0;
}