#pragma once
#include<iostream>
using namespace std;

void InsertSort(int *a,size_t size)
{
	for(size_t i = 1; i < size; ++i)
	{
		int end = i-1;
		int tmp = a[i];
		while(end >= 0)
		{
			if(tmp < a[end]) //ÉýÐò  //if(tmp > a[end]) //½µÐò
			{
				a[end+1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end+1] = tmp;
	}
}

void ShellSort(int* a,size_t size)
{
	int gap = size;
	int end = 0;
	int tmp = 0;
	while(gap > 1)
	{
		gap = gap/3+1;
		for(size_t i = gap; i < size; ++i)
		{
			end = i-gap;
			tmp = a[i];
			while(end >= 0)
			{
				if(tmp > a[end])  //½µÐò   //if(tmp < a[end]) ÉýÐò
				{
					a[end+gap] = a[end];
					end -= gap;
				}
				else
					break;
			}
			a[end+gap] = tmp;
		}
	}
}

void Display(int *a,size_t size)
{
	for(size_t i = 0; i < size; ++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void TestInsert()
{
	int a[] = {2,5,4,9,3,6,8,7,1,0};
	size_t size = sizeof(a)/sizeof(a[0]);
	InsertSort(a,size);
	Display(a,size);
	ShellSort(a,size);
	Display(a,size);
}