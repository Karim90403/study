#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream of;
	of.open("myfile.txt");
	for (int i = 0; i < 10; i++) {
		of << i << endl;
	}
}
