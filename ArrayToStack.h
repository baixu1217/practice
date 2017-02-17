#pragma once
#include<iostream>
using namespace std;
//用一个数组实现两个栈
template<class T>
class Stack
{
public:
	Stack()
		:_a(NULL)
		,_top1(0)
		,_top2(0)
		,_capacity(0)
	{}
	~Stack()
	{
		if(_a)
		{
			delete[] _a;
		}
	}
public:
	void _Capacity()
	{
		if(_a == NULL)
		{
			_capacity += 3;
			_a = new T[_capacity];
			_top2 = _capacity-1;
		}
		if(_top1 == _top2)
		{
			size_t OldCapacity = _capacity;
			_capacity *= 2;
			T* tmp = new T[_capacity];
			for(size_t i = 0; i < _top1; ++i)     //i++和++i
			{
				tmp[i] = _a[i];
			}
			for(size_t j = OldCapacity-1,i = _capacity-1;j > _top2;j--,i--)
			{
				tmp[i] = _a[j];
			}
			delete[] _a;
			_a = tmp;
			_top2 = (_capacity-1)-(OldCapacity-1-_top2);
		}
	}
public:
	void Push1(const T& x)
	{
		_Capacity();
		_a[_top1++] = x;
	}
	void Push2(const T& x)
	{
		_Capacity();
		_a[_top2--] = x;
	}
	void Pop1()
	{
		if(_top1 > 0)
			--_top1;
	}
	void Pop2()
	{
		if(_top2 < _capacity-1)
			++_top2;
	}

	T& Top1()
	{
		if(_top1 > 0)
			return _a[_top1-1];
	}
	T& Top2()
	{
		if(_top2 < _capacity-1)
			return _a[_top2+1];
	}

	bool Empty1()
	{
		return _top1 == 0;
	}
	bool Empty2()
	{
		return _top2 == _capacity-1;
	}
	size_t Size1()
	{
		return _top1;
	}
	size_t Size2()
	{
		return _capacity-1-_top2;
	}
private:
	T* _a;
	size_t _top1;
	size_t _top2;
	size_t _capacity;
};


void StackTest()
{
	Stack<int> s1;
	s1.Push1(1);
	s1.Push1(2);
	s1.Push1(3);
	s1.Push1(4);
	cout<<"s1的size："<<s1.Size1()<<endl;
	s1.Pop1();
	cout<<"s1的栈顶："<<s1.Top1()<<endl;
	while(!s1.Empty1())
	{
		cout<<s1.Top1()<<" ";
		s1.Pop1();	
	}
	cout<<endl;
	
	Stack<int> s2;
	s2.Push2(5);
	s2.Push2(6);
	s2.Push2(7);
	s2.Push2(8);
	cout<<endl;
	cout<<"s2的size："<<s2.Size2()<<endl;
	s2.Pop2();
	cout<<"s2的栈顶："<<s2.Top2()<<endl;
	while(!s2.Empty2())
	{
		cout<<s2.Top2()<<" ";
		s2.Pop2();	
	}
}