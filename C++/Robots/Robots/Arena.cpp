#include "Arena.h"
#include "const.h"
#include "iostream"

const double consoleXSize = 80; // pixels
const double consoleYSize = 20; // pixels

Arena::Arena()
{
}


Arena::~Arena()
{
}

void Arena::show(std::vector<Circle*> objectStorage){
	for (int y = 0; y < consoleYSize; y++){
		std::cout << y;
		for (int x = 0; x < consoleXSize; x++){
			for (auto object : objectStorage){
				if (x == consoleXSize * (int)object->x / arenaXSize && y == consoleYSize * (int)object->y / arenaYSize){
					object->show();
				}else{
					std::cout << " ";
				}
			}
		}
		std::cout << std::endl;
	}
}