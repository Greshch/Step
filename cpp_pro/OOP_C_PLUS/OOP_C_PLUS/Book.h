#pragma once
class Book
{
private:
	char* title;
	char* author;
	char* ganre;
	int pages;
	double price;

public:
	Book();
	Book(char const* title_, char const* author_,
		char const* ganre_, double price_, int pages_);
	char const* GetTitle() const;
	char const* GetAuthor() const;
	char const* GetGanre() const;
	int  GetPages(char const*);
	void SetTitle(char const*);
	void SetAuthor(char const*);
	void SetGanre(char const*);
	void SetPages(int);
	void SetPrice(double dollars);
	void Print() const;
	~Book();

private:
	int const LEN = 40;
	void Init();
};

