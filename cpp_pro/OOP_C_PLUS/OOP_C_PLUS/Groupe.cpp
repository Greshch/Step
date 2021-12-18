#include "Groupe.h"
#include <algorithm>
using namespace std;

Groupe::Groupe()
{
}

Groupe::Groupe(unsigned num)
{
	Init(num);
}

void Groupe::ShowStudents() const
{
	cout << "name of group:\t" << GetName() << endl;
	cout << "special of group:\t" << GetSpecial() << endl;
	unsigned sz = GetCurNumStudents();
	for (size_t i = 0; i < sz; i++)
	{
		cout << i + 1 << ") ";
		_students[i].Print();
	}
}

Groupe::Groupe(Groupe const& obj)
{
}

void Groupe::SetNumStudents(unsigned num)
{
	if (num > MAX_SZ)
	{
		throw "Too much size of groupe\n";
	}
	_num_of_students = num;
}

void Groupe::SortByNames()
{
	sort(_students, _students + _p_student,
		[](Student const& a, Student const& b)
		{
			return a.GetName() < b.GetName();
		}
	);
}

string const Groupe::GetName() const
{
	return _name_of_groupe;
}

unsigned Groupe::GetCurNumStudents() const
{
	return _p_student;
}

string const Groupe::GetSpecial() const
{
	return _special;
}

void Groupe::TransferStudent(unsigned id_student, Groupe& from, Groupe& to)
{

}

void Groupe::AddStudentToGroup(Student const& student)
{
	if (_p_student >= MAX_SZ)
	{
		throw "Too much people in one group!\n";
	}
	else if (_p_student == DEFAULT_SZ)
	{
		_num_of_students = MAX_SZ;
		Student* tmp = new Student[_num_of_students];
		for (size_t i = 0; i < _p_student; i++)
		{
			tmp[i] = _students[i];
		}
		delete[] _students;
		_students = tmp;
	}
	_students[_p_student++] = student;
}

void Groupe::MergeGroups(Groupe& other)
{
}

unsigned Groupe::GetNumStudents() const
{
	return _num_of_students;
}

void Groupe::ExileStudents()
{
}

Groupe::~Groupe()
{
	delete[] _name_of_groupe;
	delete[] _special;
	delete[] _students;
}

void Groupe::AllocateString()
{
	_name_of_groupe = new char[LEN_STR];
	_special = new char[LEN_STR];
}

void Groupe::Init(unsigned num_students)
{
	AllocateString();
	SetNumStudents(num_students);
	_students = new Student[_num_of_students];
}
