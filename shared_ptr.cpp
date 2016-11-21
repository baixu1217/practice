#include<iostream>
using namespace std;
#include<memory>
#include<boost/shared_ptr.hpp>
template<typename T>
class Node
{
public:
	Node(const T& value)
		:_value(value)
	{}
	T _value;	
	weak_ptr<Node<T>> _pNext;
	weak_ptr<Node<T>> _pPre;
};

void FunTest()
{
	shared_ptr<Node<int>> sp1(new Node<int>(1));
	shared_ptr<Node<int>> sp2(new Node<int>(2));
	cout<<sp1.use_count()<<endl;
	cout<<sp2.use_count()<<endl;
	sp1->_pNext = sp2;
	sp2->_pPre = sp1;
	cout<<sp1.use_count()<<endl;
	cout<<sp2.use_count()<<endl;
}

int main()
{
	FunTest();
	return 0;
}