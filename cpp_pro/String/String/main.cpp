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
		//String s = "test";
		//s.ConcatNum(123);
		//s.Concat('A');
		//s.PrintLn();
		
		//Test Concat(double)
		/*String s = "test ";
		s.Concat(-123.456);
		s.PrintLn();*/

		// Test IndexOf(char)
		/*String s = "God bless you!";
		s.PrintLn();
		cout << "i -> " << s.IndexOf('i') << endl;
		cout << "o -> " << s.IndexOf('o') << endl;*/

		// Test LastIndexOf(char)
		/*String s = "God bless you!";
		s.PrintLn();
		cout << "i -> " << s.LastIndexOf('i') << endl;
		cout << "o -> " << s.LastIndexOf('o') << endl;*/

		//Test IndexOf(char const*)
		/*String str = "test one two three";
		str.PrintLn();
		cout << str.IndexOf("one") << endl;*/

		//Test Contains(char const*)
		/*String str = "test one two three";
		str.PrintLn();
		cout << str.Contains("one") << endl;*/
		
	}
	catch (char const* exc)
	{
		cout << exc << endl;
	}
	return 0;
}