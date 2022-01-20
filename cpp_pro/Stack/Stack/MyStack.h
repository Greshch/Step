#pragma once
#include"MyVector.h"

class MyStack
{
private:
	MyVector* _buffer = new MyVector(BUFFER_SIZE);

public:
	bool Empty() const;
	void Pop();
	void Push(const int& val);
	int Peek() const;
	int Size() const;
	~MyStack();

private:
	static int const BUFFER_SIZE = 10;
};

