#include "Student.h"

Student::Student() : 
	Student("no_name", "no_father", "no_surname", {1,1,1})
{
}

Student::Student(char const* name, char const* fathers_name, char const* surname, Date const& date)
{
	Init();
	SetName(name);
	SetFathersName(fathers_name);
	SetSurname(surname);
	SetBirth(date);
}

Student::Student(Student const& obj)
{
	Init();
	SetName(obj._name);
	SetFathersName(obj._fathers_name);
	SetSurname(obj._surname);
	SetBirth({obj._date->day, obj._date->month, obj._date->year});
	CopyConditions(obj._conditions, obj._pconditions);
}

Student& Student::SetName(char const* name)
{
	strcpy_s(_name, LEN - 1, name);
	return *this;
}

string const Student::GetName() const
{
	return _name;
}

Student& Student::SetSurname(char const* surname)
{
	strcpy_s(_surname, LEN - 1, surname);
	return *this;
}

string const Student::GetSurname() const
{
	return _surname;
}

Student& Student::SetFathersName(char const* name)
{
	strcpy_s(_fathers_name, LEN - 1, name);
	return *this;
}

string const Student::GetFathersName() const
{
	return _fathers_name;
}

Student& Student::SetPhone(char const* phone)
{
	for (size_t i = 0; i < strlen(phone); i++)
	{
		if (!isdigit(phone[i]) && phone[i] != '-' && phone[i] != ' ')
		{
			throw "Bad phone number\n";
		}
	}
	strcpy_s(_phone, LEN - 1, phone);
	return *this;
}

string const Student::GetPhone() const
{
	return _phone;
}

Student& Student::SetBirth(int day, int month, int year)
{
	if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1)
	{
		throw "Bad date\n";
	}
	_date->day = day;
	_date->month = month;
	_date->year = year;
	return *this;
}

Student& Student::SetBirth(Date const& date)
{
	SetBirth(date.day, date.month, date.year);
	return *this;
}

Student::Date const Student::GetBirth() const
{
	return {_date->day, _date->month, _date->year};
}

Student& Student::WriteExams(SubjectsNGrade const& pair)
{
	_exams[_pexams++] = pair;
	return *this;
}

Student& Student::WriteCourses(SubjectsNGrade const& pair)
{
	_curseworks[_pcurseworks++] = pair;
	return *this;
}

Student& Student::WriteConditions(SubjectsNGrade const& pair)
{
	_conditions[_pconditions++] = pair;
	return *this;
}

void Student::Print() const
{
	cout << _name << " " << _fathers_name << " " << _surname
		<< "{ " << _date->day << ", " << _date->month << ", " << _date->year << "}\n";
}

void Student::PrintResults(SubjectsNGrade const* arr, int sz_arr) const
{
	for (size_t i = 0; i < sz_arr; i++)
	{
		switch (arr[i].subject)
		{
		case MATH:
			cout << "math -> " << arr[i].grade;
			break;

		case ALGORITHM:
			cout << "algorithm -> "; 
			break;
		
		case ENGLISH:
			cout << "english -> "; 
			break;
		
		case UML:
			cout << "uml -> "; 
			break;

		case CPP:
			cout << "C++ -> "; 
			break;

		case JAVA:
			cout << "Java -> "; 
			break;

		case CSHARP:
			cout << "C# -> "; 
			break;

		case PHP:
			cout << "PHP -> ";
			break;

		case SQL:
			cout << "SQL -> ";
			break;

		case JAVASCRIPT:
			cout << "JavaScript -> ";
			break;

		case HTML:
			cout << "HTML -> ";
			break;

		case CSS:
			cout << "CSS -> ";
			break;

		default:
			break;
		}
		cout << "\t\t" << arr[i].grade << endl;
	}
}

void Student::PrintExams() const
{
	cout << "\tExams\n";
	PrintResults(_exams, _pexams);
}

void Student::PrintConditions() const
{
	cout << "\tConditions\n";
	PrintResults(_conditions, _pconditions);
}

void Student::PrintCurseWorks() const
{
	cout << "\tCourse works\n";
	PrintResults(_curseworks, _pcurseworks);
}

void Student::CopyResults(SubjectsNGrade* dest, SubjectsNGrade const* src, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		dest[i] = src[i];
	}
}

void Student::CopyConditions(SubjectsNGrade const* arr_src, int sz_arr)
{
	CopyResults(_conditions, arr_src, sz_arr);
	_pconditions = sz_arr;
}

void Student::CopyExams(SubjectsNGrade const* arr_src, int sz_arr)
{
	CopyResults(_exams, arr_src, sz_arr);
	_pexams = sz_arr;
}

void Student::CopyCourses(SubjectsNGrade const* arr_src, int sz_arr)
{
	CopyResults(_curseworks, arr_src, sz_arr);
	_pcurseworks = sz_arr;
}

Student::~Student()
{
	delete[] _name;
	delete[] _fathers_name;
	delete[] _surname;
	delete[] _phone;
	delete _date;
	delete[] _exams;
	delete[] _conditions;
	delete[] _curseworks;
}

void Student::Init()
{
	AllocateString(&_name);
	AllocateString(&_fathers_name);
	AllocateString(&_surname);
	AllocateString(&_phone);
	_date = new Date;

	_pexams = 0;
	_pconditions = 0;
	_pcurseworks = 0;
	AllocateGrades(&_exams);
	AllocateGrades(&_conditions);
	AllocateGrades(&_curseworks);
}

void Student::AllocateString(char** str)
{
	*str = new char[LEN];
}

void Student::AllocateGrades(SubjectsNGrade** sng)
{
	*sng = new SubjectsNGrade[SZ];
}
