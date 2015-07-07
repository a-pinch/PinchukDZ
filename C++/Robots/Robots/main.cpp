#include <iostream>
#include <conio.h>
#include <vector>
#include <stdlib.h>
#include "Circle.h"
#include "Robot.h"
#include "Bolt.h"
#include "Arena.h"
#include "windows.h"
#include "const.h"

using namespace std;

vector<Circle*> objectStorage;

int main(){
	int count = 0;

	objectStorage.push_back(new Robot(100, 100));
	objectStorage.push_back(new Robot(200, 200));

	do{
		system("cls");		
		Arena::show(objectStorage);
		cout << "Test " << count++;
		Sleep(1000 / FPS);
	} while (objectStorage.size() > 1);

	_getch();

	return 0;
}