//用选择排序实现优先级队列
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

	for(size_t i = 0; i < size; ++i)
	{
		T max = i;	
		for(size_t j = i+1;j < size; ++j)
		{
			if(arr1[max] < arr1[j])
			{
				max = j;
			}
		}
		swap(arr1[max],arr1[i]);
		q.push(arr1[i]);
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