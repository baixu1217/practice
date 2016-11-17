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
	}

	AutoPtr(AutoPtr& ap)
		:_p(ap._p)
	{
		cout<<"AutoPtr(AutoPtr& ap)"<<endl;
		ap._p = NULL;
	}
	AutoPtr<T>& operator=(AutoPtr& ap)
	{
		cout<<"AutoPtr<T>& operator=(AutoPtr& ap)"<<endl;
		if(this != &ap)
		{
			delete _p;
			_a = ap._p;
			ap._p = NULL;
		}
	}
	~AutoPtr()
	{
		cout<<"~AutoPtr()"<<endl;
		if (_p)
		{
			delete _p;
			_p = NULL;
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