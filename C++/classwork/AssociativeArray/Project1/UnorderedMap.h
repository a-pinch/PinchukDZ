#pragma once;

#include <iostream>
#include <list>

using namespace std;

template<class Tkey, class Tvalue> 
class UnorderedMap{
private:
	struct pair
	{
		pair(Tkey k, Tvalue v) : key(k), value(v){};
		Tkey key;
		Tvalue value;
	};

	list<pair> pairs;
public:
	UnorderedMap(){}
	~UnorderedMap(){}
	Tvalue& operator[](const Tkey& key) {
		for (auto i = pairs.begin(); i != pairs.end(); i++){
			if (i->key == key){
				return i->value;
			}
		}
		pairs.push_back(pair(key, Tvalue()));
		return pairs.back().value;
	}

	void show(){
		for (auto pair: pairs){	
			cout << pair.key << " -> " <<pair.value << endl;
		}

	}

	int size(){
		return pairs.size();
	}
};