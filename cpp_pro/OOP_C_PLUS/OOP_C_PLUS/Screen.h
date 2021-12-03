#pragma once
class Screen
{
private:
	int length;
	int width;
	int frequency;
	char* name;
	int price;
	static const int LEN = 32;

public:
	Screen();
	Screen(int len, int wid, int freq, const char* nam, int pr);
	void SetPrice(int pr);
	int GetLength() const;
	int GetWidth() const;
	int GetFrequency() const;
	char const* GetName() const;
	void Print() const;
	~Screen();
};

