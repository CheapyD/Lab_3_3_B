#include "Triad.h"

Triad::Triad() 
{
	SetX(0); 
	SetL(0); 
	SetR(0); 
}

Triad::Triad(const double x = 0, const double l = 0, const double r = 0)
{
	SetX(x); 
	SetL(l); 
	SetR(r);
}

Triad::Triad(const Triad& A)
{
	SetX(A.GetX());
	SetL(A.GetL());
	SetR(A.GetR());
}

Triad& Triad::operator =(const Triad& n)
{
	SetX(n.GetX());
	SetL(n.GetL());
	SetR(n.GetR());
	return *this;
}

bool operator == (const Triad& A, const Triad& B)
{
	return (A.GetX() == B.GetX() && A.GetL() == B.GetL() && A.GetR() == B.GetR());
}

bool operator != (const Triad& A, const Triad& B)
{
	return !(A == B);
}

bool operator > (const Triad& A, const Triad& B)
{
	return ((A.GetX() > B.GetX()) || (A.GetX() == B.GetX() && A.GetL() > B.GetL()) ||
			(A.GetX() == B.GetX() && A.GetL() == B.GetL() && A.GetR() > B.GetR()));
}

bool operator < (const Triad& A, const Triad& B)
{
	return ((A.GetX() < B.GetX()) || (A.GetX() == B.GetX() && A.GetL() < B.GetL()) ||
			(A.GetX() == B.GetX() && A.GetL() == B.GetL() && A.GetR() < B.GetR()));
}

bool operator >= (const Triad& A, const Triad& B)
{
	return !(A < B);
}

bool operator <= (const Triad& A, const Triad& B)
{
	return !(A > B);
}

Triad::operator string() const
{
	stringstream ss;
	ss << "x = " << x << endl;
	ss << "l = " << l<< endl;
	ss << "r = " << r << endl;
	return ss.str();
}

ostream& operator << (ostream& out, const Triad& A)
{
	out << string(A);
	return out;
}

istream& operator >> (istream& in, Triad& A)
{
	double x, l , r;
	cout << "x = "; in >> x;
	cout << "l = "; in >> l;
	cout << "r = "; in >> r;
	A.SetX(x); A.SetL(l); A.SetR(r);
	return in;
}