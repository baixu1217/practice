#pragma once
#include<iostream>
using namespace std;
#include<vector>

class UnionFindSet
{
public:
	//将每一个元素都初始化为-1
	UnionFindSet(size_t n)
	{
		_set.resize(n+1,-1);
	}

	//查找元素的根
	int FindRoot(int index)
	{
		int i = index;
		while(_set[i] >= 0)
		{
			i = _set[i];
		}
		return i;
	}

	//将每一对数组中有相同元素的都合并到一个数组中
	void Union(int num1,int num2)
	{
		int root1 = FindRoot(num1);
		int root2 = FindRoot(num2);
		if(root1 != root2)
		{
			_set[root1]+=_set[root2];
			_set[root2] = root1;
		}
	}

	int GetFriend(size_t n,size_t m,int a[][2])
	{
		int count = 0;

		for(int i = 0; i < m; ++i)   //m对好友需要合并好友圈
		{
			Union(a[i][0],a[i][1]);
		}

		for(int i = 1; i < n; i++)
		{
			if(_set[i] < 0)
				count++;
		}
		return count;
	}
private:
	vector<int> _set;
};

void UnionFindSetTest()
{
	size_t n = 5;
    size_t m = 3;
	int a[][2] = {{1,2},{2,3},{4,5}};
	UnionFindSet uf(n);
	cout<<uf.GetFriend(n,m,a)<<endl;
}