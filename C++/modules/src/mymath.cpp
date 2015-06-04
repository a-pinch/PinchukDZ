#include <string>

using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    while(a%b != 0){
        int c = a%b;
        a = b; b = c;
    }
    return b;
}

int lcm(int a, int b){
    return a * (b / gcd(a,b));
}

unsigned long digest(string key){
	/*
	unsigned int dig = 0;
	for (size_t i = 0; i < key.length(); i++){
		dig += key[i];
	}
	return dig;
	*/
/*	unsigned long hash = 5381;
	for (size_t i = 0; i < key.length(); i++){
		hash = ((hash << 5) + hash) + key[i]; // hash * 33 + c 
	}

	return hash;
*/
	unsigned long hash, i;
	for (hash = i = 0; i < key.length(); ++i)
	{
		hash += key[i];
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return hash;
}

unsigned long digest(int key){
	return (unsigned long)key;
}