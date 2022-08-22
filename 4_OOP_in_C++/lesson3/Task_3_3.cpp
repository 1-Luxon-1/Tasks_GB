#include <iostream>
using namespace std;

class Fraction
{
public:

	friend ostream& operator<<(ostream& output, const Fraction& f);

	Fraction(int _num = 1, int _den = 1)
	{
		num = _num;
		den = (_den != 0) ? _den : 1;
	}

	Fraction(Fraction& f)
	{
		num = f.num;
		den = f.den;
	}

	Fraction operator +(Fraction& f)
	{
		Fraction resultSum;
		resultSum.num = num * f.den + f.num * den;
		resultSum.den = den * f.den;
		return resultSum;
	}
	
	Fraction operator- (Fraction& f)
	{
		Fraction resultSub;
		resultSub.num = num * f.den - f.num * den;
		return resultSub;
	}

	Fraction operator* (Fraction& f)
	{
		Fraction resultMul;
		resultMul.num = num * f.num;
		resultMul.den = den * f.den;
		return resultMul;
	}

	Fraction operator/ (Fraction& f)
	{
		Fraction resultDiv;
		resultDiv.num = num * f.den;
		resultDiv.den = den * f.num;
		return resultDiv;
	}

	Fraction operator- ()
	{
		Fraction neg;
		neg.num = -1;
		return neg;
	}

	bool operator== (Fraction &f)
	{
		if (num == f.num && den == f.den)
		{
			return true;
		}
		return false;
	}

	bool operator!= (Fraction& f)
	{
		if (*this == f)
		{
			return false;
		}
		return true;
	}

	bool operator< (Fraction& f)
	{
		double divLeft = static_cast<double>(num) / static_cast<double>(den);
		double divRight= static_cast<double>(f.num) / static_cast<double>(f.den);
		if (divLeft < divRight)
		{
			return true;
		}
		return false;
	}

	bool operator>= (Fraction& f)
	{
		return (*this < f) ? false : true;
	}

	bool operator> (Fraction& f)
	{
		double divLeft = static_cast<double>(num) / static_cast<double>(den);
		double divRight = static_cast<double>(f.num) / static_cast<double>(f.den);
		if (divLeft > divRight)
		{
			return true;
		}
		return false;
	}

	bool operator<= (Fraction& f)
	{
		return (*this > f) ? false : true;
	}

private:
	int num;
	int den;
};