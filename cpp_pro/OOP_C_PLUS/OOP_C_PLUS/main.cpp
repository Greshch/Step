#include <iostream>
#include "Stack.h"
#include "Book.h"
#include "Screen.h"
#include "Shape.h"
#include "Person.h"

using namespace std;

int main()
{
	//////////////////////////////////////////
	/*Stack stack;
	for (size_t i = 0; i < 5; i++)
	{
		stack.Push(i + 1);
	}

	while (!stack.IsEmpty())
	{
		cout << stack.Pop() << endl;
	}*/
	//////////////////////////////////////////
	
	//////////////////////////////////////////
	/*Book some_book("title", "author", "ganre", 100, 300);
	Book kobzar("Kobzar", "Taras Shevchenko", "poems", 320, 250);
	some_book.Print();
	kobzar.Print();*/
	//////////////////////////////////////////
	/*Screen samsung(640, 480, 70, "samsung screen", 1200);
	Screen lg;
	samsung.Print();
	lg.Print();*/
	//////////////////////////////////////////
	/*Shape shape1(10, 25, 5, 100, Shape::Colors::RED);
	Shape shape2(12, 20, 15, 250, Shape::Colors::BLUE);
	cout << shape1.GetVolume() << endl;
	cout << shape2.GetVolume() << endl;*/
	//////////////////////////////////////////
	Person vasyl("Vasyl", "Poterijko", 120, 200, 32);
	Person masha("Maria", "Dudka", 82, 186, 28);
	vasyl.PrintPasportDate();
	vasyl.PrintApireance();

	masha.PrintPasportDate();
	masha.PrintApireance();
	return 0;
}
