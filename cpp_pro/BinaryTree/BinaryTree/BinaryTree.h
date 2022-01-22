#pragma once
class BinaryTree
{
private:
	struct Node
	{
		int _val;
		Node* parent = nullptr;
		Node* left = nullptr;
		Node* right = nullptr;
	};

	Node* root = nullptr;

public:
	void Add(int val);
	void Print() const;
	~BinaryTree();

private:
	void Print(Node* node) const;
	void Add(Node* pre, Node* cur, int val);
	void Clear();
};

