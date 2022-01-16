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
	SinglyLinkedList& operator=(SinglyLinkedList const&);
	SinglyLinkedList operator+(SinglyLinkedList const& obj);
	SinglyLinkedList& operator+=(SinglyLinkedList const& obj);
	//////////////////////////////////
	void Print() const;
	bool IsEmpty() const;
	void Add(int val);
	void Insert(int pos, int val);
	void Remove(int pos);
	int LastIndexOf(int num);
	bool Contains(int elem);
	void Clone(SinglyLinkedList const& obj);
	bool Equals(SinglyLinkedList const& obj) const;
	void Reverse();
	void PrintReverse();
	void SetAt(int index, int val);
	~SinglyLinkedList();
	//////////////////////////////////
	void SortAsc();
	void SortDesc();
	void Shuffle();
	MyVector GetMyVector() const;// Insted ToArray
	void MergeWith(SinglyLinkedList const&);
	void FillFromMyVector(MyVector const&);

private:
	void Clear();
	void PrintReverse(Node*);
	void Reverse(SinglyLinkedList& obj ,Node* node);
};

