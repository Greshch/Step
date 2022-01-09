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
	String& operator= (String);
	//////////////////////////////////////
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
	int CompareTo(String const&);
	int CompareTo(char*);
	///////////////////////////////////
	int IndexOf(char);
	int IndexOf(char, int);
	int LastIndexOf(char);
	int LastIndexOf(char, int);
	int LastIndexOf(String const&);
	int LastIndexOf(char const*);
	int IndexOf(String const&);
	int IndexOf(char const*);
	bool Contains(String const&);
	///////////////////////////////////
	bool EndsWith(String const&);
	bool StartsWith(String const&);
	///////////////////////////////////
	void Remove(int);
	void Remove(int start, int count);
	///////////////////////////////////
	void Replace(char R, char Z); 
	void Replace(String const& substr, String const& rep);
	void Insert(char , int);
	void Insert(char const*, int);
	void Insert(String const&, int);
	///////////////////////////////////
	String* Split(char separator, int& pieces);
	void Trim();
	void TrimStart();
	void TrimEnd();
	///////////////////////////////////
	void Reverse();
	void SortAZ();
	void SortZA();
	///////////////////////////////////
	void Shuffle();
	void RandomFill();
	///////////////////////////////////
	~String();

	
private:
	static const unsigned START_CAPACITY = 16;
	void ReallocNCopy();
	void ReallocNCopy(int sz);
	void Clear();
	String ToString(double d);
	unsigned GetSizeOfNum(unsigned num);
	unsigned GetSizeOfDouble(double d);
	unsigned TruncRightNulls(unsigned num);
	bool FromIndexContainsStr(char const*, int);
	bool SearchInt(int*, int, int);
};

