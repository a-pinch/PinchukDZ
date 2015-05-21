#pragma once

class Fraction
{
public:
	int n; //numerator
	unsigned int d; //denominator

	Fraction();
	Fraction(int n);
	Fraction(int n, unsigned int d);
	~Fraction();

	void print() const;

	Fraction& operator *= (const Fraction &f);
	Fraction& operator /= (const Fraction &f);
	Fraction operator * (const Fraction &f) const;
	Fraction operator / (const Fraction &f) const;

	Fraction& operator += (const Fraction &f);
	Fraction& operator -= (const Fraction &f);
	Fraction operator + (const Fraction &f) const;
	Fraction operator - (const Fraction &f) const;

	Fraction& operator *= (int a);
	Fraction& operator /= (int a);
	Fraction operator * (int a) const;
	Fraction operator / (int a) const;

	Fraction& operator += (int a);
	Fraction& operator -= (int a);
	Fraction operator + (int a) const;
	Fraction operator - (int a) const;

	Fraction& operator *= (double a);
	Fraction& operator /= (double a);
	Fraction operator * (double a) const;
	Fraction operator / (double a) const;

	Fraction& operator += (double a);
	Fraction& operator -= (double a);
	Fraction operator + (double a) const;
	Fraction operator - (double a) const;

	Fraction operator + () const;
	Fraction operator - () const;

	bool operator > (const Fraction &f) const;
	bool operator >= (const Fraction &f) const;
	bool operator < (const Fraction &f) const;
	bool operator <= (const Fraction &f) const;

	bool operator == (const Fraction &f) const;
	bool operator != (const Fraction &f) const;

private:
	void cancel();

};

