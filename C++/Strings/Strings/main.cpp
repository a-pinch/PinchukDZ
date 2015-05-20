#include "String.h"

#include <iostream>

using namespace std;

int main() {
	const String a = " world!";
	String b = "Hello", c('v', 5);

	String d = a; // вызов конструктора копирования

	b = a; // присваивание

	a.print();
	print(b);
	b.print();
	c.print();

	int y = sqr(1 + 7 * 4 + 19);

	char *search = "word";
	
	if (b.find(search))
		cout << "\"" << search << "\" is found in \"" << b.c_str() << "\"." <<endl;
	else
		cout << "\"" << search << "\" is not found in \"" << b.c_str() << "\"." << endl;

    b.add(" world!");

	a.print();
	b.print();
	
	getc(stdin);
	return 0;
}