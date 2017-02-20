#pragma once
#include<iostream>
using namespace std;
#include<vector>

namespace HashBucket
{
	template<class K,class V>
	class HashTable;

	template<class K,class V>
	struct HashNode
	{
		pair<K,V> _kv;
		HashNode<K,V> *_next;

		HashNode(const pair<K,V>& kv)
			:_kv(kv)
			,_next(NULL)
		{}
	};
	template<class K,class V,class Ref,class Ptr>
	struct HashIterator
	{
		typedef HashNode<K,V> Node;
		typedef HashIterator<K,V,Ref,Ptr> Self;
		Node* _node;
		HashTable<K,V>* _ht;

		HashIterator(Node* node,HashTable<K,V>* ht)
			:_node(node)
			,_ht(ht)
		{}

		Ref operator*()
		{
			return _node->_kv;
		}

		Ptr operator->()
		{
			return &_node;
		}

		bool operator!=(const Self& s) const
		{
			return _node != s._node;
		}

		Self& operator++()
		{
			_node = Next(_node);
			return *this;
		}

		Node* Next(Node* node)
		{
			Node* next = node->_next;
			if(next)
				return next;
			else
			{
				size_t index = _ht->HashFunc(node->_kv.first)+1;
				for(;index < _ht->_tables.size();++index)
				{
					next = _ht->_tables[index];
					if(next)
					{
						return next;
					}
				}
				return NULL;
			}
		}
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

	template<class K,class V>
	class HashTable
	{
		typedef HashNode<K,V> Node;
	public:
		typedef HashIterator<K,V,pair<K,V>&,pair<K,V>*> Iterator;
		typedef HashIterator<K,V,const pair<K,V>&,const pair<K,V>*> ConstIterator;
		friend struct Iterator;
		friend struct ConstIterator;
	public:
		HashTable()
		:_size(0)
		{
			_tables.resize(GetNextPrime());
		}

		~HashTable()
		{
			Clear();
		}

		void Clear()
		{
			Node* cur = NULL;
			Node* del = NULL;
			for(size_t index = 0; index < _tables.size(); ++index)
			{
				cur = _tables[index];
				if(cur == NULL)
				{
					continue;
				}
				while(cur)
				{
					del = cur;
					cur = cur->_next;
					delete del;
					del = NULL;
				}
			}

		}

		Iterator Begin()
		{
			Node* cur = _tables[0];
			for(size_t index = 0; index < _tables.size();++index)
			{
				cur = _tables[index];
				if(cur)
				{
					return Iterator(cur,this);
				}
			}
			return Iterator((Node*)NULL,this);
		}

		Iterator End()
		{
			return Iterator((Node*)NULL,this);
			/*Node* cur = _tables[_tables.size()-1];
			while(cur)
			{
				if(cur == NULL)
				{
					return Iterator(cur,this);
				}
				cur = cur->_next;
			}
			return Iterator((Node*)NULL,this);*/
		}

		size_t HashFunc(const K& key)
		{
			__HashFunc<K> hf;
			size_t va = hf(key);
			return va % _tables.size();
		}

		void Swap(HashTable<K,V>& ht)
		{
			_tables.swap(ht._tables);
			swap(_size,ht._size);
		}

		void _CheckCapacity()
		{
			//负载因子为1时，扩容
			if(_size == _tables.size())
			{
				size_t index = GetNextPrime();
				HashTable<K,V> tmp;
				tmp._tables.resize(index);
				Node* cur = NULL;
				for(;index < _tables.size();++index)
				{
					cur = _tables[index];
					while(cur)
					{
						tmp.Insert(cur->_kv);
						cur = cur->_next;
					}
				}
				this->Swap(tmp);
			}
		}

		size_t GetNextPrime()
		{
			// 使用素数表对齐做哈希表的容量，降低哈希冲突
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
	public:
		pair<Iterator,bool> Insert(pair<K,V> kv)
		{
			_CheckCapacity();
			size_t index = HashFunc(kv.first);
			Node* cur = _tables[index];
			while(cur)
			{
				if(cur->_kv.first == kv.first)
				{
					return make_pair(Iterator(cur,this),false);
				}
				cur = cur->_next;
			}
			Node* tmp = new Node(kv);
			tmp->_next = _tables[index];
			_tables[index] = tmp;
			_size++;
			return make_pair(Iterator(tmp,this),true);
		}

		Node* Find(const K& key)
		{
			size_t index = HashFunc(key);
			Node* cur = _tables[index];
			while(cur)
			{
				if(cur->_kv.first == key)
				{
					return cur;
				}
				cur = cur->_next;
			}
			return NULL;
		}

		bool Erase(const K& key)
		{
			size_t index = HashFunc(key);
			Node* prev = NULL;
			Node* cur = _tables[index];
			Node* del = NULL;
			while (cur)
			{
				if(cur->_kv.first == key)
				{
					if(prev == NULL)
					{
						_tables[index] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}
					delete cur;
					cur = NULL;
					_size--;
					return true;
				}
				prev = cur;
				cur = cur->_next;
			}
			return false;
		}
	private:
		vector<Node*> _tables;
		size_t _size;
	};

	void HashTest()
	{
		HashTable<int,int> ht;
		ht.Insert(make_pair<int,int>(89,0));
		ht.Insert(make_pair<int,int>(18,0));
		ht.Insert(make_pair<int,int>(49,0));
		ht.Insert(make_pair<int,int>(58,0));
		ht.Insert(make_pair<int,int>(9,0));
		cout<<ht.Erase(58)<<endl;
		if(ht.Find(49))
			cout<<ht.Find(9)->_kv.first<<endl;
		HashTable<int,int>::Iterator it = ht.Begin();
		while(it != ht.End())
		{
			cout<<(*it).first<<":"<<(*it).second<<endl;
			++it;
		}
	}
};