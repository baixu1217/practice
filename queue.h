#pragma once
#include<iostream>
using namespace std;
#include<list>

template<typename T>
class Queue
{
public:
	Queue()
	{
		cout<<"Queue()"<<endl;
	}
	~Queue()
	{
		if(!Empty())
		{
			l.~list();
		}
	}
public:
	T& Front ( )
	{
		return l.front();
	}
	const T& Front ( ) const
	{
		return l.front();
	}

	T& Back()
	{
		return l.back();
	}
	const T& Back() const
	{
		return l.back();
	}

	void PopFront()
	{
		return l.pop_front();
	}

	void PushBack(const T& data)
	{
		l.push_back(data);
	}

	size_t Size()
	{
		return l.size();
	}

	bool Empty()
	{
		return l.empty();
	}

private:
	list<T> l;
};