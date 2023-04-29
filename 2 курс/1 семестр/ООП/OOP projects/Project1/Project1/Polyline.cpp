#include "Polyline.h"

Polyline::Polyline() {}
Polyline::Polyline(vector <double> v_x, vector <double> v_y)
{
	for (int i = 0; i < v_x.size(); i++)
	{
		this->v_x.push_back(v_x[i]);
		this->v_y.push_back(v_y[i]);
	}
}
void Polyline::print()
{
	cout << "PolyLine" << endl;
	cout << "Quantity of points - " << v_x.size() << endl;
	for (int i = 0; i < v_x.size(); i++)
	{
		cout << "x[" << i << "] = " << v_x[i] << endl << "y[" << i << "] = " << v_y[i] << endl;
	}
}
Polyline::~Polyline() {}