#define _CRT_SECURE_NO_WARNINGS 1
#include"Singleton.h"

Singleton* Singleton::_instance = 0;
Singleton::Singleton()
{
	cout<<"Singleton()"<<endl;
}

Singleton* Singleton::Instance()
{
	if(_instance == 0)
	{
		_instance = new Singleton();
	}
	return _instance;
}
