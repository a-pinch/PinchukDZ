#pragma once;
#include <stdlib.h>
#include <string>

unsigned long digest(string key);
unsigned long digest(int key);


template<class Tkey, class Tvalue> class DigestMap{
private:
	int NN, N;
	UnorderedMap<Tkey,Tvalue> **table;

public:
	DigestMap() :  DigestMap(100) {};
	DigestMap(int capacity) : N(capacity), NN(3 * capacity){
		table = new UnorderedMap<Tkey,Tvalue>* [NN];
		for (int i = 0; i < NN; i++){
			table[i] = nullptr;
		}
	};
	~DigestMap(){
		delete[] table;
	};

	Tvalue& operator[](const Tkey& key) {
		unsigned long dig = digest(key);
		if (table[dig % NN] == nullptr){
			table[dig % NN] = new UnorderedMap<Tkey, Tvalue>();
		}
		return (*(table[dig % NN]))[key];
	}

	void show(){
		for (int i = 0; i < NN; i++){
			if (table[i] != nullptr){
				cout << "cell " << i << ": ";
				(table[i])->show();
			}
		}
	}

};
