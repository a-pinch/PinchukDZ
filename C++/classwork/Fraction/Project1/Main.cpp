#include "Fraction.h"
#include <iostream>

using namespace std;

int main() {
	Fraction a(1, 2), b = 7;

	cout << "a = "; a.print();
	cout << "b = "; b.print();

	a *= b;
	cout << "a = a*b = "; a.print();
	cout << "b/a = "; (b / a).print();

	a += b;
	cout << "a = a+b = "; a.print();
	cout << "b - a = "; (b - a).print();

	cout << "a+7 = " << a + 7;

	getc(stdin);

	return 0;
}