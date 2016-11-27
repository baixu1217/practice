#pragma once
#include<iostream>
using namespace std;
#include<assert.h>
struct _TrueType
{
	bool Get()
	{
		return true;
	}
};
struct _FalseType
{
	bool Get()
	{
		return false;
	}
};

template<typename T>
class _TypeTraits
{
public:
	typedef _FalseType _PodType;
};

template<>
class _TypeTraits <int>
{
public:
	typedef _TrueType _PodType;
};

template<>
class _TypeTraits <short>
{
public:
	typedef _TrueType _PodType;
};

template<>
class _TypeTraits <char>
{
public:
	typedef _TrueType _PodType;
};

template<>
class _TypeTraits <long>
{
public:
	typedef _TrueType _PodType;
};

template<typename T>
void Copy(T* dst,T *src,size_t Size)
{
	if(_TypeTraits<T>::_PodType().Get())
	{
		memcpy(dst,src,sizeof(T)*Size);
	}
	else
	{
		for(size_t i = 0; i < Size; ++i)
		{
			dst[i] = src[i];
		}
	}
}


template<typename T>
class Stack
{
public:
	Stack()
		:_a(NULL)
		,_size(0)
		,_capacity(0)
	{}
	~Stack()
	{
		if (_a)
		{
			delete[] _a;
			_a = NULL;
			_size = _capacity = 0;
		}
	}
public:
	void Push(const T& data)
	{
		_CheckCapacity();
		_a[_size++] = data;
	}

	void Pop()
	{
		assert(_size);
		_size--;
	}

	T& Top()
	{
		assert(_size);
		return _a[_size-1];
	}

	T& Size()
	{
		return _size;
	}

	bool Empty()
	{
		return _size==0;
	}
public:
	void _CheckCapacity()
	{
		if(_size >= _capacity)
		{
			size_t newCapacity = _capacity*2+3;
			T* tmp = new T[newCapacity];
			if(_a)
			{
				Copy<T>(tmp,_a,_size);
				delete[] _a;
				_a = NULL;
			}

			_a = tmp;
			_capacity = newCapacity;
		}
	}
protected:
	T* _a;
	size_t _size;
	size_t _capacity;
};