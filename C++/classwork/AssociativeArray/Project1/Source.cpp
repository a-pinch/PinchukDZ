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
	people["Anna"] = 1.7f;
	people["Alex"] = 2.7f;
	people["Boreau"] = 0.1f;

	people.show();

	cin.get();

	return 0;
}