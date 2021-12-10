#pragma once
class Fraction
{
private:
	int numerator;
	int denumenator;

public:
	Fraction();
	Fraction(double);
	Fraction(int num, int den);
	void SetNumenator(int num);
	void SetDenumenator(int den);
	int GetNumenator() const;
	int GetDenumenator() const;
	void Print() const;
	double GetDecimal() const;
	void Decris();
	bool Equal(Fraction const&);
	Fraction& Add(Fraction const&);
	Fraction& Dif(Fraction const&);
	Fraction& Product(Fraction const&);
	Fraction& Div(Fraction const&);
};

