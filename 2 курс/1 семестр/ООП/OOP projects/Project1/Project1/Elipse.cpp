#include "Elipse.h"
Elipse::Elipse(){}
Elipse::Elipse(double x, double y, double x1, double y1, double otn_m_k_b)
{
	this->x = x;
	this->y = y;
	this->x1 = x1;
	this->y1 = y1;
	this->proporcion = otn_m_k_b;
}
void Elipse::print()
{
	cout << "Ellipse" << endl;
	cout << "x[0] = " << x << endl << "y[0] = " << y << endl;
	cout << "x[1] = " << x << endl << "y[1] = " << y << endl;
	cout << "The ratio of a smaller arc to a larger one : " << proporcion << endl;
}

Elipse::~Elipse(){}