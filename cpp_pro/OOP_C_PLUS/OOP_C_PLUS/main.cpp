#include <iostream>
#include <Windows.h>
#include "Point.h"
#include "Counter.h"

using namespace std;

int main()
{
	//Point demo
	///////////////////////////////////////////////
	/*Point point(7, 4);
	point.Print();
	point.MoveToX(-2).MoveToY(+2);
	point.Print();*/
	///////////////////////////////////////////////
	
	//Counter demo
	///////////////////////////////////////////////
	Counter c;
	c.SetStep(3);
	c.SetMax(99);
	for (size_t i = 0; i < 40; i++)
	{
		c.Print();
		Sleep(600);
		system("cls");
		c.Increment();
		//c.IncrByStep();
	}
	///////////////////////////////////////////////
	return 0;
}