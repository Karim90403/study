#include <iostream>
#include <vector>
using namespace std;
class Base
{
    int* a;
public:
Base() {
    a = new int;
    *a = 123;
}
    virtual ~Base()
    {
        delete a;
    }
    Base(const Base& o)
    {
        a = new int;
        *a = *o.a;
    }
    virtual Base* copy()
    {
        return new Base(*this);
    }
};
class Derived_1: public Base
{
public:
float f;
    Derived_1()
    {
        f = 12.3;
    }
    virtual ~Derived_1(){}
    Derived_1(const Derived_1& o): Base(o)
    {
        f = o.f;
    }
    virtual Base* copy()
    {
        return new Derived_1(*this);
    }
};
class Derived_2: public Derived_1
{
public:
char s;
    Derived_2()
    {
        s = 's';
    }
    void Change(char new_s)
    {
        s = new_s;
    }
    Derived_2(const Derived_2& o): Derived_1(o)
    {
        s = o.s;
    }
    virtual Base* copy()
    {
        return new Derived_2(*this);
    }
    ~Derived_2(){}
};
vector<Base*> v1;
vector<Base*> v2;
void DeleteVector(vector<Base*> v)
{
    for(int i = 0; i < v.size(); i++)
    {
        delete v[i];
    }
    v.clear();
}
int main() {
    for(int i = 0; i < 3; i++)
    {
        v1.push_back(new Base);
        v1.push_back(new Derived_1);
        v1.push_back(new Derived_2);
}
    for (int i = 0; i < v1.size(); i++)
     {
      v2.push_back(v1[i]->copy());
     }
    DeleteVector(v1);
    DeleteVector(v2);
    return 0;
}
