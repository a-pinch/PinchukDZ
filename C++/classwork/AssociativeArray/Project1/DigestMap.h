#pragma once;
#include <stdlib.h>
#include <string>

template<class Tkey, class Tvalue> class DigestMap{
private:
	int NN, N;
	UnorderedMap<Tkey,Tvalue> **table;

	unsigned int digest(string key){
		unsigned int dig = 0;
		for (size_t i = 0; i < key.length(); i++){
			dig += key[i];
		}
		return dig;
	}

public:
	DigestMap() :  DigestMap(N) {};
	DigestMap(int capacity) : N(capacity), NN(3 * NN){
		table = new UnorderedMap<Tkey,Tvalue>* [NN];
		for (int i = 0; i < NN; i++){
			table[i] = new UnorderedMap<Tkey, Tvalue>();
		}
	};
	~DigestMap(){
		delete[] table;
	};

	Tvalue& operator[](const Tkey& key) {
		int dig = digest(key);
		////
		return (*(table[dig % NN]))[key];
	}

	void show(){
		for (int i = 0; i < NN; i++){
			(table[i])->show();
		}
	}

};