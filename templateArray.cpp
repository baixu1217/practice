#include<iostream>
using namespace std;

template<typename T,int Size>
void FunTest(T (&arr)[Size])
{
	for(int i = 0; i < Size; i++)
	{
		arr[i] = 0;
	}
}

template<typename T,int Size>
void FunTest(T arr)
{
	for(int i = 0; i < Size; i++)
	{
		arr[i] = 0;
	}
}

int main()
{
	int arr[10];
	FunTest<int[10],10>(arr);
	return 0;
}