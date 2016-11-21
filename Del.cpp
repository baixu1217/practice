#include<iostream>
using namespace std;
#include<boost/shared_ptr.hpp>

//关闭文件(close file)
struct FClose
{
	void operator()(FILE *file)
	{
		fclose(file);
		cout<<"fclose()"<<endl;
	}
};

void FunTest()
{
	FILE* file = fopen("1.txt","w");
	shared_ptr<FILE> sp(file,FClose());
}

//释放空间(free space)
struct Free
{
       void operator()(void *ptr)
       {
              free(ptr);
			  cout<<"free()"<<endl;
       }
};
void FunTest()
{
	int *p = (int *)malloc(sizeof(int));
    shared_ptr<int> sp(p,Free());      
}