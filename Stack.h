#pragma once
#include<iostream>
using namespace std;
#include<vector>

template<typename T>
class Stack
{
public:
	Stack()
	{
		cout<<"Stack()"<<endl;
	}
	~Stack()
	{
		if(!Empty())
		{
			s.~vector();
		}
	}
public:
	void Push(const T& data)
	{
		s.push_back(data);
	}

	void Pop()
	{
		s.pop_back();
	}

	size_t Size()
	{
		return s.size();
	}

	bool Empty()
	{
		return s.empty();
	}

	T& Top()
	{
		return s.back();
	}

	const T& Top() const
	{
		return s.back();
	}
private:
	vector<T> s;
};