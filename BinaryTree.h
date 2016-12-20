#pragma once 
#include<assert.h>
#include<queue>
#include<iostream>
using namespace std;

template<typename T>
struct BinaryTreeNode
{
	T _data;
	BinaryTreeNode<T> *_left;
	BinaryTreeNode<T> *_right;
	BinaryTreeNode(const T& data)
		:_data(data)
		, _left(NULL)
		, _right(NULL)
	{}
};

template<typename T>
class BinaryTree
{
	typedef BinaryTreeNode<T> Node;
public:
	BinaryTree()
		:_root(NULL)
	{}
	BinaryTree(T* arr,size_t size,const T& invalid = T())
	{
		assert(arr);
		size_t index = 0;
		_root = CreateTree(arr,size,invalid,index);
	}

	BinaryTree(BinaryTree<T> &t)
	{
		assert(t._root);
		_root = _Copy(t._root);
	}
	//传统写法
	/*BinaryTree<T>& operator=(BinaryTree<T>& t)
	{
		if (this != &t)
		{
			Node* tmp = _Copy(t._root);
			_root = _Destroy(_root);
			_root = tmp;
		}
		return *this;
	}*/
	//现代写法
	BinaryTree<T>& operator=(BinaryTree<T>& t)
	{
		if (this != &t)
		{
			BinaryTree<T> tmp(t);
			std::swap(tmp._root, _root);
		}
		return *this;
	}

	~BinaryTree()
	{
		if (_root)
		{
			_root = _Destroy(_root);
		}
	}
public:
	size_t Size()
	{
		return _Size(_root);
	}
	size_t Depth()
	{
		return _Depth(_root);
	}

	void PreOrder()
	{
		_PreOrder(_root);
		cout << endl;
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	void PostOrder()
	{
		_PostOrder(_root);
		cout << endl;
	}

	void LevelOrder()
	{
		_LevelOrder(_root);
		cout << endl;
	}
public:

	Node* CreateTree(T* arr, size_t size, const T& invalid,size_t& index)
	{
		Node* root = NULL;
		if (index < size)
		{
			if (arr[index] != invalid)
			{
				root = new Node(arr[index]);
				root->_left = CreateTree(arr, size, invalid, ++index);
				root->_right = CreateTree(arr, size, invalid, ++index);
			}
		}
		return root;
	}

	Node* _Copy(Node* root)
	{
		Node* cur = NULL;
		if (root)
		{
			cur = new Node(root->_data);
			cur->_left = _Copy(root->_left);
			cur->_right = _Copy(root->_right);
		}
		return cur;
	}

	Node* _Destroy(Node* root)
	{
		if (root != NULL)
		{
			root->_left = _Destroy(root->_left);
			root->_right = _Destroy(root->_right);
			delete root;
			root = NULL;
		}
		return root;
	}
	size_t _Size(Node* root)
	{
		if (root == NULL)
			return 0;
		return _Size(root->_left) + _Size(root->_right) + 1;
	}
	size_t _Depth(Node* root)
	{
		size_t maxDepth = 1;
		if (root)
		{
			size_t depth = 1;
			if (root->_left)
			{
				depth += _Depth(root->_left);
			}
			if (depth > maxDepth)
			{
				maxDepth = depth;
			}
			if (root->_right)
			{
				depth = _Depth(root->_right) + 1;
			}
			if (depth > maxDepth)
			{
				maxDepth = depth;
			}
		}
		return maxDepth;
	}

	void _PreOrder(Node* root)
	{
		if (root)
		{
			cout << root->_data << " ";
			_PreOrder(root->_left);
			_PreOrder(root->_right);

		}
	}

	void _InOrder(Node* root)
	{
		if (root)
		{
			_InOrder(root->_left);
			cout << root->_data << " ";
			_InOrder(root->_right);

		}
	}
	void _PostOrder(Node* root)
	{
		if (root)
		{
			_PostOrder(root->_left);
			_PostOrder(root->_right);
			cout << root->_data << " ";
		}
	}
	void _LevelOrder(Node* root)
	{
		queue<Node*> q;
		if (root)
			q.push(root);
		while (!q.empty())
		{
			Node* front = q.front();
			cout << front->_data << " ";
			q.pop();
			if (front->_left)
			{
				q.push(front->_left);
			}
			if (front->_right)
			{
				q.push(front->_right);
			}
		}
	}

private:
	Node* _root;
};


void FunTest()
{
	int arr[] = {1,2,3,'#','#',4,'#','#',5,6};
	int arr1[] = { 1, 2,'#', 3, '#', '#', 4, 5,'#',6 ,'#', 7,'#','#',8};

	BinaryTree<int> b1(arr,sizeof(arr)/sizeof(arr[0]),'#');
	BinaryTree<int> b6(arr1, sizeof(arr1) / sizeof(arr1[0]), '#');

	BinaryTree<int> b2(b1);
	BinaryTree<int> b3;
	b3 = b2;
	cout << b1.Size() << endl;
	cout << b2.Size() << endl;
	cout << b3.Size() << endl;
	cout << b1.Depth() << endl;
	cout << b6.Depth() << endl;
	b1.PreOrder();
	b1.InOrder();
	b1.PostOrder();
	b1.LevelOrder();
	b6.PreOrder();
	b6.InOrder();
	b6.PostOrder();
	b6.LevelOrder();
}