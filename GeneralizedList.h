#pragma once 
#include<iostream>
using namespace std;
#include<assert.h>

enum Type
{
	HEAD,
	VALUE,
	SUB,
};

struct GeneralizeListNode
{
	Type _type;
	GeneralizeListNode* _next;

	union
	{
		char _value;
		GeneralizeListNode* _sublink;
	};

	GeneralizeListNode(Type type,char value = 0)
		:_next(NULL)
		,_type(type)
		,_value(value)
	{
		if(type == VALUE)
		{
			_value = value;
		}
		if(type == SUB)
		{
			_sublink = NULL;
		}
	}
};

class GeneralizeList
{
	typedef GeneralizeListNode Node;
public:
	GeneralizeList()
		:_head(NULL)
	{}
	//构造函数
	GeneralizeList(const char* str)
	{
		_head = Create(str);
	}
	//拷贝构造函数
	GeneralizeList(const GeneralizeList& g)
	{
		_head = _Copy(g._head);
	}
	//赋值运算符重载（1）
	//GeneralizeList& operator=(const GeneralizeList& g)
	//{
	//	if(this != &g)
	//	{
	//		Node* tmp = _Copy(g._head);
	//		delete _head;
	//		_head = tmp;
	//	}
	//	return *this;
	//}
	//赋值运算符重载（2）
	GeneralizeList& operator=(const GeneralizeList& g)
	{
		if(_head != g._head)
		{
			GeneralizeList tmp(g);
			swap(_head,tmp._head);
		}
		return *this;
	}

	~GeneralizeList()
	{
		if(_head)
		{
			_Destroy(_head);
			_head = NULL;
		}
	}

	void Print()
	{
		_Print(_head);
		cout<<endl;
	}

public:
	Node* Create(const char*& str)
	{
		assert(*str == '(');
		Node* head = new Node(HEAD);
		++str;
		Node* tail = head;
		while(*str)
		{
			if((*str >= '0' && *str <= '9')
				||(*str >= 'a' && *str <= 'z')
				||(*str >= 'A' && *str <= 'Z'))
			{
				tail->_next = new Node(VALUE,*str);
				tail = tail->_next;
				++str;
			}
			else if(*str == '(')
			{
				tail->_next = new Node(SUB);
				tail = tail->_next;
				tail->_sublink = Create(str);
				++str;
			}
			else if(*str == ')')
			{
				++str;
				return head;
			}
			else
			{
				++str;
			}
		}
		return head;
	}

	void _Print(Node* head)
	{
		assert(head);
		Node* cur = head;
		while(cur)
		{
			if(cur->_type == HEAD)
			{
				cout<<"(";
			}
			else if(cur->_type == VALUE)
			{
				cout<<cur->_value;
				if(cur->_next != NULL)
				{
					cout<<",";
				}
			}
			else if(cur->_type == SUB)
			{
				_Print(cur->_sublink);
				if(cur->_next != NULL)
				{
					cout<<",";
				}
			}
			else
			{
				assert(false);
			}
			cur = cur->_next;
		}
		cout<<")";
	}

	Node* _Copy(Node* head)
	{
		Node* cur = head;
		Node* newHead = new Node(HEAD);
		Node* newTail = newHead;
		while(cur)
		{
			if(cur->_type == HEAD)
			{
				cur = cur->_next;
			}
			else if(cur->_type == VALUE)
			{
				newTail->_next = new Node(VALUE,cur->_value);
				newTail = newTail->_next;
				cur = cur->_next;
			}
			else if(cur->_type == SUB)
			{
				newTail->_next = new Node(SUB);
				newTail = newTail->_next;
				newTail->_sublink = _Copy(cur->_sublink);
				cur = cur->_next;
			}
			else
			{
				assert(false);
			}
		}
		return newHead;
	}

	void _Destroy(Node* head)
	{
		Node* cur = head;
		while(cur)
		{
			if(cur->_type == HEAD || cur->_type == VALUE)
			{
				Node* del = cur;
				cur = cur->_next;
				delete del;
			}
			else if(cur->_type == SUB)
			{
				Node* del = cur;
				cur = cur->_next;
				_Destroy(del->_sublink);
				delete del;
			}
			else
			{
				assert(false);
			}
		}
	}

	size_t Size()
	{
		return _Size(_head);
	}

	size_t _Size(Node* head)
	{
		assert(head);
		size_t count = 0;
		Node* cur = head;
		while(cur)
		{
			if(cur->_type == VALUE)
			{
				++count;
			}
			else if(cur->_type == SUB)
			{
				count += _Size(cur->_sublink);
			}
			cur = cur->_next;
		}
		return count;
	}

	size_t Depth()
	{
		return _Depth(_head);
	}

	size_t _Depth(Node* head)
	{
		Node* cur = head;
		size_t MaxDepth = 1;
		while(cur)
		{
			if(cur->_type == SUB)
			{
				size_t Depth = _Depth(cur->_sublink);
				if(Depth+1 > MaxDepth)
				{
					MaxDepth = Depth+1;
				}
			}
			cur = cur->_next;
		}
		return MaxDepth;
	}
protected:
	Node* _head;
};


void FunTest()
{
	char* str = "(a,b,(c,d),(e,(f),g))";
	GeneralizeList g1(str);
	g1.Print();
	GeneralizeList g2(g1);
	g2.Print();
	GeneralizeList g3;
	g3 = g1;
	g3.Print();
	cout<<g3.Size()<<endl;
	cout<<g3.Depth()<<endl;
}