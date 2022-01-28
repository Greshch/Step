#pragma once
class MyVector;

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
	void Remove(int val);
	void Print() const;
	void Clear();
	bool Search(int val);
	~BinaryTree();

private:
	void PrintStack() const;
	void Print(Node* node) const;
	void Add(Node* pre, Node* cur, int val);
	void AddStack(int val);
	//void Remove(Node* node);
	void Clear(Node* node);
	void ClearStack();
	Node* Search(Node* node,int val) const;
	Node* SearchStack(int val) const;
	Node* LefterThenNode(Node*) const;
	Node* RighterThenNode(Node*) const;
	bool IsList(Node* node) const;
	void PrintLefterRighter() const;
	MyVector GetMyVector() const;
};

