#include <cstdlib>
#include <iostream>
#include <math.h>
#include "Fraction.h"
#include "mymath.h"

Fraction::Fraction()
{
	n = 0;
	d = 1;
}

Fraction::Fraction(int n){
	this->n = n;
	this->d = 1;
}

Fraction::Fraction(int n, unsigned int d){
	this->n = n;
	this->d = d;
}

Fraction::~Fraction()
{
}

void Fraction::print() const{
	print(cout);
}

void Fraction::print(ostream& s) const{
	if (d != 0){
		if (d == 1){
			s << n << endl;
		}else if (n / (int)d != 0){
			if (n%(int)d == 0){
				s << abs(n) / (int)d << endl;
			}else{
				s << n / (int)d << ' ' << abs(n)%(int)d << "/" << d << endl;
			}
		}else{
			s << n << "/" << d << endl;
		}
	}else{
		if (n == 0){
			s << "NaN" << endl;
		}else if (n < 0){
			s << "-oo" << endl;
		}else{
			s << "+oo" << endl;
		}
	}
}

Fraction& Fraction::operator *= (const Fraction &f){
	n *= f.n;
	d *= f.d;
	return *this;
}
Fraction& Fraction::operator /= (const Fraction &f){
	n *= f.d;
	d *= f.n;
	return *this;
}
Fraction Fraction::operator * (const Fraction &f) const{
	Fraction res = Fraction(*this);
	res *= f;
	return res;
}
Fraction Fraction::operator / (const Fraction &f) const{
	Fraction res = Fraction(*this);
	res /= f;
	return res;
}

Fraction& Fraction::operator += (const Fraction &f){	
	n = this->n*f.d + f.n*this->d;
	d *= f.d;
	cancel();
	return *this;
}
Fraction& Fraction::operator -= (const Fraction &f){	
	return *this += -f;
}
Fraction Fraction::operator + (const Fraction &f) const{
	Fraction res = Fraction(*this);
	res += f;
	return res;
}
Fraction Fraction::operator - (const Fraction &f) const{
	Fraction res = Fraction(*this);
	res -= f;
	return res;
}

Fraction& Fraction::operator *= (int a){
	n *= a;
	return *this;
}
Fraction& Fraction::operator /= (int a){
	d *= a;
	return *this;
}
Fraction Fraction::operator * (int a) const{
	Fraction res = Fraction(*this);
	res *= a;
	return res;
}
Fraction Fraction::operator / (int a) const{
	Fraction res = Fraction(*this);
	res /= a;
	return res;
}

Fraction& Fraction::operator += (int a){
	n += a*d;
	return *this;
}
Fraction& Fraction::operator -= (int a){
	return *this += -a;
}
Fraction Fraction::operator + (int a) const{
	Fraction res = Fraction(*this);
	res += a;
	return res;
}
Fraction Fraction::operator - (int a) const{
	Fraction res = Fraction(*this);
	res -= a;
	return res;
}

Fraction Fraction::operator + () const{
	return *this;
}

Fraction Fraction::operator - () const{
	Fraction res(*this);
	res.n = -res.n;
	return res;
}

bool Fraction::operator > (const Fraction &f) const{
	return f < *this;
}

bool Fraction::operator >= (const Fraction &f) const{
	return !(*this < f);
}

bool Fraction::operator < (const Fraction &f) const{
	return n*f.d < f.n*d;
}

bool Fraction::operator <= (const Fraction &f) const{
	return !(f < *this);
}

void Fraction::cancel(){
	int cd = gcd(abs(n), abs((int)d));
	if (cd > 1){
		n /= cd;
		d /= cd;
	}
}

ostream& operator << (ostream& s, const Fraction& f){
	f.print();
	return s;
}
