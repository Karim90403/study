#pragma once
#include "Circle.h"

class Elipse :public Shape
{
private:
	double x;
	double x1;
	double y;
	double y1;
	double proporcion;
public:
	Elipse();
	Elipse(double x, double y, double x1, double y1, double otn_m_k_b);
	void print();
	~Elipse();
};

