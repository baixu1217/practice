#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<assert.h>

template<class T>
class DoubleStack
{
public:
	DoubleStack()
		:array(NULL)
		,_capacity(0)
		,top1(0)
		,top2(0)
	{}

	void Push1(const T& data)
	{
		CheckCapacity();
		array[top1++] = data;
	}

	void Push2(const T& data)
	{
		CheckCapacity();
		array[top2--] = data;
	}

	void Pop1()
	{
		assert(top1 > 0);
		top1--;
	}
	void Pop2()
	{
		assert(top2 < _capacity-1);
		top2++;
	}
	size_t Size1()
	{
		return top1;
	}

	size_t Size2()
	{
		return _capacity-1-top2;
	}

	bool IsEmpty1()
	{
		return top1 == 0;
	}

	bool IsEmpty2()
	{
		return top2 == _capacity-1;
	}

	T Top1()
	{
		return array[top1-1];
	}

	T Top2()
	{
		return array[top2+1];
	}

	void CheckCapacity()
	{
		if(top1 == top2)
		{
			size_t newCapacity = _capacity*2+3;
			
			if(array)
			{
				T* tmp = new T[newCapacity];
				for(int i = 0; i < top1;i++)
				{
					tmp[i] = array[i];
				}
				size_t newC = newCapacity;
				for(int i = _capacity-1; i >= top2;i--)
				{
					tmp[newC--] = array[i];
				}
				_capacity = newCapacity;
				top2 = _capacity-1;
				swap(tmp,array);
				delete tmp;
				tmp = NULL;
			}
			else
			{
				array = new T[newCapacity];
				_capacity = newCapacity;
				top2 = _capacity-1;
			}
			
		}
	}

	//~DoubleStack()
	//{
	//	if(array != NULL)
	//	{
	//		delete[] array;
	//		array = NULL;
	//		top1 = 0;
	//		top2 = 0;
	//		_capacity = 0;
	//	}
	//}
private:
	T* array;
	size_t top1;
	size_t top2;
	size_t _capacity;
};


int main()
{
	DoubleStack<int> s;
	s.Push1(1);
	s.Push1(2);
	s.Push1(3);
	s.Push1(4);
	s.Push2(5);
	s.Push2(6);
	s.Push2(7);
	s.Push2(8);

	cout<<s.Size1()<<endl;
	cout<<s.Size2()<<endl;

	while(!s.IsEmpty1())
	{
		cout<<s.Top1()<<" ";
		s.Pop1();
	}


	while(!s.IsEmpty2())
	{
		cout<<s.Top2()<<" ";
		s.Pop2();
	}

    return 0;
}