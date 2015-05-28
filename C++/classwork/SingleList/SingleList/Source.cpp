#include "List.h";
#include <iostream>

using namespace std;

int main(){
	List l;

	try{
		l.push_front(1).push_front(2).push_front(3);
		l[1] = 7;

		for (size_t i = 0; i < l.getSize(); i++){
			cout << l[i] << " ";
		}
		cout << endl;

		//l[4] = 5;

		size_t s = l.getSize();
		for (size_t i = 0; i <= s; i++){
			l.pop_front();
		}
	}
	catch (int e){
		switch (e){
		case 1:		//empty stack
			cout << "empty stack" << endl;
			break;
		case 2:		// index out of bouds
			cout << "index out of bouds" << endl;
			break;
		case 3:		// can't create node
			cout << "can't create node" << endl;
			break;
		default:
			break;
		}
	}

	cin.get();
	return 0;
}