#pragma once
class Person
{
private:
	char* name;
	char* surname;
	int weight;
	int altitude;
	int age;

	static const int LEN = 40;

public:
	Person();
	Person(const char* name_, const char* surname_, int weight_, int altitude_, int age_);
	void IncrAge();
	void PrintPasportDate();
	void PrintApireance();
	void LoseWeight(int kg);
	void GainWeight(int kg);
	void ChangeSurname(const char* name_);
	~Person();
};

