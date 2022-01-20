#include "MyStack.h"
#include <iostream>
using namespace std;

bool MyStack::Empty() const
{
    return _buffer->GetSize() == 0;
}

void MyStack::Pop()
{
    if (Empty())
        return;

    _buffer->PopBack();
}

void MyStack::Push(const int& val)
{
    _buffer->PushBack(val);
}

int MyStack::Peek() const
{
    if (Empty())
    {
        throw "Empty stack error!!\n";
    }
    return (*_buffer)[_buffer->GetSize() - 1];
}

int MyStack::Size() const
{
    return _buffer->GetSize();
}

MyStack::~MyStack()
{
    delete _buffer;
}

