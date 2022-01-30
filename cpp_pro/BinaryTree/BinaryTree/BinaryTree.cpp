#include "BinaryTree.h"
#include "MyVector.h"
#include <iostream>
#include <stack>
using namespace std;

void BinaryTree::Add(int val)
{
	//Add(nullptr, root, val);
	AddStack(val);
}

void BinaryTree::Remove(int val)
{
	Node* tmp = SearchStack(val);
	if (tmp == nullptr)
	{
		return;
	}

	if (tmp == root)
	{
		MyVector vec = GetMyVector();
		//vec.Print();
		vec.Shuffle();
		int sz = vec.GetSize();
		Clear();
		for (int i = 0; i < sz; i++)
		{
			this->Add(vec[i]);
		}
		return;
	}

	Node* prev = tmp->parent;
	if (IsList(tmp))
	{
		if (prev->left == tmp)
		{
			prev->left = nullptr;
		}
		else
		{
			prev->right = nullptr;
		}
		return;
	}

	if (tmp->left != nullptr)
	{
		Node* rb = RighterThenNode(tmp->left);
		tmp->_val = rb->_val;
		if (tmp->left == rb)
		{
			if (IsList(rb))
			{
				tmp->left = nullptr;
			}
			else
			{
				rb->left->parent = tmp;
				tmp->left = rb->left;
			}
		}
		else
		{
			rb->parent->right = rb->left;
			if (rb->left != nullptr)
			{
				rb->left->parent = rb->parent;
			}
		}
		delete rb;
	}
	else if (tmp->right != nullptr)
	{
		Node* lb = LefterThenNode(tmp->right);
		tmp->_val = lb->_val;
		if (tmp->right == lb)
		{
			if (IsList(lb))
			{
				tmp->right = nullptr;
			}
			else
			{
				lb->right->parent = tmp;
				tmp->right = lb->right;
			}
		}
		else
		{
			lb->parent->left = lb->right;
			if (lb->right != nullptr)
			{
				//rb->parent->right = rb->left;
				lb->right->parent = lb->parent;
			}
		}
		delete lb;
	}
	//delete tmp;
}

void BinaryTree::Print() const
{
	//Print(root);
	PrintStack();
	cout << endl;
}

BinaryTree::~BinaryTree()
{
	Clear();
}

void BinaryTree::PrintStack() const
{
	if (root == nullptr)
	{
		return;
	}
	stack<Node*> repo;
	repo.push(root);
	while (!repo.empty())
	{
		Node* tmp = repo.top();
		if (tmp != nullptr)
		{
			repo.pop();
			int val = tmp->_val;
			cout << val << (IsList(tmp) ? "^ " : " ");
			if (tmp->left != nullptr)
			{
				repo.push(tmp->left);
			}
			if (tmp->right != nullptr)
			{
				repo.push(tmp->right);
			}
		}
	}
}

void BinaryTree::Print(Node* node) const
{
	if (node == nullptr)
	{
		return;
	}
	Print(node->left);
	Print(node->right);
	cout << node->_val << " ";
}

void BinaryTree::Add(Node* pre, Node* cur, int val)
{
	if (root == nullptr)
	{
		Node* tmp = new Node{ val };
		root = tmp;
		return;
	}

	if (cur == nullptr)
	{
		Node* tmp = new Node{ val, pre };
		if (val < pre->_val)
		{
			pre->left = tmp;
		}
		else
		{
			pre->right = tmp;
		}
		return;
	}

	if (cur->_val == val)
	{
		return;
	}
	if (val < cur->_val)
	{
		Add(cur, cur->left, val);
	}
	else
	{
		Add(cur, cur->right, val);
	}
}

void BinaryTree::AddStack(int value)
{
	
	if (root == nullptr)
	{
		Node* neo_node = new Node{ value };
		root = neo_node;
		return;
	}
	stack<Node*> repo;
	repo.push(root);
	bool left = false;
	Node* prev = root;
	while (!repo.empty())
	{
		Node* tmp = repo.top();
		if (tmp != nullptr)
		{
			repo.pop();
			int val = tmp->_val;
			if (val == value)
			{
				return;
			}
			if (value < val)
			{
				left = true;
				repo.push(tmp->left);
			}
			else
			{
				left = false;
				repo.push(tmp->right);
			}
		}
		else
		{
			Node* neo_node = new Node{ value, prev };
			if (left)
			{
				prev->left = neo_node;
			}
			else
			{
				prev->right = neo_node;
			}
			return;
		}
		prev = tmp;
	}
}

void BinaryTree::Clear(Node* node)
{
	if (node == nullptr)
	{
		return;
	}
	Clear(node->left);
	Clear(node->right);
	delete node;
}

void BinaryTree::ClearStack()
{
	if (root == nullptr)
	{
		return;
	}
	stack<Node*> repo;
	repo.push(root);
	while (!repo.empty())
	{
		Node* tmp = repo.top();
		if (tmp != nullptr)
		{
			repo.pop();
			if (tmp->left != nullptr)
			{
				repo.push(tmp->left);
			}
			if (tmp->right != nullptr)
			{
				repo.push(tmp->right);
			}
			//cout << "#" << tmp->_val << endl;
			delete tmp;
			tmp = nullptr;
		}
	}
	root = nullptr;
}

BinaryTree::Node* BinaryTree::Search(Node* cur, int val) const
{
	if (cur == nullptr || cur->_val == val)
	{
		return cur;
	}

	if (val < cur->_val)
	{
		Search(cur->left, val);
	}
	else
	{
		Search(cur->right, val);
	}
}

BinaryTree::Node* BinaryTree::SearchStack(int value) const
{
	stack<Node*> repo;
	repo.push(root);
	while (!repo.empty())
	{
		Node* tmp = repo.top();
		if (tmp != nullptr)
		{
			repo.pop();
			int val = tmp->_val;
			if (val == value)
			{
				return tmp;
			}
			if (value < val)
			{
				repo.push(tmp->left);
			}
			else
			{
				repo.push(tmp->right);
			}
		}
		else
		{
			return nullptr;
		}
	}
}

BinaryTree::Node* BinaryTree::LefterThenNode(Node* node) const
{
	stack<Node*> repo;
	repo.push(node);
	while (!repo.empty())
	{
		Node* tmp = repo.top();
		if (tmp != nullptr)
		{
			repo.pop();
			if (tmp->left != nullptr)
			{
				repo.push(tmp->left);
			}
			else
			{
				return tmp;
			}
		}
		else
		{
			return tmp->parent;
		}
	}
	return nullptr;
}

BinaryTree::Node* BinaryTree::RighterThenNode(Node* node) const
{
	stack<Node*> repo;
	repo.push(node);
	while (!repo.empty())
	{
		Node* tmp = repo.top();
		if (tmp != nullptr)
		{
			repo.pop();
			if (tmp->right != nullptr)
			{
				repo.push(tmp->right);
			}
			else
			{
				return tmp;
			}
		}
		else
		{
			return tmp->parent;
		}
	}
	return nullptr;
}

bool BinaryTree::IsList(Node* node) const
{
	if (node == nullptr)
	{
		return false;
	}
	return node->left == nullptr && node->right == nullptr;
}

void BinaryTree::Clear()
{
	//Clear(root);
	ClearStack();
}

bool BinaryTree::Search(int val)
{
	//return Search(root, val);
	return SearchStack(val);
}

void BinaryTree::PrintLefterRighter() const
{
	cout << "Min -> " << LefterThenNode(root)->_val << "\tMax -> "
		<< RighterThenNode(root)->_val << endl;
}

MyVector BinaryTree::GetMyVector() const
{
	MyVector res;
	stack<Node*> repo;
	repo.push(root);
	while (!repo.empty())
	{
		Node* tmp = repo.top();
		if (tmp != nullptr)
		{
			repo.pop();
			int val = tmp->_val;
			res.PushBack(val);
			if (tmp->left != nullptr)
			{
				repo.push(tmp->left);
			}
			if (tmp->right != nullptr)
			{
				repo.push(tmp->right);
			}
		}
	}
	return res;
}
