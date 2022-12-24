#include <iostream>
#include <vector>
#include <fstream>
#include <set>
using namespace std;

void func() {
    ifstream ifile;
    ifile.open("myfile.txt");
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
int main()
{
    func();
}
