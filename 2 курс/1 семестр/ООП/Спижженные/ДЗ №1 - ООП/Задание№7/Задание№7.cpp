#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
int main()
{
    ifstream ifile;
    ifile.open("myfile.txt");
    int a;
    vector <int> v;
    for(; ;)
    {
        ifile >> a;
        if (ifile.eof())break;
        v.push_back(a);   
    }
    //sort(v.begin(), v.end());
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
}
