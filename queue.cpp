#define _CRT_SECURE_NO_WARNINGS 
#include"queue.h"

int main()
{
	Queue<int> queue;
	queue.PushBack(1);
	queue.PushBack(2);
	queue.PushBack(3);
	queue.PushBack(4);
	cout<<queue.Front()<<endl;
	cout<<queue.Back()<<endl;
	cout<<queue.Size()<<endl;
	queue.PopFront();
	cout<<queue.Front()<<endl;
	queue.PopFront();
	queue.PopFront();
	queue.PopFront();
	cout<<queue.Size()<<endl;
	cout<<queue.Empty()<<endl;
	getchar();
	return 0;
}
