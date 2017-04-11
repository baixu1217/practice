#include<iostream>
using namespace std;
#include"StackOrder.h"

int main()
{
	int arr1[] = {1,2,3,4,5};   //入栈序列
	int arr2[] = {4,5,3,1,2};   //出栈序列
	int arr3[] = {5,4,3,2,1};
	int arr4[] = {1,3,2,5,4};

	size_t size1 = sizeof(arr1)/sizeof(arr1[0]);
	size_t size2 = sizeof(arr2)/sizeof(arr2[0]);
	size_t size3 = sizeof(arr3)/sizeof(arr3[0]);
	size_t size4 = sizeof(arr4)/sizeof(arr4[0]);

	StackOrder<int> s(arr1,arr2,size1,size2);
	cout<<s.CheckOrder()<<endl;
	StackOrder<int> s1(arr1,arr4,size1,size4);
	cout<<s1.CheckOrder()<<endl;

	StackOrder<int> s3(arr1,arr3,size1,size3);
	cout<<s3.CheckOrder()<<endl;

	 char* arra = "abcdef";   //入栈序列
    char* str2 = "bafdce";    //出栈序列
    //char* str2 = "baefdc";  //出栈序列
    StackOrder<char> s2(arra,str2, 6, 6);
	cout << s2.CheckOrder() << endl;
    return 0;
}