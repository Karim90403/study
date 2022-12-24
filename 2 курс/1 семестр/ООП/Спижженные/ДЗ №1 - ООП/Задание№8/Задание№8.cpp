#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Reader {
    vector<int> m_v;
public:
    Reader(){}
    void read(const char* name);
    void print();
};

void Reader::read(const char* name) {
    ifstream ifile;
    ifile.open(name);
    int a;
    for (; ;) {
        ifile >> a;
        m_v.push_back(a);
        if (ifile.eof())break;
    }
}

void Reader::print() {
    for (int i = 0; i < m_v.size(); i++)
    {
        cout << m_v[i] << endl;
    }
}
int main()
{
    Reader r;
    r.read("myfile.txt");
    r.print();
    getchar();
}
