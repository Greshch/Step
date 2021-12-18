#pragma 
#include "Student.h"

class Groupe
{
private:
	Student* _students;
	int _num_of_students;
	int _p_student;
	char* _name_of_groupe;
	char* _special;
	int _num_of_course;
	static unsigned const LEN_STR = 32;
	static unsigned const DEFAULT_SZ = 20;
	static unsigned const MAX_SZ = 50;

public:
	Groupe();
	Groupe(unsigned num);
	void SetNumStudents(unsigned num);
	unsigned GetNumStudents() const;
	unsigned GetCurNumStudents() const;
	string const GetName() const;
	string const GetSpecial() const;
	Groupe(Groupe const& obj);
	void ShowStudents() const;
	void AddStudentToGroup(Student const& student);
	void MergeGroups(Groupe& other);
	void SortByNames();
	static void TransferStudent(unsigned id_student, Groupe& from, Groupe& to);
	void ExileStudents();
	void BunishmentTheWorstStudent();
	~Groupe();

private:
	void AllocateString();
	void Init(unsigned num_studens);
};

