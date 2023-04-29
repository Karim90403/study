#include "DB.h"
DB::DB() {}
void DB::print()
{
	for (vector<Shape*>::iterator it = this->begin(); it != this->end(); it++)
	{
		cout << "Coordinates and additional values of the object:" << endl;
		(*it)->print();
		cout << "------------------------------------------------" << endl;
	}
}
DB::~DB() {}