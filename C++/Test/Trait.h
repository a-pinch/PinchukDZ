#pragma once
#include <string>
#include <vector>

class Trait
{
public:
	static std::vector<Trait> traits;
	const std::string name;
	Trait(const std::string& n) : name(n) {};

	static void init(std::string filename);
	static void show();
private:
	static void parse(std::string buf);
};

typedef size_t trait_numb;
