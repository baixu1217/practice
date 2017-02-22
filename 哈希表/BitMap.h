#pragma once
#include<iostream>
using namespace std;
#include<vector>

//位图的每一位的0,1标志这个数存在或不存在的状态
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
	//将这个数存在的状态置为1
	void Set(const size_t& value)
	{
		size_t index = value>>5;
		size_t bit = value % 32;
		
		_array[index] |= (1<<bit);
	}
	//将这个数不存在的状态置为0
	void Reset(const size_t& value)
	{
		size_t index = value>>5;
		size_t bit = value % 32;

		_array[index] &= (~(1<<bit));
	}
	//测试某个数是否出现过
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
	BitMap bm(size_t(-1));   //64位系统下表示的整数的最大值
	bm.Set(10);
	bm.Set(100);
	bm.Set(20);
	bm.Set(500);
	cout<<bm.Test(10)<<endl;
	cout<<bm.Test(200)<<endl;
	cout<<bm.Test(500)<<endl;
	cout<<bm.Test(40)<<endl;
}