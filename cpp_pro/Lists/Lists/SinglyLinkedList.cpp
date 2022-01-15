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

bool SinglyLinkedList::Contains(int elem)
{
	Node* cur = head;
	for (int i = 0; i < count; i++)
	{
		int val = cur->value;
		if (val == elem)
		{
			return true;
		}
		cur = cur->next;
	}
	return false;
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

void SinglyLinkedList::SetAt(int index, int val)
{
	if (index < 0 || index >= count)	return;
	Node* cur = head;
	for (int i = 0; true; i++)
	{
		if (i == index)
		{
			cur->value = val;
			break;
		}
		cur = cur->next;
	}
}

SinglyLinkedList::~SinglyLinkedList()
{
	Clear();
}

void SinglyLinkedList::SortAsc()
{
	MyVector vec = GetMyVector();
	vec.SortAsc();
	//vec.Print();
	Clear();
	FillFromMyVector(vec);
}

void SinglyLinkedList::SortDesc()
{
	MyVector vec = GetMyVector();
	vec.SortDesc();
	//vec.Print();
	Clear();
	FillFromMyVector(vec);
}

void SinglyLinkedList::Shuffle()
{
	MyVector vec = GetMyVector();
	vec.Shuffle();
	//vec.Print();
	Clear();
	FillFromMyVector(vec);
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

void SinglyLinkedList::MergeWith(SinglyLinkedList const& obj)
{
	tail->next = obj.head;
	count += obj.count;
	tail = obj.tail;
}

void SinglyLinkedList::FillFromMyVector(MyVector const& obj)
{
	int sz = obj.GetSize();
	for (int i = 0; i < sz; i++)
	{
		Add(obj[i]);
	}
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

bool SinglyLinkedList::Equals(SinglyLinkedList const& obj) const
{
	if (count != obj.count)	return false;
	Node* cur = head;
	Node* cur_obj = obj.head;
	for (int i = 0; i < count; i++)
	{
		if (cur->value != cur_obj->value)
		{
			return false;
		}
		cur = cur->next;
		cur_obj = cur_obj->next;
	}
	return true;
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
