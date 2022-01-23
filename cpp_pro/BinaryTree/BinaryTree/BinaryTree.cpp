#include "BinaryTree.h"
#include <iostream>
using namespace std;

void BinaryTree::Add(int val)
{
	Add(nullptr, root, val);
}

void BinaryTree::Print() const
{
	Print(root);
	cout << endl;
}

BinaryTree::~BinaryTree()
{
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

void BinaryTree::Clear(Node* node)
{
	if (node == nullptr)
	{
		return;
	}
	Print(node->left);
	Print(node->right);
	delete node;
}

void BinaryTree::Clear()
{
	Clear(root);
}
