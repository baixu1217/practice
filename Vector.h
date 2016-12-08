#pragma once
#include"List.h"
#include"TypeTraits.h"
template<typename T>
class Vector
{
public:
	typedef T* Iterator;
	typedef const T* ConstIterator;
public:
	Vector()
		:_start(0)
		,_finish(0)
		,_EndOfStorge(0)
	{}

	Vector(Vector<T>& v)
		:_start(new T[v.Size()])
	{
		Copy<T>(_start,v._start,v.Size());
		_finish = _start+v.Size();
		_EndOfStorge = _finish;
	}

	Vector<T>& operator=( Vector<T>& v)
	{
		if(this != &v)
		{
			size_t _size = Size();
			size_t _Capacity = v._EndOfStorge - v._start;
			Iterator tmp = new T[v.Size()];
			Copy<T>(tmp,v._start,v.Size());
			delete _start;
			_start = tmp;
			_finish = _start + v.Size();
			_EndOfStorge = _start + _Capacity;
		}
		return *this;
	}

public:
	Iterator Begin()
	{
		return _start;
	}

	Iterator End()
	{
		return _finish;
	}
	Iterator rBegin()
	{
		return _finish;
	}

	Iterator rEnd()
	{
		return _start;
	}

	ConstIterator Begin() const
	{
		return _start;
	}

	ConstIterator End() const
	{
		return _finish;
	}


	void CheckCapacity()
	{
		if(_start == _finish)
		{
			size_t _size = Size();
			size_t NewCapacity = Capacity()*2+3;
			T* tmp = new T[NewCapacity];
			if(_start)
			{
				Copy<T>(tmp,_start,Size());
				delete _start;
			}
			_start = tmp;
			_finish = _start+_size;
			_EndOfStorge = _start + NewCapacity;
		}
	}

	T& operator[](size_t n)
	{
		return *(_start+n);
	}

	const T& operator[](size_t n) const
	{
		assert(n < Size());
		return *(_start+n);
	}
public:
	void PushBack(const T& data)
	{
		CheckCapacity();
		*_finish = data;
		++_finish;
	}

	void PopBack()
	{
		assert(_start);
		--_finish;
	}

	Iterator Insert(Iterator pos,const T& data)
	{
		CheckCapacity();
		for(Iterator i = _finish; i > pos; --i)
		{
			*i = *(i-1);
		}
		*(pos) = data;
		++_finish;
		return _start;
	}

	Iterator Erase(Iterator pos)
	{
		assert(_start);
		for(Iterator i = pos; i < _finish; ++i)
		{
			*i = *(i+1);
		}
		--_finish;
		return _start;
	}
	void Resize(size_t _size,const T& data)
	{
		size_t size = Size();
		if(size < _size)
		{
			Iterator tmp = new T[_size];
			Copy<T>(tmp,_start,size);
			
			_start = tmp;
			for(size_t i = size; i < _size; ++i)
			{
				*(_start+i) = data;
			}
			_finish = _start+_size;
		}
		else
		{
			_finish = _start+_size;
		}
	}
	size_t Size()
	{
		return _finish - _start;
	}

	bool Empty()
	{
		return _start == _finish;
	}

	size_t MaxSize()
	{
		return size_t(-1)/sizeof(T);
	}

	size_t Capacity()
	{
		return _EndOfStorge-_start;
	}

	T& Front()
	{
		return *_start;
	}
	const T& Front() const
	{
		return *_start;
	}

	T& Back()
	{
		return *_finish;
	}
	const T& Back() const
	{
		return *_finish;
	}

	void Swap(Vector<T>& v)
	{
		swap(_start,v._start);
		swap(_finish,v._finish);
		swap(_EndOfStorge,v._EndOfStorge);
	}

protected:
	Iterator _start;
	Iterator _finish;
	Iterator _EndOfStorge;
};

void PrintList(Vector<int>& l)
{
	Vector<int>::Iterator it = l.Begin();
	while(it != l.End())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
}

void rPrintList(Vector<int>& l)
{
	Vector<int>::Iterator it = l.rBegin();
	while(it != l.rEnd())
	{
		--it;
		cout<<*it<<" ";
		
	}
	cout<<endl;
}