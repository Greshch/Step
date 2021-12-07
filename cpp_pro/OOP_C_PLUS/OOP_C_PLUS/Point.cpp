#include "Point.h"
#include <iostream>
using namespace std;

Point::Point() : Point(0, 0)
{
}

Point::Point(int x, int y)
{
    SetX(x);
    SetY(y);
}

Point& Point::SetX(int x)
{
    _x = x;
    return *this;
}

Point& Point::SetY(int y)
{
    _y = y;
    return *this;
}

int Point::GetX() const
{
    return _x;
}

int Point::GetY() const
{
    return _y;
}

Point& Point::MoveToX(int x)
{
    _x += x;
    return *this;
}

Point& Point::MoveToY(int y)
{
    _y += y;
    return *this;
}

void Point::Print() const
{
    cout << "(x=" << _x << ", y=" << _y << ")" << endl;
}
