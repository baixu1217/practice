#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"
#include<vector>
int main()
{
	List<int> l;
	List<int> l1;
	const List<int> l3;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	l.PopBack();
	PrintList(l);
	l.PushFront(0);
	PrintList(l);
	l.PopFront();
	l.Insert(l.End(),4);
	l.Insert(l.Begin(),0);
	PrintList(l);
	cout<<"Front:"<<l.Front()<<endl;
	cout<<"Back:"<<l.Back()<<endl;
	cout<<"Empty:"<<l.Empty()<<endl;
	l1.Swap(l);
	PrintList(l1);
	PrintList(l);
	l.PushBack(10);
	l.PushBack(11);
	l.PushBack(12);
	l1.Insert(l1.Begin(),l.Begin(),l.End());
	PrintList(l1);
	vector<int> v;
	v.push_back(55);
	v.push_back(66);
	l1.Insert(l1.Begin(),v.begin(),v.end());
	PrintList(l1);
	char str[] = {'a','b'};
	l1.Insert(l1.Begin(),str,str+2);
	PrintList(l1);

	return 0;
}