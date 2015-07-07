#include <math.h>

#pragma once

class Circle
{
protected:
	Circle(double init_x, double init_y, double init_v, int init_e)
		: x(init_x), y(init_y), v(init_v), energy(init_e)
	{}
public:
	// координаты
	double x, y,
		// вектор текущей скорости
		vx, vy;
	// разрешённая скорость
	const double v;
	int energy;
	// переместить объект в новую позицию 
	// в соответствии с его вектором скорости
	void move(double deltaT) {
		x += vx*deltaT;
		y += vy*deltaT;
	}
	// задать скорость в заданном направлении
	void moveToPoint(double init_x, double init_y) {
		double l = hypot(init_x - x, init_y - y);
		vx = init_x / l*v;
		vy = init_y / l*v;
	}

	virtual void show() = 0;
};

