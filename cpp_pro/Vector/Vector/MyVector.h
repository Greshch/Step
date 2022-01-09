#pragma once
class MyVector
{
private:
	int* ar;
	int size;
	int capacity;

public:
	////////////////////////////////////
	MyVector(int capacity);
	MyVector();
	~MyVector();
	////////////////////////////////////
	int GetSize() const;
	int GetCapacity() const;
	void Print() const;
	////////////////////////////////////
	void PushBack(int);
	void PushFront(int);
	void Insert(int index, int value);
	void RemoveAt(int index);
	void Remove(int value);
	////////////////////////////////////
	int& operator[] (int);
	////////////////////////////////////

private:
	static const int DEFAULT_CAPACITY = 10;
	void EnsureCapacity(int new_capacity);
};

