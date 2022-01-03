#include "String.h"
#include <iostream>
#include <cstring>
#include <cmath>

String::String(unsigned capacity)
{
	_capacity = capacity;
	_str = new char[_capacity];
	Clear();
}

String::String(String const& obj) : String(obj.GetCharArray())
{
	
}

String::String(const char* str) : String(strlen(str) + 1)
{
	strcpy_s(_str, _capacity, str);
}
String::String() : String(START_CAPACITY)
{

}

void String::Print() const
{
	using std::cout;
	cout << _str;
}

void String::PrintLn() const
{
	using std::cout;
	using std::endl;
	Print();
	cout << endl;
}

char String::GetCharAt(unsigned int index) const
{
	if (index < 0 || index > strlen(_str))
	{
		throw "Bad index exception\n";
	}
	return _str[index];
}

void String::GetLine()
{
	using std::cout;
	int ch;
	int i = 0;
	while ((ch = getchar()) != EOF && ch != '\n')
	{
		if (i == _capacity - 1)
		{
			ReallocNCopy();
		}
		_str[i++] = ch;
		_str[i] = '\0';
	}
}

void String::ConcatNum(int num)
{
	/*
	* String s = "test"
	* ConcatNum(123) ..test123 
	*/
	using namespace std;
	char str[100];
	_itoa_s(num, str, 10);
	//cout << "# " << str << endl;
	int sz = strlen(str) + strlen(_str);
	if (sz >= _capacity - 1)
	{
		ReallocNCopy(sz + 10);
	}
	Concat(str);
}

void String::Concat(int ch)
{
	/*
	* String s = "test"
	* ConcatNum('A) ..testA 
	*/
	using namespace std;
	int index = strlen(_str);
	if (index >= _capacity - 1)
	{
		ReallocNCopy(index + 10);
	}
	_str[index++] = ch;
	_str[index] = '\0';
}

void String::Concat(String const& s)
{
	Concat(s.GetCharArray());
}

void String::Concat(char const* s)
{
	unsigned len = strlen(s) + strlen(_str);
	if (_capacity <= len)
	{
		ReallocNCopy(len + 10);
	}
	strcat_s(_str, _capacity - 1, s);
}

void String::Concat(double d)
{
	String d_str = ToString(d);
	Concat(d_str);
}

const char* String::GetCharArray() const
{
	return _str;
}

int String::CompareTo(String s)
{
	return CompareTo(s._str);
}

int String::CompareTo(char* str)
{
	return strcmp(str, _str);
}

String::~String()
{
	if (_str != nullptr)
		delete[] _str;
}

void String::ReallocNCopy()
{
	_capacity = _capacity * 3 / 2 + 1;
	char* tmp = new char[_capacity];
	strcpy_s(tmp, _capacity - 1, _str);
	delete[] _str;
	_str = tmp;
}

void String::ReallocNCopy(int sz)
{
	_capacity = sz;
	char* tmp = new char[_capacity];
	strcpy_s(tmp, _capacity - 1, _str);
	delete[] _str;
	_str = tmp;
}

void String::Clear()
{
	for (size_t i = 0; i < _capacity; i++)
	{
		_str[i] = '\0';
	}
}

String String::ToString(double d)
{
	/*
	write result in s_num
	*/
	using namespace std;
	int left = (int) d;
	int tmp = left;
	//cout << "left -> " << left << endl;
	String s_num;
	if (tmp < 0)
	{
		tmp = -tmp;
		s_num.Concat('-');
	}
	unsigned sz = GetSizeOfNum(tmp);
	
	int pw = pow(10, sz - 1);
	
	for (size_t i = 0; i < sz; i++)
	{
		s_num.Concat('0' + (tmp / pw));
		tmp %= pw;
		pw /= 10;
	}

	s_num.Concat('.');

	//// write double part
	//double right = abs(d - left);
	//sz = GetSizeOfDouble(right);
	////cout << "\nsz -> " << sz << endl;
	//pw = pow(10, sz);
	//right *= pw;
	////cout << endl << "right = " << right << endl;
	//right = TruncRightNulls(right);
	//cout << endl << "right = " << right << endl;
	return s_num;
}

unsigned String::GetSizeOfNum(unsigned num)
{
	unsigned sz = 0;
	while (num)
	{
		num /= 10;
		++sz;
	}
	return sz;
}

unsigned String::GetSizeOfDouble(double d)
{
	/*
	* You ought to put nums less then 1!
	* Obviously this method return excess result
	*/
	unsigned size = 0;
	double mirror = 1.0 - d;
	int const precision = 2;
	int concurency = 0;
	while (true)
	{
		++size;
		d *= 10;
		mirror *= 10;
		int int_d = (int) d;
		int int_m = (int) mirror;
		//std::cout << int_d << "\t" << int_m << std::endl;
		if (int_d == 0 && int_m == 9)
		{
			concurency++;
		}
		if (int_d - int_m == 0 || concurency == precision) break;
		d -= int_d;
		mirror -= int_m;
	}
	return size;
}

unsigned String::TruncRightNulls(unsigned num)
{
	while (true)
	{
		if (num % 10 == 0)
		{
			num /= 10;
		}
		else
		{
			break;
		}
	}
	return num;
}
