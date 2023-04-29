#include "Point.h"
Point::Point(){}
Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
}
void Point::print()
{
	cout << "Point" << endl;
	cout << "x = " << x << endl << "y = " << y << endl;
}

Point::~Point(){}