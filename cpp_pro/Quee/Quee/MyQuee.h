#pragma once
struct Node
{
	int val = 0;
	Node* next = nullptr;
	Node* prev = nullptr;
};

class QueeAble abstract
{
public:
	virtual void Push(int value) = 0;
	virtual void Pop() = 0;
	virtual int Peek() const = 0;
	virtual int Back() const = 0;
	virtual int Front() const = 0;
	virtual bool Empty() const = 0;
};

class PrrintAble abstract
{
public:
	virtual void Print() const = 0;
};

class MyQuee
{
private:
	Node* head = nullptr;
	int size = 0;


};

