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
    void someMath();
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
    ::sort(m_v.begin(), m_v.end());
}

void Reader::someMath()
{
    ifstream ifile;
    ifile.open("/Users/karimmuzafarov/Desktop/ООП/Проекты/Поект 15/myfile.txt");
    float a;

    vector <float> st;
    for (; ; )
    {
        ifile >> a;
        if (ifile.eof()) break;
        st.push_back(a);
        st.push_back(sqrt(a));
    }
        
    for (int it = 0; it < st.size(); ++it)
    {
        cout << st[it] << " ";
        if (it % 2 == 1)
            cout << endl;
    }
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


int _tmain(int argc, _TCHAR* argv[])
{
    Reader r;
    r.read("/Users/karimmuzafarov/Desktop/ООП/Проекты/Поект 15/myfile.txt");
    r.sort();
    r.print();
    r.someMath();
    getchar();
    return 0;
}
