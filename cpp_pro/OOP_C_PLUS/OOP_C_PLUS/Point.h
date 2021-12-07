#pragma once
class Point
{
private:
	int _x;
	int _y;

public:
	Point();
	Point(int x, int y);
	Point& SetX(int x);
	Point& SetY(int y);
	int GetX() const;
	int GetY() const;
	Point& MoveToX(int x);
	Point& MoveToY(int y);
	void Print() const;
};

