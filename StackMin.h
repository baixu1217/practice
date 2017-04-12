#include<iostream>
using namespace std;
#include<stack>
#include<assert.h>
#include<string>

template<class T>
struct Less
{
	bool operator()(const T& left,const T& right)
	{
		return left < right;
	}
};

template<class T>
struct Greater
{
	bool operator()(const T& left,const T& right)
	{
		return left >= right;
	}
};

template<class T,class Compare>
class StackWithMax
{
public:
	void Push(const T& data);
	void Pop();
	T& MaxValue();

private:
	stack<T> value_st;
	stack<T> max_st;
};

template<class T,class Compare>
void StackWithMax<T,Compare>::Push(const T& data)
{
	value_st.push(data);
	if(max_st.size() == 0 || Compare()(data,max_st.top()))
		max_st.push(data);
	else
		max_st.push(max_st.top());
}

template<class T,class Compare>
void StackWithMax<T,Compare>::Pop()
{
	assert(value_st.size() >= 0 && max_st.size() >= 0);
	max_st.pop();
	value_st.pop();
}
template<class T,class Compare>
T& StackWithMax<T,Compare>::MaxValue()
{
	assert(value_st.size() >= 0 && max_st.size() >= 0);
	return max_st.top();
}

