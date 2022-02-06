#include "MyQuee.h"
#include <iostream>
using namespace std;

bool MyQuee::Empty() const
{
	return head == nullptr;
}

void MyQuee::Push(int value)
{
	++size;
	Node* curent = new Node{ value };
	if (Empty())
	{
		this->head = this->tail = curent;
		return;
	}
	tail->next = curent;
	tail = curent;
}

int MyQuee::Front() const
{
	if (Empty())
	{
		throw "Empty stack exception!\n";
	}
	return head->val;
}

int MyQuee::Back() const
{
	if (Empty())
	{
		throw "Empty stack exception!\n";
	}
	return tail->val;
}

int MyQuee::Peek() const
{
	return Front();
}

void MyQuee::Pop()
{
	if (Empty())
	{
		throw "Empty stack exception!\n";
	}
	Node* new_head = head->next;
	delete head;
	head = new_head;
	--size;
}

void MyQuee::Print() const
{
	if (Empty())
	{
		return;
	}
	Node* tmp = head;
	for (int i = 0; i < size; i++)
	{
		cout << tmp->val << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

MyQuee::~MyQuee()
{
	Clear();
}

void MyQuee::Clear()
{
	if (Empty())
	{
		tail = nullptr;
		size = 0;
		return;
	}
	Node* cur = head;
	Node* tmp = nullptr;
	for (int i = 0; i < size; i++)
	{
		tmp = cur;
		cur = cur->next;
		delete tmp;
	}
	head = tail = nullptr;
	size = 0;
}
