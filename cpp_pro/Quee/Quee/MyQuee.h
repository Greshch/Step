#pragma once
struct Node
{
	int val = 0;
	Node* next = nullptr;
};

struct PrNode
{
	int val = 0;
	int prio = 0;
	PrNode* prev = nullptr;
	PrNode* next = nullptr;
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

class PrintAble abstract
{
public:
	virtual void Print() const = 0;
};

class MyQuee : public PrintAble, public QueeAble
{
protected:
	Node* head = nullptr;
	Node* tail = nullptr;
	int size = 0;

public:
	virtual bool Empty() const override;
	virtual void Push(int value) override;
	virtual int Front() const override;
	virtual int Back() const override;
	virtual int Peek() const override;
	virtual void Pop() override;

	virtual void Print() const override;

	virtual ~MyQuee();
	virtual void Clear();
};

class PrQuee : public PrintAble, public QueeAble
{
private:
	PrNode* head = nullptr;
	PrNode* tail = nullptr;
	int size = 0;

public:
	virtual bool Empty() const override;
	virtual void Push(int value) override;
	void Push(int pri, int value);
	virtual int Front() const override;
	virtual int Back() const override;
	virtual int Peek() const override;
	virtual void Pop() override;

	virtual void Print() const override;

	virtual ~PrQuee();
	virtual void Clear();
};

