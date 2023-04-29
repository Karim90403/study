#pragma once
#include "Elipse.h"

class Point :public Shape
{
private:
	double x;
	double y;
public:
	Point();
	Point(double x, double y);
	void print();
	~Point();
};

