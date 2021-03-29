#pragma once
#pragma pack(1)
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Triad
{
private:
	double x, l, r;

public:
	Triad();
	Triad(const double x, const double l, const double r);
	Triad(const Triad& a);

	double GetX() const { return x; }
	double GetL() const { return l; }
	double GetR() const { return r; }

	void SetX(double value) { x = value; }
	void SetL(double value) { l = value; }
	void SetR(double value) { r = value; }

	Triad& operator =(const Triad& n);
	operator string() const;

	friend bool operator == (const Triad& l, const Triad& r);
	friend bool operator != (const Triad& l, const Triad& r);
	friend bool operator > (const Triad& l, const Triad& r);
	friend bool operator < (const Triad& l, const Triad& r);
	friend bool operator >= (const Triad& l, const Triad& r);
	friend bool operator <= (const Triad& l, const Triad& r);

	friend ostream& operator << (ostream& out, const Triad& a);
	friend istream& operator >> (istream& in, Triad& a);
};

