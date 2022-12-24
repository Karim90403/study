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

class Reader
{
    vector <int> m_v;
public:
    Reader() { }
    void read(const char* name);
    void sort();
    void print();
};

void Reader::print()
{
    for (int i = 0; i < m_v.size(); i++)
    {
        cout << m_v[i] << endl;
    }
}

void Reader::sort()
{
    sort(m_v.begin(), m_v.end());
}

void Reader::read(const char* name)
{
    ifstream ifile;
    ifile.open(name);
    int a;
    for (; ; )
    {
        ifile >> a;
        if (ifile.eof()) break;
        m_v.push_back(a);
    }
}

void mainFunc() {
    ofstream of;
    of.open("/Users/karimmuzafarov/Desktop/ООП/Проекты/Поект 13/myfile.txt");

    for (int i = 0; i < 10; i++) {
        of << i << endl;
    }

    fstream ifile;
    ifile.open("/Users/karimmuzafarov/Desktop/ООП/Проекты/Поект 13/myfile.txt");
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
    
    sort(v.rbegin(), v.rend());
    

}


int _tmain(int argc, _TCHAR* argv[])
{
    Reader r;
    r.read("/Users/karimmuzafarov/Desktop/ООП/Проекты/Поект 13/myfile.txt");
    r.sort();
    r.print();
    getchar();
    mainFunc();
    return 0;
}
