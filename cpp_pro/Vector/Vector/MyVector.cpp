#include "MyVector.h"
#include <iostream>

MyVector::MyVector(int capacity) : capacity(capacity), size(0), ar(new int[capacity])
{
}

MyVector::MyVector() : MyVector(DEFAULT_CAPACITY)
{
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

int& MyVector::operator[](int index)
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
