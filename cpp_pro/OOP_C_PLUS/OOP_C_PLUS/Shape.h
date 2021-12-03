#pragma once
class Shape
{
public:
	enum Colors { RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET };

private:

	int height;
	int width;
	int altitude;
	int weight;
	Colors color;


public:

	Shape();
	Shape(int heigh_, int wid_, int altit_, int weigh_, Colors c);
	void Draw() const;
	long GetVolume() const;
	long GetSquare() const;
	void Move();
	void Rotate();
	~Shape();
};

