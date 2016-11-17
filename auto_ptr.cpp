#include<iostream>
using namespace std;

template<typename T>
class AutoPtr
{
public:
	AutoPtr(T* p)
		:_p(new T(1))
	{
		cout<<"AutoPtr()"<<endl;
		_p = p;
		_owner = true;
	}

	AutoPtr(AutoPtr& ap)
		:_p(ap._p)
	{
		cout<<"AutoPtr(AutoPtr& ap)"<<endl;
		ap._owner = false;
		ap._p = NULL;
		_owner = true;
	}
	AutoPtr<T>& operator=(AutoPtr& ap)
	{
		cout<<"AutoPtr<T>& operator=(AutoPtr& ap)"<<endl;
		if(this != &ap)
		{
			delete _p;
			_a = ap._p;
			ap._owner = false;
			ap._p = NULL;
			_owner = true;
		}
	}
	~AutoPtr()
	{
		cout<<"~AutoPtr()"<<endl;
		if (_p)
		{
			delete _p;
			_p = NULL;
			_owner = false;
		}
	}
public:
	T& operator*()
	{
		return *_p;
	}
	T* operator->()
	{
		return _p;
	}
private:
	T *_p;
	bool _owner;
};


void FunTest()
{
	AutoPtr<int> ap = new int;
	AutoPtr<int> ap1(ap);
	*ap1 =  10;
	*(ap1.operator->()) = 20;
 }

int main()
{
	FunTest();
	return 0;
}