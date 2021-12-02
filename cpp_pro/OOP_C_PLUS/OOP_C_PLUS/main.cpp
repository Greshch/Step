#include <iostream>
#include "Stack.h"
#include "Book.h"

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
	Book some_book("title", "author", "ganre", 100, 300);
	some_book.Print();
	//////////////////////////////////////////


	return 0;
}
