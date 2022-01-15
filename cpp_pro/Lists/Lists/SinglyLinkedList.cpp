#include "SinglyLinkedList.h"
#include <iostream>
using namespace std;

SinglyLinkedList::SinglyLinkedList()
{
}

SinglyLinkedList::SinglyLinkedList(SinglyLinkedList const& obj)
{
	Clone(obj);
}

SinglyLinkedList& SinglyLinkedList::operator=(SinglyLinkedList& obj)
{
	if (&obj != this)
	{
		Clear();
		Clone(obj);
	}
	return *this;
}

void SinglyLinkedList::Print() const
{
	Node* cur = head;
	for (int i = 0; i < count; i++)
	{
		cout << cur->value << " " ;
		if (i && i % 10 == 0)	cout << endl;
		cur = cur->next;
	}
	cout << endl;
}

bool SinglyLinkedList::IsEmpty() const
{
	return count == 0;
}

void SinglyLinkedList::Add(int val)
{
	Node* cur = new Node{ val, nullptr };
	if (IsEmpty())
	{
		head = tail = cur;
	}
	else
	{
		tail->next = cur;
		tail = cur;
	}
	++count;
}

void SinglyLinkedList::Insert (int pos, int val)
{
	if (pos < 0 || pos > count) return;
	if (pos == count)
	{
		Add(val);
		return;
	}
	Node* cur = new Node{ val, nullptr };
	if (IsEmpty())
	{
		head = tail = cur;
	}
	else if (pos == 0)
	{
		cur->next = head;
		head = cur;
	}
	else
	{
		Node* tmp = head;
		for (int i = 0; i < pos - 1; i++)
		{
			tmp = tmp->next;
		}
		cur->next = tmp->next;
		tmp->next = cur;
	}
	++count;
}

void SinglyLinkedList::Remove(int pos)
{
	if (pos < 0 || pos > count || IsEmpty()) return;

	Node* pre = head;
	Node* dummy = nullptr;
	if (pos == 0)
	{
		dummy = head;
		head = head->next;
	}
	else
	{
		for (int i = 0; i < pos - 1; i++)
		{
			pre = pre->next;
		}
		dummy = pre->next;
		pre->next = dummy->next;
	}
	delete dummy;

	if (pos == count - 1)
	{
		tail = pre->next;
	}
	--count;
}

int SinglyLinkedList::LastIndexOf(int num)
{
	Node* cur = head;
	int result = -1;
	for (int i = 0; i < count; i++)
	{
		int val = cur->value;
		if (val == num)
		{
			result = i;
		}
		cur = cur->next;
	}
	return result;
}

void SinglyLinkedList::Reverse()
{
	SinglyLinkedList tmp;
	Reverse(tmp, head);
	*this = tmp;
}

void SinglyLinkedList::PrintReverse()
{
	PrintReverse(head);
}

SinglyLinkedList::~SinglyLinkedList()
{
	Clear();
}

MyVector SinglyLinkedList::GetMyVector() const
{
	MyVector res;
	Node* cur = head;
	int result = -1;
	for (int i = 0; i < count; i++)
	{
		int val = cur->value;
		res.PushBack(val);
		cur = cur->next;
	}
	return res;
}

void SinglyLinkedList::Clear()
{
	Node* cur = head;
	count = 0;
	for (int i = 0; i < count; i++)
	{
		Node* tmp = cur;
		cur = cur->next;
		delete tmp;
	}
	head = tail = nullptr;
}

void SinglyLinkedList::Clone(SinglyLinkedList const& obj)
{
	Node* cur = obj.head;
	for (int i = 0; i < obj.count; i++)
	{
		int val = cur->value;
		this->Add(val);
		cur = cur->next;
	}
}

void SinglyLinkedList::PrintReverse(Node* node)
{
	int val;
	if (node == nullptr)
	{
		std::cout << "\n";
		return;
	}
	else
	{
		val = node->value;
		PrintReverse(node->next);
		std::cout << val << " ";
	}
}

void SinglyLinkedList::Reverse(SinglyLinkedList& obj, Node* node)
{
	int val;
	if (node == nullptr)
	{
		return;
	}
	else
	{
		val = node->value;
		Reverse(obj, node->next);
		obj.Add(val);
	}
}
