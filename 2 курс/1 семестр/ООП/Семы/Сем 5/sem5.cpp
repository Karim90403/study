#include <iostream>
#include <vector>

using namespace std;

struct Leaks{
    ~Leaks() { _CrtDumpMemoryLeaks(); }
};
Leaks l_;

class Base
{
public:
    int* a = new int();
    Base() {
        *a = 10;
    }
    Base(const Base& b) {
        *a = *b.a;
    }
    virtual Base* copy() {
        return new Base(*this);
    }
    virtual ~Base() {
        delete a;
    }
};

class Derived: public Base
{
public:
    string s;
    Derived() {
        s = "str";
    }
    Derived(const Derived& d):Base(d) {
        s = d.s;
    }
    Derived* copy() {
        return new Derived(*this);
    }
    ~Derived() {}
};

class DB
{
private:
    vector<Base*>* v;
public:
    DB() {
        v = new vector<Base*>;
    }
    void add(Base* b){
        v->push_back(b);
    }
    DB(const DB& obj)
    {
        vector<Base*> ::iterator it;
        for (it = obj.v->begin(); it != obj.v->end(); it++) {
            Base* new_obj = (*it)->copy();
            v->push_back(new_obj);
        }
    }
    void copy_data(const DB& obj)
    {
        vector<Base*> ::iterator it;
        for (it = v->begin(); it != v->end(); it++)
            delete* it;
        v->clear();

        for (it = obj.v->begin(); it != obj.v->end(); it++){
            Base* new_obj = (*it)->copy();
            v->push_back(new_obj);
        }
    }
    ~DB(){
        vector<Base*> ::iterator it;
        for (it = v->begin(); it != v->end(); it++)
            delete* it;
        v->clear();
        delete v;
    }
};

int main()
{
    DB db1, db2;

    for (int i = 0; i < 2; i++) {
        db1.add(new Base);
        db1.add(new Derived);
    }

    db2.copy_data(db1);

}
