#include "Shape.h"
#include <iostream>
using namespace std;



Shape::Shape()
{
	width = 0;
	height = 0;
	altitude = 0;
	weight = 0;
	color = GREEN;
}

Shape::Shape(int heigh_, int wid_, int altit_, int weigh_, Colors c)
{
	height = heigh_;
	width = wid_;
	altitude = altit_;
	weight = weigh_;
}

void Shape::Draw() const
{
	cout << "Draw\n";
}

long Shape::GetVolume() const
{
	return width * height * altitude;
}

long Shape::GetSquare() const
{
	return width * height;
}

void Shape::Move()
{
	cout << "Move\n";
}

void Shape::Rotate()
{
	cout << "Rotate\n";
}

Shape::~Shape()
{
}
