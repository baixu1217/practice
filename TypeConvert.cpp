#include<stdio.h>
#include<iostream>
using namespace std;

void FunTest()
{
	//强转
	int a = 10;
	double d = (double)a;
	printf("%lf %d\n",d,a);
	//两个相关类型的转换  (static_cast)
	int b = 10;
	double c = static_cast<double>(b);
	printf("%lf %d\n",c,a);
	//两个不相关类型的转换
	int q = 10;
	int *p = reinterpret_cast<int*>(&q);
	printf("%d %d\n",q,*p);
	//删除变量的const属性
	const int x = 3;
	int *r = const_cast<int*>(&x);
	*r = 30;
	printf("%d %d\n",x,*r);

}


////两个不相关类型的转换
typedef void (*Fun)();

int DoSomething(int i)
{
	printf("DoSomething()\n");
	return 0;
}

//dynamic_cast含有虚函数的类的转换
class A
{
public:
	virtual void test()
	{
		cout<<"virtual void test()"<<endl;
	}
};
class B:public A
{
	
};

void Test(A* pa)
{
	B* pb1 = static_cast<B*>(pa);
	B* pb2 = dynamic_cast<B*>(pa);
	cout<<"pb1: "<<pb1<<endl;
	cout<<"pb2: "<<pb2<<endl;

}

//explicit关键字阻止经过转换构造函数进行的隐式转换的发生

class C
{
public:
	explicit C(int a )
	{
		cout<<"C(int a)"<<endl;
	}
	C(const C& c)
	{
		cout<<"C(const C& c)"<<endl;
	}
private:
	int _a;
};

void test()
{
	C c(1);
//	C c1 = 2;

}

int main()
{
	A a;
	B b;
	Fun f = reinterpret_cast<Fun>(DoSomething);
	FunTest();
	f();
	Test(&a);
	Test(&b);
	test();
	return 0;
}