#pragma once
#include<iostream>
using namespace std;

class Singleton
{
protected:
	Singleton();
public:
	static Singleton* Instance();
private:
	static Singleton*  _instance;
};
