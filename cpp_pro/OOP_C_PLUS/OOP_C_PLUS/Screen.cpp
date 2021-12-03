#include "Screen.h"
#include <cstring>
#include <iostream>
using namespace std;



Screen::Screen()
{
	length = 0;
	width = 0;
	frequency = 0;
	price = 0;
	char const* no_name = "No_name";
	name = new char[LEN];
	strcpy_s(name, strlen(no_name) + 1, no_name);
}

Screen::Screen(int len, int wid, int freq, const char* nam, int pr)
{
	length = len;
	width = wid;
	frequency = freq;
	price = pr;
	name = new char[LEN];
	strcpy_s(name, strlen(nam) + 1, nam);
}

void Screen::SetPrice(int pr)
{
	price = pr;
}

int Screen::GetLength() const
{
	return length;
}

int Screen::GetWidth() const
{
	return width;
}

int Screen::GetFrequency() const
{
	return frequency;
}

char const* Screen::GetName() const
{
	return name;
}

void Screen::Print() const
{
	cout << "name: " << name << ", width=" << width
		<< "px, length=" << length
		<< "px, frequency=" << frequency
		<< "hz, price=" << price << "$"
		<< endl;

}

Screen::~Screen()
{
	delete[] name;
}
