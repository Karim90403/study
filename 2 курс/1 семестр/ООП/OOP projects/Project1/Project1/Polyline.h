#pragma once
#include "Shape.h"

class Polyline: public Shape
{
vector <double> v_x;
vector <double> v_y;
public:
	Polyline();
	Polyline(vector <double> v_x, vector <double> v_y);
	void print();
	~Polyline();
};

