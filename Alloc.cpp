//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//#include"MyAlloc.h"
//int main()
//{
//	MyAlloc::MallocAllocTemplate<0> ma;
//	int *tmp = (int*)ma.Allocate(22);
//	
//	int *m = (int*)ma.Reallocate(tmp,22,40);
//	ma.Deallocate(tmp,10);
//    return 0;
//}

#include<iostream>
using namespace std;
#include <algorithm>

int main()
{
	int n;     //ÐòÁÐ³¤¶È
	int arr[50];
	int count = 1;
	int tmp[50];
	cin>>n;
	if(n >= 1 && n <= 50)
	{
		for(int i = 0; i < n; i++)
		{
			cin>>arr[i];
			if(arr[i] < 1 || arr[i] > 1000)
				return 0;
		}
		
		int l = 0;
		int *p = NULL;
		for(int i = 0; i < n; i++)
		{
			p = find(arr+i+1,arr+n-i,arr[i]);
			if(p)
			{
				tmp[l++] = arr[i];
			}
		}
		/*int k = 0,j = 0;
		for( k = 0; k < n-1; k++)
		{
			if(arr[k] != arr[k+1])
			{
				tmp[j++] = arr[k];
			}
		}
		tmp[j] = arr[k];*/
		for(int m = 0; m < count; m++)
		{
			cout<<tmp[m];
			if(m != count-1)
				cout<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}