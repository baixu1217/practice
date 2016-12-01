//插入排序实现优先级队列
#pragma once
#include<iostream>
using namespace std;
#include<queue>
#include<assert.h>

template<typename T>
T QueuePriority(T *arr1,size_t size)
{
	assert(arr1);
	queue<T> q;
	T arr2[7] = {0};
	arr2[0] = arr1[0];
	for(size_t i = 1; i < size; ++i)
	{
		if(arr2[i-1] <= arr1[i])
		{
			arr2[i] = arr1[i];
		}
		else
		{
			size_t j = 0;
			for(j = i-1; j >= 0; --j)
			{
				if(arr2[j] > arr1[i])
				{
					arr2[j+1] = arr2[j];
				}
				else
				{
					break;
				}
			}
			arr2[j+1] = arr1[i];
		}
	}

	for(int k = size-1; k >= 0; k--)
	{
		q.push(arr2[k]);
	}

	return q.front();
}

void FunTest()
{
	int arr1[] = {1,3,5,4,2,6,0};
	char arr2[] = {'a','d','b','c'};
	size_t size = sizeof(arr1)/sizeof(arr1[0]);
	size_t size1 = sizeof(arr2)/sizeof(arr2[0]);

	cout<<QueuePriority<int>(arr1,size)<<endl;
	cout<<QueuePriority<char>(arr2,size1)<<endl;
}

int main()
{
	FunTest();
	return 0;
}