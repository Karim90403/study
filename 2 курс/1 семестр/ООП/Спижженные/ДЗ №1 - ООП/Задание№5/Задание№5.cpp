#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream ifile;
	ifile.open("myfile.txt");
	string s0, s1;
	for (; ;)
	{
		ifile >> s0;
		s1 += s0 + "\n";
		if (ifile.eof()) break;
	}
	cout << s1;
}
