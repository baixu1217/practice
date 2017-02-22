#pragma once
#include<string>
#include<iostream>
using namespace std;
#include"BitMap.h"
#include"HashFunc.h"
struct _HashFunc1
{
	size_t operator()(const string& s)
	{
		return BKDRHash(s.c_str());
	}
};

struct _HashFunc2
{
	size_t operator()(const string& s)
	{
		return SDBMHash(s.c_str());
	}
};

struct _HashFunc3
{
	size_t operator()(const string& s)
	{
		return RSHash(s.c_str());
	}
};

struct _HashFunc4
{
	size_t operator()(const string& s)
	{
		return APHash(s.c_str());
	}
};

struct _HashFunc5
{
	size_t operator()(const string& s)
	{
		return JSHash(s.c_str());
	}
};


template<class K = string,
class HashFunc1 = _HashFunc1,
class HashFunc2 = _HashFunc2,
class HashFunc3 = _HashFunc3,
class HashFunc4 = _HashFunc4,
class HashFunc5 = _HashFunc5
>
class BloomFilter
{
public:
	BloomFilter(size_t Num)
		:_bm(Num*5*2)
		,_size(Num*2)
	{}

	void BloomSet(const K& key)
	{
		size_t Hash1 = HashFunc1()(key)%_size;
		size_t Hash2 = HashFunc2()(key)%_size;
		size_t Hash3 = HashFunc3()(key)%_size;
		size_t Hash4 = HashFunc4()(key)%_size;
		size_t Hash5 = HashFunc5()(key)%_size;

		_bm.Set(Hash1);
		_bm.Set(Hash2);
		_bm.Set(Hash3);
		_bm.Set(Hash4);
		_bm.Set(Hash5);
	}

	bool Test(const K& key)
	{
		size_t Hash1 = HashFunc1()(key)%_size;
		if(_bm.Test(Hash1) == false)
		{
			return false;
		}
		size_t Hash2 = HashFunc2()(key)%_size;
		if(_bm.Test(Hash2) == false)
		{
			return false;
		}
		size_t Hash3 = HashFunc3()(key)%_size;
		if(_bm.Test(Hash3) == false)
		{
			return false;
		}
		size_t Hash4 = HashFunc4()(key)%_size;
		if(_bm.Test(Hash4) == false)
		{
			return false;
		}
		size_t Hash5 = HashFunc5()(key)%_size;
		if(_bm.Test(Hash5) == false)
		{
			return false;
		}
		return true;
	}
private:
	BitMap _bm;
	size_t _size;
};

void BloomFilterTest()
{
	BloomFilter<> bm(1024);
	bm.BloomSet("11111");
	bm.BloomSet("11110");
	bm.BloomSet("11112");
	bm.BloomSet("11113");

	cout<<bm.Test("11111")<<endl;
	cout<<bm.Test("11101")<<endl;
	cout<<bm.Test("11102")<<endl;
	cout<<bm.Test("11113")<<endl;


}