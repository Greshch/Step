#include "Book.h"
#include <cstring>
#include <iostream>
using namespace std;

Book::Book()
{
    Init();
}

Book::Book(char const* title_, char const* author_, char const* ganre_, double price_, int pages_)
{
    Init();
    SetTitle(title_);
    SetAuthor(author_);
    SetGanre(ganre_);
    SetPrice(price_);
    SetPages(pages_);
}

char const* Book::GetTitle() const
{
    return title;
}

char const* Book::GetAuthor() const
{
    return author;
}

char const* Book::GetGanre() const
{
    return ganre;
}

int Book::GetPages(char const*)
{
    return pages;
}

void Book::SetTitle(char const* title_)
{
    strcpy_s(this->title, LEN, title_);
}

void Book::SetAuthor(char const* author_)
{
    strcpy_s(this->author, LEN, author_);
}

void Book::SetGanre(char const* ganre_)
{
    strcpy_s(this->ganre, LEN, ganre_);
}

void Book::SetPages(int pages_)
{
    pages = pages_;
}

void Book::SetPrice(double dollars)
{
    price = dollars;
}

void Book::Print() const
{
    cout << "title: " << title
        << ", author: " << author
        << ", ganre: " << ganre
        << ", price: " << price
        << ", pages: " << pages
        << endl;
}

Book::~Book()
{
    delete[] title;
    delete[] author;
    delete[] ganre;
}

void Book::Init()
{
    title = new char[LEN];
    author = new char[LEN];
    ganre = new char[LEN];
}
