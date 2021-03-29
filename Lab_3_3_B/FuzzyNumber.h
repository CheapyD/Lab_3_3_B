#pragma once
#include "Triad.h"

class FuzzyNumber : public Triad
{
public:
	FuzzyNumber();
	FuzzyNumber(double x, double l, double r);
	FuzzyNumber(const FuzzyNumber& v);

	FuzzyNumber& operator --();
	FuzzyNumber& operator ++();
	FuzzyNumber operator --(int);
	FuzzyNumber operator ++(int);

	friend FuzzyNumber operator + (FuzzyNumber a, FuzzyNumber b);
	friend FuzzyNumber operator * (FuzzyNumber a, FuzzyNumber b);
};

