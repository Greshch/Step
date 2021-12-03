#include "Person.h"
#include <cstring>
#include <iostream>
using namespace std;

Person::~Person()
{
	delete[] name;
	delete[] surname;
}

Person::Person()
{
	name = new char[LEN];
	surname = new char[LEN];
	const char* none = "NONE";
	strcpy_s(name, strlen(none) + 1, none);
	strcpy_s(surname, strlen(none) + 1, none);
	weight = 0;
	altitude = 0;
	age = 0;
}

Person::Person(const char* name_, const char* surname_, int weight_, int altitude_, int age_)
{
	name = new char[LEN];
	surname = new char[LEN];
	strcpy_s(name, strlen(name_) + 1, name_);
	strcpy_s(surname, strlen(name_) + 1, name_);
	weight = weight_;
	altitude = altitude_;
	age = age_;
}

void Person::IncrAge()
{
	++age;
}

void Person::PrintPasportDate()
{
	cout << "name: " << name << ", surname: " << surname << ", age=" << age << endl;
}

void Person::PrintApireance()
{
	cout << "altitude = " << altitude << ", weight = " << weight << endl;
}

void Person::LoseWeight(int kg)
{
	weight -= kg;
}

void Person::GainWeight(int kg)
{
	weight += kg;
}

void Person::ChangeSurname(const char* surname_)
{
	strcpy_s(surname, strlen(surname_) + 1, surname_);
}
