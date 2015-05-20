#include "strings.h"

#include <iostream>

using namespace std;

int main() {
	String a = "Hello ", b = "world!";
	String c = concat(a, b);

	a.print();
	b.print();
	c.print();

	c.upper();
	c.print();

	String d= c.first(3);
	d.print();

	String e = c.last(3);
	e.print();

	String f = c.substr(4, 3);
	f.print();

	String g = "   trim  ";
	g.print();
	g.trim().print();

	getc(stdin);

	return 0;
}