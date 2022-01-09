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

		//Test LastIndexOf(char)
		/*String str = "test one two three";
		str.PrintLn();
		cout << str.LastIndexOf('t') << endl;*/
		
		//Test LastIndexOf(char const*)
		/*String str = "one two zero";
		str.PrintLn();
		cout << str.LastIndexOf("one") << endl;*/

		// Test Remove(int)
		/*String str = "one two zero";
		str.PrintLn();
		str.Remove(5);
		str.PrintLn();*/

		// Test Remove(int, int)
		/*String str = "onetwozero";
		str.PrintLn();
		str.Remove(2, 5);
		str.PrintLn();*/

		// Test Replace(int R, int Z)
		/*String str = "onetwozero";
		str.PrintLn();
		str.Replace('e', '#');
		str.PrintLn();*/

		// Test Replace(String const& substr, String const& rep)
		/*String str = "onetwozerofouroneend";
		str.PrintLn();
		str.Replace("one", "test");
		str.PrintLn();*/

		//Test insert(char, int)
		/*String str = "abc";
		str.PrintLn();
		str.Insert('X', 1);
		str.Insert('X', 1);
		str.Insert('X', 1);
		str.Insert('L', 1);
		str.PrintLn();*/

		//Test insert(char const*, int);
		/*String str = "abc";
		str.Insert("12", 2);
		str.PrintLn();*/

		//Test StartsWith & EndWith
		/*String str = "onetwothree";
		str.PrintLn();
		cout << str.StartsWith("one") << endl;
		cout << str.EndsWith("three");*/

		//Test Split
		/*String str = "    hello,world,test,xyz  ";
		int sz = 0;
		str.PrintLn();
		String* words = str.Split(',', sz);
		for (int i = 0; i < sz; i++)
		{
			words[i].PrintLn();
		}
		delete[] words;*/

		//Test reverse
		/*String str = "abcdefg";
		str.PrintLn();
		str.Reverse();
		str.PrintLn();*/
	}
	catch (char const* exc)
	{
		cout << exc << endl;
	}
	return 0;
}