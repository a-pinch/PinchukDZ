#include <string>
#include <cstdio>
#include "UnorderedMap.h"
#include "DigestMap.h"

class Turtle {
public:
	Turtle(){};
};

int main(){
	int n = 300;
	DigestMap<string, float> people(n);
	char buffer[50];
	for (int i = 0; i < 100; i++){
		sprintf_s(buffer, "%s%d", "Anna",i);
		people[buffer] = i*1.7f;
		sprintf_s(buffer, "%s%d", "Alex", i);
		people[buffer] = i*2.7f;
		sprintf_s(buffer, "%s%d", "Boreau", i);
		people[buffer] = i*0.1f;
	}

	people.show();
	cout << people.colisions() << "(" << ((double)people.colisions() / n) * 100 << "%) colisions" << endl;

	cin.get();

	return 0;
}