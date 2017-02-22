#pragma once
#include<iostream>
using namespace std;
#include<vector>

//λͼ��ÿһλ��0,1��־��������ڻ򲻴��ڵ�״̬
class BitMap
{
public:
	BitMap(size_t Size = 1024)
	{
		_array.resize(Size/32+1);
	}

	~BitMap()
	{}

public:
	//����������ڵ�״̬��Ϊ1
	void Set(const size_t& value)
	{
		size_t index = value>>5;
		size_t bit = value % 32;
		
		_array[index] |= (1<<bit);
	}
	//������������ڵ�״̬��Ϊ0
	void Reset(const size_t& value)
	{
		size_t index = value>>5;
		size_t bit = value % 32;

		_array[index] &= (~(1<<bit));
	}
	//����ĳ�����Ƿ���ֹ�
	bool Test(const size_t& value)
	{
		size_t index = value>>5;
		size_t bit = value % 32;

		return (_array[index] & (1<<bit));
	}
private:
	vector<size_t> _array;
};


void BitMapTest()
{
	BitMap bm(size_t(-1));   //64λϵͳ�±�ʾ�����������ֵ
	bm.Set(10);
	bm.Set(100);
	bm.Set(20);
	bm.Set(500);
	cout<<bm.Test(10)<<endl;
	cout<<bm.Test(200)<<endl;
	cout<<bm.Test(500)<<endl;
	cout<<bm.Test(40)<<endl;
}