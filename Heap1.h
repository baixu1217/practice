#pragma once
#include <vector>

template<class T>
struct Less
{
	bool operator()(const T& l, const T& r)
	{
		return l < r;
	}
};

template<class T>
struct Greater
{
	bool operator()(const T& l, const T& r)
	{
		return l > r;
	}
};

template<class T, class Compare = Greater<T>>
class Heap
{
public:
	Heap()
	{}

	Heap(T* a, size_t n)
		:_a(a, a+n)
	{
		/*_a.reserve(n);
		for (size_t i = 0; i < n; ++i)
		{
			_a.push_back(a[i]);
		}*/

		// 建堆
		for(int i = (_a.size()-2)/2; i >= 0; i--)
		{
			_AdjustDown(i);
		}
	}

	void Push(const T& x)
	{
		_a.push_back(x);
		_AdjustUp(_a.size()-1);
	}

	void Pop()
	{
		swap(_a[0], _a[_a.size()-1]);
		_a.pop_back();
		_AdjustDown(0);
	}

protected:
	void _AdjustUp(int child)
	{
		Compare compare;

		int parent = (child-1)/2;
		
		//while(parent >= 0) 有问题？
		while(child > 0)
		{
			//if (_a[parent] < _a[child])
			if (compare(_a[child], _a[parent]))
			{
				swap(_a[parent], _a[child]);
				child = parent;
				parent = (child-1)/2;
			}
			else
			{
				break;		
			}
		}
	}

	// 根的左右子树都是堆
	void _AdjustDown(int root)
	{
		Compare compare;
		int parent = root;
		int child = root*2+1;
		while(child < _a.size()) //?
		{
			// 找左右孩子里面大的那一个
			//if (child+1 < _a.size()
			//	&& _a[child+1] > _a[child])
			if (child+1 < _a.size()
				&& compare(_a[child+1],_a[child]))
			{
				++child;
			}

			// 1.如果孩子大于父亲，则交换，继续往下调整
			// 2.否则，结束
			//if (_a[child] > _a[parent])
			if(compare(_a[child],_a[parent]))
			{
				swap(_a[child], _a[parent]);
				parent = child;
				child = parent*2+1;
			}
			else
			{
				break;
			}
		}
	}

	size_t Size()
	{
		return _a.size();
	}

	bool Empty()
	{
		return _a.empty();
	}

	T& Top()
	{
		assert(!_a.empty());
		return _a[0];
	}

protected:
	//T* _a;
	//size_t _size;
	//size_t _capacity;
	vector<T> _a;
};

template<class T, class Compare = Greater<int>>
class PriorityQueue
{
public:
	void Push(const T& x)
	{
		_hp.Push(x);
	}

	void Pop()
	{
		_hp.Pop();
	}

	const T& Top()
	{
		return _hp.Top();
	}

	size_t Size();
	bool Empty();

protected:
	Heap<T, Compare> _hp;
};

void TestHeap()
{
	int a[] = {10,11, 13, 12, 16, 18, 15, 17, 14, 19};
	Heap<int, Less<int>> hp1(a, sizeof(a)/sizeof(a[0]));
	hp1.Push(20);
	hp1.Pop();
}

void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent*2+1;
	while (child < n)
	{
		if (child+1 < n && a[child+1] < a[child])
		{
			++child;
		}

		if (a[child] < a[parent])
		{
			swap(a[child], a[parent]);
			parent = child;
			child = parent*2+1;
		}
		else
		{
			break;
		}
	}
}


void GetTopK(int* a, const int n, const int k)
{
	assert(n > k && a);
	
	int* heap = new int[k];
	for (size_t i = 0; i < k; ++i)
	{
		heap[i] = a[i];
	}

	// 建堆
	for(int i = (k-2)/2; i >= 0; --i)
	{
		AdjustDown(heap, k, i);
	}

	// 选最大的前k个
	for (size_t i = k; i < n; ++i)
	{
		if(a[i] > heap[0])
		{
			heap[0] = a[i];
		}

		AdjustDown(heap, k, 0);
	}

	cout<<"最大的前"<<k<<"个数据:"<<endl;
	for (size_t i = 0; i < k; ++i)
	{
		cout<<heap[i]<<" ";
	}

	delete[] heap;
}

void TestTopK()
{
	const int N = 1000, K = 5;
	int a[N];
	for (size_t i = 0; i < N; ++i)
	{
		a[i] = rand()%N;
	}

	a[0] = N+1;
	a[10] = N+2;
	a[100] = N+3;
	a[99] = N+4;
	a[50] = N+5;


	GetTopK(a, N, K);
}

// 降序
void HeapSort(int* a, int n)
{
	assert(n);

	// 建小堆
	for(int i = (n-2)/2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	int end = n-1;
	while(end > 0)
	{
		swap(a[0], a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}