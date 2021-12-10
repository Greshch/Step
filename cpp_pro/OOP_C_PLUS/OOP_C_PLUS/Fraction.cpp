#include "Fraction.h"
#include <iostream>
using namespace std;

Fraction::Fraction() : Fraction(1, 1)
{
}

Fraction::Fraction(double d)
{
	int left = (int) d;
	double right = d - left;
	int const acuracy = 100;
	SetNumenator(left * acuracy + right * acuracy);
	SetDenumenator(acuracy);
	Decris();
}

Fraction::Fraction(int num, int den)
{
	SetNumenator(num);
	SetDenumenator(den);
}

void Fraction::SetNumenator(int num)
{
	numerator = num;
}

void Fraction::SetDenumenator(int den)
{
	if (den == 0)
	{
		throw "Div by zero\n";
	}
	denumenator = den;
}

int Fraction::GetNumenator() const
{
	return numerator;
}

int Fraction::GetDenumenator() const
{
	return denumenator;
}

void Fraction::Print() const
{
	cout << numerator << " / " << denumenator << endl;
}

double Fraction::GetDecimal() const
{
	if (denumenator == 0)
	{
		throw "Div by zero.\n";
	}
	return 1.0 * numerator / denumenator;
}

void Fraction::Decris()
{
	int min = numerator < denumenator ? numerator : denumenator;
	
	for (int  i = min; i >= 2; i--)
	{
		if (numerator % i == 0 && denumenator % i == 0)
		{
			numerator /= i;
			denumenator /= i;
		}
	}
}

bool Fraction::Equal(Fraction const& obj)
{
	return numerator == obj.numerator && denumenator == obj.denumenator
	||
	1.0 * numerator / obj.numerator == 1.0 * denumenator / obj.denumenator;
}

Fraction& Fraction::Add(Fraction const& obj)
{
	int common_denum = denumenator * obj.denumenator;
	numerator = numerator * common_denum / denumenator +
		obj.numerator * common_denum / obj.denumenator;
	denumenator = common_denum;
	Decris();
	return *this;
}

Fraction& Fraction::Dif(Fraction const& obj)
{
	int common_denum = denumenator * obj.denumenator;
	numerator = numerator * common_denum / denumenator -
		obj.numerator * common_denum / obj.denumenator;
	denumenator = common_denum;
	Decris();
	return *this;
}

Fraction& Fraction::Product(Fraction const& obj)
{
	numerator *= obj.numerator;
	denumenator *= obj.denumenator;
	Decris();
	return *this;
}

Fraction& Fraction::Div(Fraction const& obj)
{
	numerator /= obj.numerator;
	denumenator /= obj.denumenator;
	Decris();
	return *this;
}

