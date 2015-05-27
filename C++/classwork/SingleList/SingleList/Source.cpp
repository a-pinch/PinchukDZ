#include "List.h";
#include <iostream>

using namespace std;

int main(){
	List l;
	l.push_front(1).push_front(2).push_front(3);
	l[1] = 7;

	for (size_t i = 0; i < l.getSize(); i++){
		cout << l[i] <<" ";
	}
	cin.get();
	return 0;
}