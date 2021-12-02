#include "Stack.h"

int Stack::quantity = 0;

Stack::Stack()
{
	quantity++;
	this->size = 0;
	this->capacity = 10;
	this->exp_ratio = 2;
	this->buffer = new int[capacity];
}

void Stack::Push(int value)
{
	buffer[size++] = value;
	if (size == capacity)
	{
		Reload();
	}
}

int Stack::Pop()
{                                             
	return buffer[--size];
}

bool Stack::IsEmpty()
{
	return size == 0;
}

void Stack::SetRatio(int k)
{
	exp_ratio = k;
}

int Stack::GetSize() const
{
	return size;
}

int Stack::GetRatio() const
{
	return exp_ratio;
}

int Stack::GetQuantity()
{
	return quantity;
}

Stack::~Stack()
{
	quantity--;
	delete[] this->buffer;
}

void Stack::Reload()
{
	capacity *= exp_ratio;
	int* tmp = new int[capacity];
	for (size_t i = 0; i < size; i++)
	{
		tmp[i] = buffer[i];
	}
	delete[] buffer;
	buffer = tmp;
}
