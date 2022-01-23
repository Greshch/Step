#include "BinaryTree.h"
#include <iostream>
#include <stack>
using namespace std;

void BinaryTree::Add(int val)
{
	//Add(nullptr, root, val);
	AddStack(val);
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
	stack<Node*> repo;
	repo.push(root);
	while (!repo.empty())
	{
		Node* tmp = repo.top();
		if (tmp != nullptr)
		{
			repo.pop();
			int val = tmp->_val;
			cout << val << " ";
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

BinaryTree::Node* BinaryTree::Search(Node* cur, int val)
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

BinaryTree::Node* BinaryTree::SearchStack(int value)
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

void BinaryTree::Clear()
{
	Clear(root);
}

bool BinaryTree::Search(int val)
{
	//return Search(root, val);
	return SearchStack(val);
}
