#pragma once
#include<assert.h>
#include<iostream>
using namespace std;
enum Tag
{
	THREAD,
	LINK
};
template<typename  T>
struct BinaryTreeThdNode
{
	T _data;
	BinaryTreeThdNode<T>* _left;
	BinaryTreeThdNode<T>* _right;

	Tag _leftTag;
	Tag _rightTag;

	BinaryTreeThdNode(const T& data)
		:_data(data)
		,_left(NULL)
		,_right(NULL)
		,_leftTag(LINK)
		,_rightTag(LINK)
	{}
};

template<typename T>
class BinaryTreeThd
{
	typedef BinaryTreeThdNode<T> Node;
public:
	BinaryTreeThd(const T* arr,size_t size,const T& invalid = T())
	{
		assert(arr);
		size_t index = 0;
		_root = Create(arr,index,size,invalid);         //创建线索化二叉树
	}
	void PrevOrderThd()                     //前序线索化
	{
		assert(_root);
		Node* prev = _root;
		_PrevOrderThd(_root,prev);
	}
	void _PrevOrderThd(Node* root,Node*& prev)
	{
		if(root == NULL)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
			return;
		if(root->_left == NULL)
		{
			root->_left = prev;
			root->_leftTag = THREAD;
		}
		if(prev && prev->_right == NULL)
		{
			prev->_right = root;
			prev->_rightTag = THREAD;
		}

		prev = root;
		if(root->_leftTag == LINK)
			_PrevOrderThd(root->_left,prev);
		if(root->_rightTag == LINK)
			_PrevOrderThd(root->_right,prev);
	}

	void PrevOrderPrint()                  //前序线索化的打印
	{
		assert(_root);
		_PrevOrderPrint(_root);
	}

	void _PrevOrderPrint(Node* root)
	{
		Node* cur = root;
		if(root == NULL)
			return;
		while(cur)
		{
			while(cur->_leftTag == LINK)
			{
				cout<<cur->_data<<" ";
				cur = cur->_left;
			}
			cout<<cur->_data<<" ";
			while(cur && cur->_rightTag == THREAD)
			{
				cur = cur->_right;
				if(cur)
					cout<<cur->_data<<" ";
			}
			if(cur)
				cur = cur->_right;
		}
	}

	void InOrderThd()             //中序线索化
	{
		assert(_root);
		Node* prev = NULL;
		_InOrderThd(_root,prev);
		prev->_right = NULL;
		prev->_rightTag = THREAD;
	}

	void _InOrderThd(Node* root,Node*& prev)      //中序线索化     
	{
		if(root == NULL)
			return;
		//找到最左节点
		_InOrderThd(root->_left,prev);
		//对左节点为空的节点进行线索化
		if(root->_left == NULL)
		{
			root->_left = prev;
			root->_leftTag = THREAD;
		}
		
		//对右节点为空的节点进行线索化
		if(prev && prev->_right == NULL)
		{
			prev->_right = root;
			prev->_rightTag = THREAD;
		}
		prev = root;
		_InOrderThd(root->_right,prev);
	}
	void InOrderThdPrint()
	{
		assert(_root);
		_InOrderThdPrint(_root);
	}
	void _InOrderThdPrint(Node* root)          //中序线索化打印
	{
		Node* cur = root;
		if(cur == NULL)
			return;
		while(cur)
		{
			//找到它的最左节点
			while(cur->_leftTag == LINK)
			{
				cur = cur->_left;
			}
			//输出节点值
			cout<<cur->_data<<" ";
			//如果当前结点的右为线索化，就访问它的后继节点
			while(cur && cur->_rightTag == THREAD)
			{
				cur = cur->_right;
				if(cur)
					cout<<cur->_data<<" ";
			}
			//否则就访问它的右子树
			if(cur)
				cur = cur->_right;
		}
	}
	void InOrder()
	{
		assert(_root);
		_InOrder(_root);
		cout<<endl;
	}
	void _InOrder(Node* root)           //中序遍历
	{
		if(root == NULL)
			return;
		_InOrder(root->_left);
		cout<<root->_data<<" ";
		_InOrder(root->_right);

	}
public:
	Node* Create(const T* arr,size_t &index,size_t size,const T& invalid)  //创建线索化二叉树
	{
		Node* root = NULL;
		if(index < size && arr[index] != invalid)
		{
			root = new Node(arr[index]);
			root->_left = Create(arr,++index,size,invalid);
			root->_right = Create(arr,++index,size,invalid);
		}
		return root;
	}
private:
	Node* _root;
};


void FunTest()
{
	int arr[] = {1,2,3,'#','#',4,'#','#',5,6};
	BinaryTreeThd<int> bt(arr,sizeof(arr)/sizeof(arr[0]),'#');
	bt.InOrder();
//	bt.InOrderThd();
//	bt.InOrderThdPrint();
	bt.PrevOrderThd();
	bt.PrevOrderPrint();
}