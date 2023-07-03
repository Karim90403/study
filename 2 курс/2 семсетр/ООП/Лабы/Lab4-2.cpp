#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Leaks
{
    ~Leaks() { _CrtDumpMemoryLeaks(); }
};

Leaks _l;

class A {
public:
    string s;
    A() {
        cout << "Конструктор по умолчанию класса А" << endl;
    }

    A(const char* a) {
        s = a;
        cout << "Пользовательский Конструктор класса A" << endl;
        cout << s << endl;
    }
    virtual ~A() {
        cout << "Деструктор класса A" << endl;
        cout << typeid(*this).name() << endl;
    }
};

class B : public A {
public:
    B() {
        cout << "Конструктор  класса B" << endl;
    }
    B(const char* a) : A(a) {
        cout << "Пользовательский Конструктор класса B" << endl;
        cout << a << endl;
    }
    ~B() {
        cout << "Деструктор класса B" << endl;
        cout << typeid(*this).name() << endl;
    }
};

vector<A*>v;

int main() {
    setlocale(LC_ALL, "RUS");
    v.push_back(new A("first"));
    v.push_back(new B("second"));
    for_each(v.begin(), v.end(), [](A* p) { delete p; });
    return 0;
}
