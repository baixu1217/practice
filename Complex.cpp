#include"Date.h"

void Test()
{
	Complex com1(1.1,2.2);
	Complex com2(2.2,3.3);
	/*com1.operator=(com2);*/
	/*com1.operator+(com2);*/
	/*com1.operator-(com2);*/
	/*com1.operator*(com2);*/
	//com1.operator/(com2);
	com1 = com1/com2;
	cout<<com1.GetReal()<<"+"<<com1.GetImage()<<"i"<<endl;
}

int main()
{
	Test();
	system("pause");
	return 0;
}
