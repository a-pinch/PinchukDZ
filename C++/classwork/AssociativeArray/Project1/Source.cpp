#include <string>
#include <cstdio>
#include "UnorderedMap.h"
#include "DigestMap.h"

class Turtle {
public:
	Turtle(){};
};

int main(){
	DigestMap<string, float> people;
	char buffer[50];
	for (int i = 0; i < 10; i++){
		sprintf_s(buffer, "%s%d", "Anna",i);
		people[buffer] = 1.7f;
		sprintf_s(buffer, "%s%d", "Alex", i);
		people[buffer] = 2.7f;
		sprintf_s(buffer, "%s%d", "Boreau", i);
		people[buffer] = 0.1f;
	}

	people.show();

	cin.get();

	return 0;
}