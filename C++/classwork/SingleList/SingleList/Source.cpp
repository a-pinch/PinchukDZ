#include "List.h";

int main(){
	List l;
	l.push_front(1).push_front(2).push_front(3);
	l[1] = 7;

	return 0;
}