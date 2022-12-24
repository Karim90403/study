#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main()
{
    ifstream ifile;
    ifile.open("myfile.txt");
    int a;
    vector <int> v;
    for (; ;)
    {
        ifile >> a;
        v.push_back(a);
        if (ifile.eof())break;
    }
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
}
