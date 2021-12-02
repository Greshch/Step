#pragma once
class Stack
{
private:
	int* buffer;
	int size;
	int capacity;
	int exp_ratio;
	static int quantity;

public:
	Stack();
	void Push(int value);
	int Pop();
	bool IsEmpty();
	void SetRatio(int);
	int GetSize() const;
	int GetRatio() const;
	static int GetQuantity();
	~Stack();

private:
	void Reload();
};

