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
	void Clear();
	bool Search(int val);
	~BinaryTree();

private:
	void PrintStack() const;
	void Print(Node* node) const;
	void Add(Node* pre, Node* cur, int val);
	void Clear(Node* node);
	Node* Search(Node* node,int val);
};

