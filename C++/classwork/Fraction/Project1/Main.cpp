#include "Fraction.h"
#include <iostream>

int main() {
	Fraction a(1, 2), b = 7;

	std::cout << "a = "; a.print();
	std::cout << "b = "; b.print();

	a *= b;
	std::cout << "a = a*b = "; a.print();
	std::cout << "b/a = "; (b / a).print();

	a += b;
	std::cout << "a = a+b = "; a.print();
	std::cout << "b - a = "; (b - a).print();

	getc(stdin);

	return 0;
}