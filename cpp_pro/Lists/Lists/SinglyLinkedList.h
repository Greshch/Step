#pragma once
class SinglyLinkedList
{
private:
	struct Node
	{
		int value;
		Node* next;
	};

	Node* head = nullptr;
	Node* tail = nullptr;
	int count = 0;

public:
	void Print() const;
	bool IsEmpty() const;
	void Add(int val);
	void Insert(int pos, int val);
	void Remove(int pos);
	int LastIndexOf(int num);
	void Reverse();
	~SinglyLinkedList();

private:
	void Clear();
	void PrintReverse(Node*);
};

