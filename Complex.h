#pragma once
#include<iostream>
using namespace std;

class Complex
{
public:
	Complex()
	{}

	Complex(double real,double image)
		:_real(real)
		,_image(image)
	{}

	Complex(const Complex& com)
		:_real(com._real)
		,_image(com._image)
	{}

	Complex operator=(Complex& com)
	{
		_real = com._real;
		_image = com._image;
		return *this;
	}

	Complex operator+(Complex& com)
	{
		_real += com._real;
		_image += com._image;
		return *this;
	}
	Complex operator-(Complex& com)
	{
		_real -= com._real;
		_image -= com._image;
		return *this;
	}
	Complex operator*(Complex& com)
	{
		_real = _real*com._real+_image*com._image;
		_image = _real*com._image+_image*com._real;
		return *this;
	}
	Complex operator/(Complex& com)
	{
		_real = (_real*com._real-_image*com._image)/(com._real*_real+_image*com._image);
		_image = (_image*com._real-_real*com._image)/(com._real*_real+_image*com._image);
		return *this;
	}

	~Complex()
	{
		cout<<"~Complex()"<<endl;
	}
public:
	double GetReal()
	{
		return _real;
	}
	double GetImage()
	{
		return _image;
	}
private:
	double _real;
	double _image;
};
