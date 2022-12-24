#include<iostream>
#include<fstream>
#include<string>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include "tchar.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
    string s;
    s = "test";
    cout << s << endl;
    getchar();

    ofstream of;
    of.open("myfile.txt");

    for (int i = 0; i < 10; i++) {
        of << i << endl;
    }

    fstream ifile;
    ifile.open("myfile.txt");
    string s0, s1;
    for (;;) {
        ifile >> s0;
        if (ifile.eof()) break;
        s1 += s0 + "\n";
    }
    cout << s1;

    int a;
    vector <int> v;
    for (; ; ) {
        ifile >> a;
        if (ifile.eof()) break;
        v.push_back(a);
    }

    //sort(v.begin(), v.end());
    sort(v.rbegin(), v.rend());

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }

    return 0;
}
