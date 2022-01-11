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
	MyVector(MyVector const&);
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
	void PopFront();
	void PopBack();
	void Clear();
	bool IsEmpty() const;
	void TrimToSize();
	int IndexOf(int value);
	int LastIndexOf(int value);
	void Reverse();
	void SortAsc();
	void SortDesc();
	void Shuffle();
	bool Equals(MyVector const& other) const;
	int GetElementAt(int) const;
	////////////////////////////////////
	void Clone(MyVector const& obj);
	int& operator[] (int);
	int operator[] (int) const;
	////////////////////////////////////

private:
	static const int DEFAULT_CAPACITY = 10;
	void EnsureCapacity(int new_capacity);
	static bool SearchInt(int* arr, int sz, int num);
};

