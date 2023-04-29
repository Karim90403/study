#include "DB.h"

struct Leaks
{
	~Leaks() { _CrtDumpMemoryLeaks(); }
};

Leaks l;

int main()
{
	setlocale(0, "");
	fstream file;
	file.open("model.dxf");
	string reader;
	double x, y, radius, x1, y1;
	double proportion; 
	DB db1;
	vector <double> v_x;
	vector <double> v_y;

	while (!file.eof())
	{
		file >> reader;
		if (reader == "CIRCLE")
		{
			while (reader != "AcDbCircle")
			{
				file >> reader;
			}
			while (reader != "0")
			{
				file >> reader;
				if (reader == "10")
				{
					file >> reader;
					x = atof(reader.c_str());
				}
				if (reader == "20")
				{
					file >> reader;
					y = atof(reader.c_str());
				}
				if (reader == "40")
				{
					file >> reader;
					radius = atof(reader.c_str());
				}
			}
			db1.push_back(new Circle(x, y, radius));
		}
		else if (reader == "POINT")
		{
			while (reader != "AcDbPoint")
			{
				file >> reader;
			}
			while (reader != "0")
			{
				file >> reader;
				if (reader == "10")
				{
					file >> reader;
					x = atof(reader.c_str());
				}
				if (reader == "20")
				{
					file >> reader;
					y = atof(reader.c_str());
				}
			}
			db1.push_back(new Point(x, y));
		}
		else if (reader == "POLYLINE")
		{
			while (reader != "SEQEND")
			{
				file >> reader;
				while (reader != "VERTEX")
				{
					if (reader == "SEQEND")
						break;
					file >> reader;
				}
				if (reader == "SEQEND")
					break;
				while (reader != "AcDb2dVertex")
				{
					file >> reader;
				}
				while (reader != "0")
				{
					file >> reader;
					if (reader == "10")
					{
						file >> reader;
						x = atof(reader.c_str());
						v_x.push_back(x);
					}
					if (reader == "20")
					{
						file >> reader;
						y = atof(reader.c_str());
						v_y.push_back(y);
					}
				}
			}
			db1.push_back(new Polyline(v_x, v_y));
			v_x.clear();
			v_y.clear();
		}

		else if (reader == "ELLIPSE")
		{
			while (reader != "AcDbEllipse")
			{
				file >> reader;
			}
			while (reader != "0")
			{
				file >> reader;
				if (reader == "10")
				{
					file >> reader;
					x = atof(reader.c_str());
				}
				if (reader == "20")
				{
					file >> reader;
					y = atof(reader.c_str());
				}
				if (reader == "11")
				{
					file >> reader;
					x1 = atof(reader.c_str());
				}
				if (reader == "21")
				{
					file >> reader;
					y1 = atof(reader.c_str());
				}
				if (reader == "40")
				{
					file >> reader;
					proportion = atof(reader.c_str());
				}
			}
			db1.push_back(new Elipse(x, y, x1, y1, proportion));
		}
	}
	file.close();
	cout << "Total objects depicted in the AutoCAD file - " << db1.size() << endl << endl;
	db1.print();
	for (vector <Shape*>::iterator it = db1.begin(); it != db1.end(); it++)
		delete* it;

	db1.clear();
}