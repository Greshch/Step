#include "String.h"
#include <iostream>
#include <cstring>
#include <algorithm>
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

String& String::operator=(String obj)
{
	if (this == &obj)
		return *this;
	_capacity = obj._capacity;
	_str = new char[_capacity];
	Clear();

	strcpy_s(_str, _capacity, obj._str);
	return *this;
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

int String::CompareTo(String const& obj)
{
	return strcmp(_str, obj._str);
}

int String::CompareTo(char* str)
{
	return strcmp(str, _str);
}

int String::IndexOf(char ch)
{
	return IndexOf(ch, 0);
}

int String::LastIndexOf(char ch)
{
	int len = strlen(_str) - 1;
	return LastIndexOf(ch, len);
}

int String::LastIndexOf(char ch, int id)
{
	if (id < 0 || id >= strlen(_str))
		return -1;
	for (int i = id; i >= 0; i--)
	{
		if (_str[i] == ch)
			return i;
	}
	return -1;
}

int String::LastIndexOf(String const& obj)
{
	return LastIndexOf(obj._str);
}

int String::LastIndexOf(char const* str)
{
	char ch = str[0];
	int i = strlen(_str) - 1;
	int res = 0;
	while (true)
	{
		i = LastIndexOf(ch, i);
		if (i == -1)
			return -1;
		res = FromIndexContainsStr(str, i);
		if (res)
			return i;
		i--;
	}
}

int String::IndexOf(String const& obj)
{
	return IndexOf(obj._str);
}

int String::IndexOf(char const* str)
{
	char ch = str[0];
	int i = 0;
	int res = 0;
	while (true)
	{
		i = IndexOf(ch, i);
		if (i == -1)
			return -1;
		res = FromIndexContainsStr(str, i);
		if ( res )
			return i;
		i++;
	}
}

int String::IndexOf(char ch, int id)
{
	int len = strlen(_str);
	for (int i = id; i < len; i++)
	{
		if (_str[i] == ch)
			return i;
	}
	return -1;
}


bool String::Contains(String const& obj)
{
	return IndexOf(obj._str) != -1;
}

bool String::EndsWith(String const& s)
{
	return IndexOf(s) == strlen(_str) - strlen(s._str);
}

bool String::StartsWith(String const& s)
{
	return IndexOf(s) == 0;
}

void String::Remove(int index)
{
	int len = strlen(_str);
	if (index < 0 || index >= len)
		return;
	_str[index] = '\0';
}

void String::Remove(int start, int count)
{
	int len = strlen(_str);
	if (start < 0)
		return;

	if (start + count > len)
	{
		Remove(start);
		return;
	}
		

	for (int i = 0; i < count; i++)
	{
		//_str[start + i] = '\0';
		_str[start + i] = ' ';
	}

	len = len - start;
	int i = start;
	for (; i < /*len*/ start + len; i++)
	{
		_str[i] = _str[i + count];
	}
	_str[i] = '\0';
}

void String::Replace(char R, char Z)
{
	using std::cout;
	using std::endl;
	int findR = 0;
	while (true)
	{
		findR = IndexOf(R, findR);
		if (findR == -1)
			break;
		//cout << "#" << R << " -> " << findR << endl;
		_str[findR] = Z;
		++findR;
	}
}

void String::Replace(String const& substr, String const& rep)
{
	using std::cout;
	using std::endl;
	int findR = 0;
	int len = strlen(substr._str);
	while (true)
	{
		findR = IndexOf(substr);
		if (findR == -1)
			break;
		//cout << "# " << findR << endl;
		Remove(findR, len);
		Insert(rep, findR);
		//cout << _str << endl;
	}
}

void String::Insert(char ch, int pos)
{
	int len = strlen(_str);
	if (pos < 0 || pos > len)
		return;
	if (_capacity <= len + 1)
	{
		ReallocNCopy();
	}

	for (int i = len; i > pos; i--)
	{
		_str[i] = _str[i - 1];
	}
	_str[pos] = ch;
	_str[len + 1] = '\0';
}

void String::Insert(char const* str, int pos)
{
	using std::cout;
	using std::endl;
	while (*str)
	{
		Insert(*str++, pos++);
		//str++;
	}
	cout << endl;
}

void String::Insert(String const& s, int pos)
{
	Insert(s._str, pos);
}

String* String::Split(char separator, int& pieces)
{
	using namespace std;
	TrimStart();
	TrimEnd();
	int len = strlen(_str);
	int cnt = 0;
	bool flag = true;
	for (int i = 0; i < len; i++)
	{
		if (_str[i] == separator)
		{
			flag = true;
			//cout << endl;
		}
		else
		{
			if (flag == true)
			{
				//cout << cnt << "." << _str[i] << endl;
				++cnt;
				flag = false;
			}
			else
			{
				//cout << "#" << _str[i];
			}
		}
	}
	//cout << cnt << endl;
	pieces = cnt;
	String* words = new String[cnt];
	flag = true;
	int index = 0;
	for (int i = 0; i < len; i++)
	{
		if (_str[i] == separator)
		{
			flag = true;
			//cout << endl;
		}
		else
		{
			if (flag == true)
			{
				//cout << cnt << "." << _str[i] << endl;
				words[index++] =  "";
				words[index - 1].Concat(_str[i]);
				flag = false;
			}
			else
			{
				//cout << "#" << _str[i];
				words[index - 1].Concat(_str[i]);
			}
		}
	}
	return words;
}

void String::Trim()
{
	TrimStart();
	TrimEnd();
}

void String::TrimStart()
{
	using namespace std;
	char* p = _str;
	bool flag = false;
	char* tmp = new char[strlen(_str) + 1];
	int i = 0;
	while (*p)
	{
		if (*p != ' ' && flag == false)
		{
			flag = true;
		}

		if (flag)
		{
			//cout << *p;
			tmp[i++] = *p;
		}
		
		++p;
	}
	tmp[i] = '\0';
	strcpy_s(_str, strlen(_str) - 1, tmp);
	//delete[] tmp;
}

void String::TrimEnd()
{
	using namespace std;
	char* p = _str + strlen(_str) - 1;
	bool flag = false;
	int i = 0;
	while (*p)
	{
		if (*p != ' ' && flag == false)
		{
			flag = true;
		}

		if (flag)
		{
			//cout << *p;
			break;
		}
		--p;
	}
	++p;
	*p = '\0';
}

void String::Reverse()
{
	int len = strlen(_str);
	for (int i = 0; i < len / 2; i++)
	{
		std::swap(_str[i], _str[len - 1 - i]);
	}
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
	double right = abs(d - left);
	sz = GetSizeOfDouble(right);
	////cout << "\nsz -> " << sz << endl;
	pw = pow(10, sz);
	right *= pw;
	////cout << endl << "right = " << right << endl;
	right = TruncRightNulls(right);
	//cout << endl << "right = " << right << endl;
	s_num.ConcatNum(right);
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

bool String::FromIndexContainsStr(char const* str, int id)
{
	int length = strlen(_str);
	int len_str = strlen(str);
	for (int i = 0; i < len_str; i++)
	{
		if (i + id >= length || _str[i + id] != str[i])
		{
			return false;
		}
	}
	return true;
}
