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
    vector <int>* v = new vector<int>;
    Base() {
        for(int i = 0; i < 10; i++)
            v->push_back(i);
    }
    Base(const Base& obj) {
        vector<int> ::iterator it;
        for (it = obj.v->begin(); it != obj.v->end(); it++)
            v->push_back(*it);
    }
    virtual Base* copy() {
        return new Base(*this);
    }
    virtual ~Base() {
        delete v;
    }
};

class Derived: public Base
{
public:
    Derived() {}
    Derived(const Derived& d):Base(d) {}
    Derived* copy() {
        return new Derived(*this);
    }
    ~Derived() {
        cout << endl;
    }
};

class DB
{
private:
    vector<Base*>* v = new vector<Base*>;
public:
    DB() {}
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
    DB& operator= (const DB& obj)
    {
        if (this == &obj) return *this;
        copy_data(obj);
        return *this;
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

    db1.add(new Base);
    db1.add(new Derived);

    db2 = db1;
}
