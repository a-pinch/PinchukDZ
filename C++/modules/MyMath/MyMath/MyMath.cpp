#include "MyMath.h"

int gcd(int a, int b){
	if (b == 0) return a;
	while (a%b != 0){
		int c = a%b;
		a = b; b = c;
	}
	return b;
}

int lcm(int a, int b){
	return a * (b / gcd(a, b));
}

unsigned int digest(string key){
	unsigned int dig = 0;
	for (size_t i = 0; i < key.length(); i++){
		dig += key[i];
	}
	return dig;
}

unsigned int digest(int key){
	return key;
}