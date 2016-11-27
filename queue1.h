#pragma once
#include<iostream>
using namespace std;

template<typename T>
struct QueueNode
{
	T _data;
	struct QueueNode<T> *_next;

	QueueNode(const T& data)
		:_data(data)
		,_next(NULL)
	{}
};

template<typename T>
class Queue
{
	typedef QueueNode<T> Node;
public:
	Queue()
		:_head(NULL)
		,_tail(NULL)
	{}

	~Queue()
	{
		if(_head)
		{
			delete _head;
			_head = _tail = NULL;
		}
	}
public:
	void Push(const T& data)
	{
		if(_head == NULL)
		{
			_head = _tail = new Node(data);
			return;
		}
		_tail->_next = new Node(data);
		_tail = _tail->_next;
	}
	void Pop()
	{
		if(_head == _tail)
		{
			delete _head;
			_head = _tail = NULL;
			return;
		}
		Node* del = _head;
		_head = _head->_next;
		delete del;
	}
	T& Front()
	{
		return _head->_data;
	}
	T& Back()
	{
		return _tail->_data;
	}

	T& Size()
	{
		Node* cur = _head;
		int count = 0;
		while(cur)
		{
			++count;
			cur = cur->_next;
		}
		return count;
	}

	bool Empty()
	{
		return _head == NULL;
	}

protected:
	Node *_head;
	Node *_tail;
};