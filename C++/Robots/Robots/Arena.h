#pragma once
#include <vector>
#include "Circle.h"

class Arena
{
public:
	Arena();
	~Arena();

	static void show(std::vector<Circle*> objectStorage);
};

