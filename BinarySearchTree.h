#pragma once

template<typename K>
struct BinarySearchTreeNode
{
	BinarySearchTreeNode<K> *_left;
	BinarySearchTreeNode<K> *_right;

	K _key;
	BinarySearchTreeNode(const K& key)
		:_left(NULL)
		,_right(NULL)
		,_key(key)
	{}
};

template<typename K>
class BinarySearchTree
{
	typedef BinarySearchTreeNode<K> Node;
public:
	BinarySearchTree()
		:_root(NULL)
	{}

	~BinarySearchTree()
	{
		BSTDestroy();
	}
public:
	void BSTDestroy()
	{
		_BSTDestroy(_root);
		_root = NULL;
	}
	void _BSTDestroy(Node* root)
	{
		if(root == NULL)
			return;
		_BSTDestroy(root->_left);
		_BSTDestroy(root->_right);
		delete root;
	}
public:
	bool Insert(const K& key)
	{
		Node* cur = _root;
		Node* parent = NULL;
		if(_root == NULL)
		{
			_root = new Node(key);
			return true;
		}
		while(cur)
		{
			if(cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if(cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		//在此判断key值来确定插入的位置
		if(parent->_key > key)
		{
			parent->_left = new Node(key);
		}
		else
		{
			parent->_right = new Node(key);
		}
	}

	Node* Find(const K& key)
	{
		Node* cur = _root;
		while(cur)
		{
			if(cur->_key > key)
			{
				cur = cur->_left;
			}
			else if(cur->_key < key)
			{
				cur = cur->_right;
			}
			else
			{
				return cur;
			}
		}
		return NULL;
	}

	void Remove(const K& key)
	{
		Node* cur = _root;
		Node* parent = NULL;
		
		while(cur)
		{
			Node* del = cur;
			if(cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if(cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else          //找到要删除的节点
			{
				if(cur->_left == NULL)
				{
					//根的左边无节点
					if(parent == NULL)
					{
						_root = _root->_right;
						delete del;
						del = NULL;
						break;
					}
					if(parent->_left == cur )
					{
						parent->_left = cur->_right;
					}
					else
					{
						parent->_right = cur->_right;
					}
				}
				else if(cur->_right == NULL)
				{
					//根的右边无节点
					if(parent == NULL)
					{
						_root = _root->_left;
						delete del;
						del = NULL;
						break;
					}
					if(parent->_left == cur)
					{
						parent->_left = cur->_left;
					}
					else
					{
						parent->_right = cur->_left;
					}
				}
				else
				{
					parent = cur;
					Node* subLeft = cur->_right;
					
					if(subLeft->_left == NULL)
					{
						parent->_right = subLeft->_right;
					}
					else
					{
						while(subLeft->_left)
						{
							parent = subLeft;
							subLeft = subLeft->_left;
						}
						parent->_left = subLeft->_right;
					}
					del = subLeft;
					cur->_key = subLeft->_key;
				}
				delete del;
				del = NULL;
				break;
			}
		}
	}
	void InOrder()
	{
		_InOrder(_root);
	}

	void _InOrder(Node* root)
	{
		if(root == NULL)
			return;
		_InOrder(root->_left);
		cout<<root->_key<<" ";
		_InOrder(root->_right);
	}
private:
	Node* _root;
};


void BSTreeTest()
{
	int a[] = {5,3,1,4,0,2,7,6,8,9,12};
	BinarySearchTree<int> bt;
	for(int i = 0; i < sizeof(a)/sizeof(a[0]);i++)
	{ 
		bt.Insert(a[i]);
	}
	bt.InOrder();
	cout<<endl;
	cout<<bt.Find(2)->_key<<endl;
	bt.Remove(2);
	bt.Remove(1);
	bt.Remove(8);
	bt.Remove(5);


	bt.InOrder();
	//cout<<endl;
	//bt.Remove(0);
	//bt.Remove(1);
	//bt.Remove(2);
	//bt.Remove(3);
	//bt.Remove(4);
	//bt.Remove(5);
	//bt.Remove(6);
	//bt.Remove(7);
	//bt.Remove(8);
	//bt.Remove(9);
	//bt.InOrder();
	cout<<endl;
	bt.Remove(0);
	bt.Remove(6);
	bt.Remove(7);
	bt.Remove(8);
	bt.Remove(9);
	bt.Remove(12);
	bt.Remove(1);
	bt.Remove(2);
	bt.Remove(4);
	bt.Remove(5);
	bt.InOrder();
}