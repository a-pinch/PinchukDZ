#include <iostream>
#include "Test.h"
#include "Trait.h"
#include "Question.h"
using namespace std;

int main() {
	string username;
	Trait::init("traits.txt");
	Question::init("");

	cout << "Enter your name:";
	cin >> username; // getline 
	if (username == "") { //?
		cout << "Enter your name:";
		cin >> username;
	}

	Test T(username);
	while (!T.isFinished())	{
		T.ask();
	}

	T.show_result();

	return 0;
}
