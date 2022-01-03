#pragma once
class String
{
private:
	char* _str;
	unsigned _size;
	unsigned _capacity;
	

public:
	String();
	String(const char* str);
	explicit String(unsigned capacity);
	String(String const&);
	void Print() const;
	void PrintLn() const;
	char GetCharAt(unsigned int index) const;
	void GetLine();
	void ConcatNum(int);
	void Concat(int);
	void Concat(String const &);
	void Concat(char const*);
	void Concat(double);
	const char* GetCharArray() const;
	int CompareTo(String);
	int CompareTo(char*);
	~String();

	
private:
	static const unsigned START_CAPACITY = 2;
	void ReallocNCopy();
	void ReallocNCopy(int sz);
	void Clear();
	String ToString(double d);
	unsigned GetSizeOfNum(unsigned num);
	unsigned GetSizeOfDouble(double d);
	unsigned TruncRightNulls(unsigned num);
};

