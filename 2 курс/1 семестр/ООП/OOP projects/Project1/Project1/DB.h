#pragma once
#include "Point.h"

class DB :public vector <Shape*>
{
public:
	DB();
	void print();
	~DB();
};

