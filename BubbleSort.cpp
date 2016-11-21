#include<iostream>
using namespace std;
template<typename T>
class Greater
{
public:
	bool operator()(const T&left,const T& right)
	{
		return left>right;
	}
};
template<typename T>
class Less
{
public:
	bool operator()(const T&left,const T& right)
	{
		return left<right;
	}
};

template<typename T,typename Fun>
void BubbleSort(T arr[],size_t size)
{
	for(size_t i = 0; i < size-1; i++)
	{
		for(size_t j = 0; j < size-i-1;++j)
		{
			if(Fun()(arr[j],arr[j+1]))
			{
				T tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}

}
void FunTest()
{
	int arr[] = {2,5,4,1,6,9,8,7};
	BubbleSort<int,Greater<int>>(arr,sizeof(arr)/sizeof(arr[0]));
	BubbleSort<int,Less<int>>(arr,sizeof(arr)/sizeof(arr[0]));
}
int main()
{
	FunTest();
	return 0;
}