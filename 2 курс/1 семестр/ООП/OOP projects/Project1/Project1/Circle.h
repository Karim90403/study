#pragma once
#include "Polyline.h"

class Circle :public Shape
{
private:
	double x;
	double y;
	double r;
public:
	Circle();
	Circle(double x, double y, double r);
	void print();
	~Circle();
};

