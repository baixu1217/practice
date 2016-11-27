#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

#include<queue>
int main()
{
	queue<int> q;
	queue<int> q1;

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	cout<<q.back()<<endl;
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q1.push(q.front());
		q.pop();
	}
	q1.swap(q);
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();
	}
	getchar();
	return 0;
}