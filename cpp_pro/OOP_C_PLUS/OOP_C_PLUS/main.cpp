#include "Header.h"
#include "Point.h"
#include "Counter.h"
#include "Fraction.h"
#include "Student.h"

using namespace std;

int main()
{
	//Point demo
	///////////////////////////////////////////////
	/*Point point(7, 4);
	point.Print();
	point.MoveToX(-2).MoveToY(+2);
	point.Print();*/
	///////////////////////////////////////////////
	
	//Counter demo
	///////////////////////////////////////////////
	//Counter c;
	//c.SetStep(3);
	//c.SetMax(99);
	//for (size_t i = 0; i < 40; i++)
	//{
	//	c.Print();
	//	Sleep(600);
	//	system("cls");
	//	c.Increment();
	//	//c.IncrByStep();
	//}
	///////////////////////////////////////////////
	/*Fraction a(1, 2), b(1, 4);
	a.Print();
	a.Add(b);
	a.Print();
	Fraction tmp(5.75);
	tmp.Print();*/
	///////////////////////////////////////////////
	/*Student tmp;
	tmp.SetName("Jury").
		SetFathersName("Igorievich").
		SetSurname("Karataev").
		SetPhone("096-84-20-183").
		SetBirth({2, 8, 1995})
		;
	tmp.Print();
	tmp.WriteExams({ Student::Subjects::CPP, 8 }).
		WriteCourses({ Student::Subjects::CPP, 10 }).
		WriteConditions({ Student::Subjects::UML, 9 })
		;

	cout << tmp.GetPhone() << endl;
	tmp.PrintExams();
	tmp.PrintCurseWorks();
	tmp.PrintConditions();*/
	///////////////////////////////////////////////
	
	///////////////////////////////////////////////
	return 0;
}