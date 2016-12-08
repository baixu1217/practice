#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include"Vector.h"

int main()
{
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	PrintList(v);
	rPrintList(v);
	v.PopBack();
	PrintList(v);
	v.Insert(v.Begin(),7);
	PrintList(v);
	v.Erase(v.End());
	PrintList(v);
	v.Resize(5,7);
	PrintList(v);
	cout<<v.MaxSize()<<endl;
	Vector<int> v1(v);
	PrintList(v1);
	Vector<int> v2;
	v2 = v1;
	PrintList(v2);

	return 0;
}