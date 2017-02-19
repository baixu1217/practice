#pragma once
#include<vector>
#include<iostream>
using namespace std;
#include<assert.h>
#include<string>

enum Status
{
	EXIST,
	DELETE,
	EMPTY
};

template<class K,class V>
struct HashTableNode
{
	K _key;
	V _value;
	Status _status;
	HashTableNode(const K& key = K(), const V& value = V())
		:_key(key)
		,_value(value)
		,_status(EMPTY)
	{}
};

template<class K>
struct __HashFunc
{
	size_t operator()(const K& key)
	{
		return key;
	}
};

template<>
struct __HashFunc<string>
{
	size_t BKDRHash(const char* str)
	{
		register size_t hash = 0;
		while(*str)
		{
			hash = hash*131 + *str;
			++str;
		}
		return hash;
	}
	size_t operator()(const string& str)
	{
		return BKDRHash(str.c_str());
	}
};
template<class K,class V,class _HashFunc = __HashFunc<K>>
class HashTable
{
	typedef HashTableNode<K,V> Node;
public:
	HashTable(size_t size)
		:_size(0)
	{
		assert(size > 0);
	//	_tables.resize(size);
		_tables.resize(GetPrime());
	
	}

	~HashTable()
	{}
	size_t HashFunc(const K& key)
	{
		_HashFunc hf;
		size_t va = hf(key);
		return va % _tables.size();
	}

	void Swap(HashTable<K,V,_HashFunc>& ht)
	{
		_tables.swap(ht._tables);
		swap(_size,ht._size);
	}

	void _CheckCapacity()
	{
		if(_tables.size() == 0 || _size*10 / _tables.size() >= 7)
		{
			size_t OldSize = _tables.size();
		//	size_t NewSize = _tables.size()*2+3;
			size_t NewSize = GetPrime();
			HashTable<K,V,_HashFunc> ht(NewSize);
			for(size_t i = 0; i < OldSize; i++)
			{
				if(_tables[i]._status == EXIST)
				{
					ht.Insert(_tables[i]._key,_tables[i]._value);
				}
			}
			this->Swap(ht);
		}
	}

	pair<Node*,bool> Insert(const K& key,const V& value)
	{
		_CheckCapacity();
		size_t index = HashFunc(key);
		//ÏßÐÔÌ½²â
		/*while(_tables[index]._status ==  EXIST )
		{
			if(_tables[index]._key == key)
				return make_pair((Node*)NULL,false);
			++index;

			if(index == _tables.size())
			{
				index = 0;
			}
		}
		*/
		//¶þ´ÎÌ½²â
		size_t i = 0;
		size_t first = index;
		while(_tables[index]._status ==  EXIST )
		{
			if(_tables[index]._key == key)
				return make_pair((Node*)NULL,false);
			++i;
			index = first + i*i;
			index %= _tables.size();
		}
		

		++_size;
		_tables[index]._key = key;
		_tables[index]._value = value;
		_tables[index]._status = EXIST;
		return make_pair(&_tables[index],true);
	}

	Node* Find(const K& key,const V& value)
	{
		size_t index = HashFunc(key);
		while(_tables[index]._status != EMPTY)
		{
			if(_tables[index]._key == key && _tables[index]._status == EXIST)
			{
				return &_tables[index];
			}
			else
			{
				++index;
				if(index == _tables.size())
				{
					index = 0;
				}

			}
		}
		return NULL;
	}

	bool Remove(const K& key,const V& value)
	{
		Node* tmp = Find(key,value);
		if(tmp)
		{
			tmp->_status = DELETE;
			return true;
		}
		return false;
	}
	size_t GetPrime()
	{
		// Ê¹ÓÃËØÊý±í¶ÔÆë×ö¹þÏ£±íµÄÈÝÁ¿£¬½µµÍ¹þÏ£³åÍ»
		const int _PrimeSize = 28;
		static const unsigned long _PrimeList[_PrimeSize] =
		{
			53ul, 97ul, 193ul, 389ul, 769ul,
			1543ul, 3079ul, 6151ul, 12289ul, 
			24593ul,49157ul, 98317ul, 196613ul, 
			393241ul,786433ul,1572869ul, 3145739ul,
			6291469ul, 12582917ul,25165843ul,50331653ul, 
			100663319ul, 201326611ul, 402653189ul,
			805306457ul,1610612741ul, 3221225473ul, 4294967291ul
		};
		for(size_t i = 0; i < _PrimeSize; i++)
		{
			if(_tables.size() < _PrimeList[i])
				return _PrimeList[i];
		}
		return 0;
	}
private:
	vector<Node> _tables;
	size_t _size;
};

void HashTest()
{
	HashTable<int,int> ht(10);
	ht.Insert(52,0);
	ht.Insert(18,0);
	ht.Insert(36,0);
	ht.Insert(53,0);
	ht.Insert(9,0);
	if(ht.Find(49,0))
	cout<<ht.Remove(58,0)<<endl;
		cout<<ht.Find(9,0)->_key<<endl;

	HashTable<string,string> ht1(10);
	ht1.Insert("sort","ÅÅÐò");
	ht1.Insert("left","×ó±ß");
	ht1.Insert("right","ÓÒ±ß");
	ht1.Insert("up","ÉÏ±ß");
	if(ht1.Find("sort","ÅÅÐò"))
		cout<<ht1.Find("sort","ÅÅÐò")->_key<<endl;
	cout<<ht1.Remove("sort","ÅÅÐò")<<endl;
}