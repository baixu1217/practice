#include<iostream>
using namespace std;
//运用引用计数的方式
template<typename T>
class SharedPtr
{
public:
	SharedPtr(T* p = NULL)
		:_p(p)
		,_pCount(new int(1))
	{
		cout<<"SharedPtr(T* p = NULL)"<<endl;
	}
	SharedPtr(SharedPtr& sp)
		:_p(sp._p)
		,_pCount(sp._pCount)
	{
		cout<<"SharedPtr(SharedPtr& sp)"<<endl;
	}
	SharedPtr<T>& operator=(const SharedPtr& sp)
	{
		cout<<"SharedPtr<T>& operator=(const SharedPtr& sp)"<<endl;
		if(_p != sp._p)
		{
			if(_p == NULL)
			{
				_p = sp._p;
				_pCount = sp._pCount;
			}
			else if(_p && (*_pCount== 1))
			{
				delete _p;
				_p = sp._p;
				_pCount = sp._p;
			}
			else
			{
				--(*_pCount);
				_p = sp._p;
				_pCount = sp._pCount;
			}
			if(sp._p)
				++(*_pCount);
		}
		
		return *this;
	}
	~SharedPtr()
	{
		cout<<"~SharedPtr()"<<endl;
		if(_p && --(*_pCount) == 0)
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

	int UseCount()
	{
		if(_pCount != NULL)
			return *_pCount;
		return 0;
	}

private:
	T *_p;
	int *_pCount;
};

void FunTest()
{
	SharedPtr<int> sp(new int(1));
	SharedPtr<int> sp1(sp);
	SharedPtr<int> sp2;
	sp = sp1;
	sp2 = sp1;
	cout<<sp.UseCount()<<endl;
	cout<<sp1.UseCount()<<endl;
	cout<<sp2.UseCount()<<endl;
}

int main()
{
	FunTest();
	return 0;
}
