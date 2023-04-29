#include "Circle.h"
Circle::Circle(){}
Circle::Circle(double x, double y, double r)
{
	this->x = x;
	this->y = y;
	this->r = r;
}
void Circle::print()
{
	cout << "Circle" << endl;
	cout << "x = " << x << endl << "y = " << y << endl << "r = " << r << endl;
}
Circle::~Circle() {}