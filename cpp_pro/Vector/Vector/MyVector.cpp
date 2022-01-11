#include "MyVector.h"
#include <iostream>
#include <algorithm>

MyVector::MyVector(int capacity) : capacity(capacity), size(0), ar(new int[capacity])
{
}

MyVector::MyVector() : MyVector(DEFAULT_CAPACITY)
{
}

MyVector::MyVector(MyVector const& obj)
{
	std::cout << "Copy construct" << std::endl;
	Clone(obj);
}

MyVector::~MyVector()
{
	delete[] ar;
}

int MyVector::GetSize() const
{
	return size;
}

int MyVector::GetCapacity() const
{
	return capacity;
}

void MyVector::Print() const
{
	using namespace std;
	for (int i = 0; i < size; i++)
	{
		cout << ar[i] << " ";
	}
	cout << endl;
}

void MyVector::PushBack(int elem)
{
	EnsureCapacity(size + 1);
	ar[size++] = elem;
}

void MyVector::PushFront(int elem)
{
	EnsureCapacity(size + 1);
	for (int i = size++; i > 0; i--)
	{
		ar[i] = ar[i - 1];
	}
	ar[0] = elem;
}

void MyVector::Insert(int index, int value)
{
	if (index < 0 || index >= capacity)	return;
	EnsureCapacity(size + 1);
	for (int i = size++; i > index; i--)
	{
		ar[i] = ar[i - 1];
	}
	ar[index] = value;
}

void MyVector::RemoveAt(int index)
{
	if (index < 0 || index >= capacity)	return;
	--size;
	for (int i = index; i < size; i++)
	{
		ar[i] = ar[i + 1];
	}
}

void MyVector::Remove(int value)
{
	for (int i = 0; i < size; i++)
	{
		if (ar[i] == value)
		{
			RemoveAt(i);
			--i;
		}
	}
}

void MyVector::PopFront()
{
	RemoveAt(0);
}

void MyVector::PopBack()
{
	RemoveAt(size - 1);
}

void MyVector::Clear()
{
	for (int i = 0; i < size; i++)
	{
		ar[i] = 0;
	}
	size = 0;
}

bool MyVector::IsEmpty() const
{
	return size == 0;
}

void MyVector::TrimToSize()
{
	capacity = size;
	int* buffer = new int[capacity];
	for (int i = 0; i < size; i++)
	{
		buffer[i] = ar[i];
	}
	delete[] ar;
	ar = buffer;
}

int MyVector::IndexOf(int value)
{
	for (int i = 0; i < size; i++)
	{
		if (ar[i] == value)
			return i;
	}
	return -1;
}

int MyVector::LastIndexOf(int value)
{
	for (int i = size - 1; i >= 0; i--)
	{
		if (ar[i] == value)
			return i;
	}
	return -1;
}

void MyVector::Reverse()
{
	for (int i = 0; i < size / 2; i++)
	{
		std::swap(ar[i], ar[size - 1 - i]);
	}
}

void MyVector::SortAsc()
{
	using namespace std;
	sort(ar, ar + size);
}

void MyVector::SortDesc()
{
	SortAsc();
	Reverse();
}

void MyVector::Shuffle()
{
	srand(time(0));
	//Prepare random indexes
	int* indexes = new int[size];
	for (int i = 0; i < size;)
	{
		int cur = rand() % size;
		if (!SearchInt(indexes, size, cur))
		{
			indexes[i++] = cur;
		}
	}
	//Shuffle in its order
	for (int i = 0; i < size; i++)
	{
		std::swap(ar[i], ar[indexes[i]]);
	}
	delete[] indexes;
}

bool MyVector::Equals(MyVector const& other) const
{
	if (size != other.size)	return false;
	for (int i = 0; i < size; i++)
	{
		if (ar[i] != other[i])	return false;
	}
	return true;
}

int MyVector::GetElementAt(int i) const
{
	if (i < 0 || i >= size)	throw "Out of range!";
	return ar[i];
}

void MyVector::Clone(MyVector const& obj)
{
	if (obj.ar != nullptr)	delete[] ar;
	capacity = obj.capacity;
	size = obj.size;
	ar = new int[size];
	for (int i = 0; i < size; i++)
	{
		ar[i] = obj[i];
	}
}

int& MyVector::operator[](int index)
{
	return ar[index];
}

int MyVector::operator[](int index) const
{
	return ar[index];
}

void MyVector::EnsureCapacity(int param)
{
	if (param <= capacity)	return;
	int new_capacity = capacity * 3 / 2 + 1;
	int* buffer = new int[new_capacity];
	for (int i = 0; i < capacity; i++)
	{
		buffer[i] = ar[i];
	}
	delete[] ar;
	ar = buffer;
	capacity = new_capacity;
}

bool MyVector::SearchInt(int* arr, int sz, int num)
{
	for (int i = 0; i < sz; i++)
	{
		if (arr[i] == num)
			return true;
	}
	return false;
}
