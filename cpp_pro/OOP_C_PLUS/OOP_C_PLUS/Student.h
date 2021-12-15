#pragma once
#include "Header.h"

class Student
{
public:
	struct Date
	{
		int day;
		int month;
		int year;
	};

	enum Subjects
	{
		MATH,
		ALGORITHM,
		ENGLISH,
		UML,
		CPP,
		JAVA,
		CSHARP,
		PHP,
		SQL,
		JAVASCRIPT,
		HTML,
		CSS,
		SZ
	};

	struct SubjectsNGrade
	{
		Subjects subject;
		int grade;
	};

private:
	char* _name;
	char* _fathers_name;
	char* _surname;
	char* _phone;
	Date* _date;
	
	SubjectsNGrade* _exams;
	int _pexams;
	SubjectsNGrade* _conditions;
	int _pconditions;
	SubjectsNGrade* _curseworks;
	int _pcurseworks;


	static int const LEN = 64;

public:
	Student();
	Student(char const* name, char const* fathers_name, 
		char const* surname, Date const& date);
	Student(Student const& obj);
	Student& SetName(char const* name);
	string const GetName()const;
	Student& SetSurname(char const* name);
	string const GetSurname()const;
	Student& SetFathersName(char const* name);
	string const GetFathersName()const;
	Student& SetPhone(char const* name);
	string const GetPhone()const;
	Student& SetBirth(int day, int month, int year);                                                                                                                            
	Student& SetBirth(Date const& date);                                                                                                                            
	Date const GetBirth() const;
	Student& WriteExams(SubjectsNGrade const& pair);
	Student& WriteCourses(SubjectsNGrade const& pair);
	Student& WriteConditions(SubjectsNGrade const& pair);

	void Print() const;
	void PrintResults(SubjectsNGrade const* arr, int sz_arr) const;
	void PrintExams() const;
	void PrintConditions() const;
	void PrintCurseWorks() const;
	~Student();

private:
	void Init();
	void AllocateString(char** str);
	void AllocateGrades(SubjectsNGrade** sng);

	void CopyResults(SubjectsNGrade* dest, SubjectsNGrade const* arr_src, int sz_arr);
	void CopyExams(SubjectsNGrade const* arr_src, int sz_arr);
	void CopyCourses(SubjectsNGrade const* arr_src, int sz_arr);
	void CopyConditions(SubjectsNGrade const* arr_src, int sz_arr);
};

