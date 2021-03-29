#include "FuzzyNumber.h"

FuzzyNumber::FuzzyNumber()
	: Triad(0, 0, 0)
{}

FuzzyNumber::FuzzyNumber(double X = 0, double L = 0, double R = 0)
{
	if (X > (X - L) && (X + R) > X)
	{
		SetX(X);
		SetL(L);
		SetR(R);
	}
	else
	{
		SetX(0);
		SetL(0);
		SetR(0);
	}
}

FuzzyNumber::FuzzyNumber(const FuzzyNumber& v)
	: Triad(v)
{}

FuzzyNumber& FuzzyNumber::operator --()
{
	this->SetX(this->GetX() - 1);
	return *this;
}

FuzzyNumber& FuzzyNumber::operator ++()
{
	this->SetX(this->GetX() + 1);
	return *this;
}

FuzzyNumber FuzzyNumber::operator --(int)
{
	FuzzyNumber a(*this);
	this->SetR(this->GetR() - 1);
	return a;
}

FuzzyNumber FuzzyNumber::operator ++(int)
{
	FuzzyNumber a(*this);
	this->SetR(this->GetR() + 1);
	return a;
}

FuzzyNumber operator + (FuzzyNumber a, FuzzyNumber b)
{
	FuzzyNumber T(0, 0, 0);
	T.SetX(a.GetX() + b.GetX());
	T.SetL(a.GetX() + b.GetX() - a.GetL() - b.GetL());
	T.SetR(a.GetX() + b.GetX() + a.GetR() + b.GetR());
	return T;
}

FuzzyNumber operator * (FuzzyNumber a, FuzzyNumber b)
{
	FuzzyNumber N(0, 0, 0);
	N.SetX(a.GetX() * b.GetX());
	N.SetL(a.GetX() * b.GetX() - b.GetX() * a.GetL() - a.GetX() * b.GetL() - a.GetL() * b.GetL());
	N.SetR(a.GetX() * b.GetX() + b.GetX() * a.GetR() + a.GetX() * b.GetR() + a.GetR() * b.GetR());
	return N;
}
