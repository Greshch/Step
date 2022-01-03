#include <iostream>
#include "String.h"

int main()
{
	using namespace std;
	try
	{
		//String str = "test string";
		//String str2 = " go went gone";
		//String str = (String)4;
		//str.PrintLn();
		//str.GetLine();
		/*str.Concat('E');
		str.Concat('l');
		str.Concat('e');
		str.Concat('p');
		str.Concat('h');
		str.Concat('a');
		str.Concat('n');
		str.Concat('t');*/
		//cout << str.GetCharAt(-1) << endl;
		//str.PrintLn();
		//str.Concat(" one two");
		//str.Concat(str2);
		//str.PrintLn();

		/*String s;
		s.PrintLn();
		s.Concat(-123.456);
		s.PrintLn();*/

		//String s = (String) (2);
		String s = "test";
		//s.ConcatNum(123);
		s.Concat('A');
		s.PrintLn();
	}
	catch (char const* exc)
	{
		cout << exc << endl;
	}
	return 0;
}