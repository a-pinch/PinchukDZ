#pragma once
#include <string>
#include <map>
#include "Trait.h"

class Answer
{
public:

	std::string text;
	std::map<trait_numb, int> points;

	Answer();
};

