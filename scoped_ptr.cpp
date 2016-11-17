#include<iostream>
using namespace std;

template<typename T>
class ScopedPtr
{
public:
	ScopedPtr(const T* p)
		:_p(p)
	{}
	~ScopedPtr()
	{
		if(_p)
		{
			delete _p;
			_p = NULL;
		}
	}
	T& operator*()
	{
		return *_p;
	}
	T* operator->()
	{
		return _p;
	}
private:
	ScopedPtr(const ScopedPtr&);
	ScopedPtr<T>& operator=(const ScopedPtr&);
private:
	T* _p;
};

void FunTest()
{
	ScopedPtr<int> sp = new int;
	ScopedPtr<int> sp1(sp);   //error,无法拷贝
	ScopedPtr<int> sp1 = sp;   //error，无法赋值

}

int main()
{
	FunTest();
	return 0;
}