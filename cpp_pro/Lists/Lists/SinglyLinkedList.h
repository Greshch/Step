#pragma once
#include "MyVector.h"

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
	//////////////////////////////////
	SinglyLinkedList();
	SinglyLinkedList(SinglyLinkedList const&);
	SinglyLinkedList& operator=(SinglyLinkedList&);
	void Clone(SinglyLinkedList const& obj);
	bool Equals(SinglyLinkedList const& obj) const;
	//////////////////////////////////
	void Print() const;
	bool IsEmpty() const;
	void Add(int val);
	void Insert(int pos, int val);
	void Remove(int pos);
	int LastIndexOf(int num);
	void Reverse();
	void PrintReverse();
	~SinglyLinkedList();
	//////////////////////////////////
	void SortAsc();
	void SortDesc();
	void Shuffle();
	MyVector GetMyVector() const;
	void FillFromMyVector(MyVector const&);

private:
	void Clear();
	
	void PrintReverse(Node*);
	void Reverse(SinglyLinkedList& obj ,Node* node);
};

