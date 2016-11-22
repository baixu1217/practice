#include<iostream>
using namespace std;

template<typename T>
T Add(const T& left,const T& right)
{
	return left+right;
}

template<>
int Add<int>(const int& left,const int& right)
{
	return left+right;
}

int main()
{
	cout<<Add('1','2')<<endl;
	cout<<Add(1.1f,2.2f)<<endl;
	return 0;
}