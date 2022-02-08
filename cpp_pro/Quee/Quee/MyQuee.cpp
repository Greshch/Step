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
	if (size == 0)
	{
		head = tail = nullptr;
	}
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

bool PrQuee::Empty() const
{
	return head == nullptr;;
}

void PrQuee::Push(int value)
{
	++size;
	PrNode* curent = new PrNode{ value };
	if (Empty())
	{
		this->head = this->tail = curent;
		return;
	}
	curent->prev = tail;
	tail->next = curent;
	tail = curent;
}

void PrQuee::Push(int pri, int value)
{
	++size;
	PrNode* curent = new PrNode{ value, pri };
	if (Empty())
	{
		this->head = this->tail = curent;
		return;
	}
	/*curent->prev = tail;
	tail->next = curent;
	tail = curent;*/
	if (tail->prio >= pri) // Add to tail
	{
		curent->prev = tail;
		tail->next = curent;
		tail = curent;
		return;
	}
	PrNode* tmp = tail;
	while (tmp != nullptr && tmp->prio < pri)
	{
		tmp = tmp->prev;
	}
	// new head ... if tmp == nullptr
	if (tmp == nullptr)
	{
		head->prev = curent;		
		curent->next = head;
		head = curent;
	}
	else // we have to insert curent between tmp and tmp->next
	{
		PrNode* previos = tmp;
		PrNode* nexter = tmp->next;
		previos->next = curent;
		curent->prev = previos;
		curent->next = nexter;
		nexter->prev = curent;
	}
}

int PrQuee::Front() const
{
	if (Empty())
	{
		throw "Empty quee exception!\n";
	}
	return head->val;
}

int PrQuee::Back() const
{
	if (Empty())
	{
		throw "Empty quee exception!\n";
	}
	return tail->val;
}

int PrQuee::Peek() const
{
	return Front();
}

void PrQuee::Pop()
{
	if (Empty())
	{
		throw "Empty stack exception!\n";
	}
	PrNode* new_head = head->next;
	if (head->next != nullptr)
	{
		head->next->prev = nullptr;
	}
	 // Double list!!
	delete head;
	head = new_head;
	--size;
	if (size == 0)
	{
		head = tail = nullptr;
	}
}

void PrQuee::Print() const
{
	if (Empty())
	{
		return;
	}
	PrNode* tmp = head;
	for (int i = 0; i < size; i++)
	{
		cout << "{" << tmp->prio << "," << tmp->val << "} ";
		tmp = tmp->next;
	}
	cout << endl;
}

PrQuee::~PrQuee()
{
	Clear();
}

void PrQuee::Clear()
{
	if (Empty())
	{
		tail = nullptr;
		size = 0;
		return;
	}
	PrNode* cur = head;
	PrNode* tmp = nullptr;
	for (int i = 0; i < size; i++)
	{
		tmp = cur;
		cur = cur->next;
		delete tmp;
	}
	head = tail = nullptr;
	size = 0;
}
