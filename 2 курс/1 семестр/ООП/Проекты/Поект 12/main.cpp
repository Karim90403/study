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

class Test
{
public:
    Test()
    {
        cout << "Construct" << endl;
    }
    ~Test()
    {
        cout << "Destruct" << endl;
    }
};

class Reader
{
    vector <int> m_v;
public:
    Reader() { }
    void read(const char* name);
    void print();
};

void Reader::print()
{
    for (int i = 0; i < m_v.size(); i++)
    {
        cout << m_v[i] << endl;
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

void reader() {
    ifstream ifile;
    ifile.open("/Users/karimmuzafarov/Desktop/ООП/Проекты/Поект 12/myfile.txt");
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

void mainFunc() {
    ofstream of;
    of.open("/Users/karimmuzafarov/Desktop/ООП/Проекты/Поект 12/myfile.txt");

    for (int i = 0; i < 10; i++) {
        of << i << endl;
    }

    fstream ifile;
    ifile.open("/Users/karimmuzafarov/Desktop/ООП/Проекты/Поект 12/myfile.txt");
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
    
    vector <Test*>v2(10);
    for (int i = 0; i < v.size(); i++) {
        v2[i] = new Test();
    }
    for (int i = 0; i < v.size(); i++) {
        delete v2[i]; v2[i] = 0;
    }
}


int _tmain(int argc, _TCHAR* argv[])
{
    mainFunc();
    reader();
    return 0;
}
