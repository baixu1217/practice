#pragma once
#include<stack>
#include<iostream>
using namespace std;
template<class T>
class StackOrder
{
public:
	StackOrder( T* arr, T* outarr,size_t arrSize,size_t outarrSize)
		:_array(new T(arrSize))
		,_outArray(new T(outarrSize))
		,_arraySize(arrSize)
		,_outArraySize(outarrSize)
	{
		for(int i = 0; i < arrSize; ++i)
		{
			_array[i] = arr[i];
		}
		for(int i = 0; i < outarrSize; ++i)
		{
			_outArray[i] = outarr[i];
		}
	}

public:
	void Push(const T& data)
	{
		st.push(data);
	}

	void Pop()
	{
		st.pop();
	}

	bool CheckOrder()
	{
		int i = 0;
		int j = 0;
		
		while(!st.empty() || i < _arraySize)
		{
			if(st.empty() && i < _arraySize)
				st.push(_array[i++]);
			while(_outArray[j] != st.top())
			{
				if(i >= _arraySize)
					return false;
				st.push(_array[i++]);
			}
			st.pop();
			j++;
		}
		return true;
	}
private:
	stack<T> st;
	T* _array;
	size_t _arraySize;
	T* _outArray;
	size_t _outArraySize;
};