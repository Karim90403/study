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
    ::sort(m_v.begin(), m_v.end());
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

void reader() {
    ifstream ifile;
    ifile.open("/Users/karimmuzafarov/Desktop/ООП/Проекты/Поект 14/myfile.txt");
    int a;
    set <int> st;
    for (; ;) {
        ifile >> a;
        if (ifile.eof())break;
        st.insert(a);
    }
    set <int>::iterator it = st.begin();
    for (; it != st.end(); ++it)
    {
        cout << *it << endl;
    }
}

void text() {
    string s;
    s = "test";
    cout << s << endl;
    getchar();
}


int _tmain(int argc, _TCHAR* argv[])
{
    Reader r;
    r.read("/Users/karimmuzafarov/Desktop/ООП/Проекты/Поект 14/myfile.txt");
    r.sort();
    r.print();
    getchar();
    return 0;
}
