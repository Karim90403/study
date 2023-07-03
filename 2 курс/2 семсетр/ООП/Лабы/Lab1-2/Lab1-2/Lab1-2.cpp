#include <iostream>
#include <vector>
#include <iterator>
#include <string>

using namespace std;

class Parent {
    string str;
public:
    Parent(){}
    Parent(string m_str) {
        str = m_str;
    }
    virtual Parent* copy() {
        return new Parent(*this);
    }
    virtual void print() {
        cout << "String:" << str << "\n";
    }
    virtual ~Parent(){ }
};

class Child : public Parent {
public:
    Child() {};
    virtual Child* copy() {
        return new Child(*this);
    }
    void print() {};
    ~Child() {};
};

int main() 
{
    vector<Parent*> db1;
    db1.push_back(new Parent("Parent 1"));
    db1.push_back(new Child());
    db1.push_back(new Parent("Parent 2"));
    db1.push_back(new Child());

    vector<Parent*> db2;
    copy(db1.begin(), db1.end(), back_inserter(db2));

    for (auto it = db2.begin(); it != db2.end(); ++it) {
        (*it)->print();
    }

    for (auto it = db1.begin(); it != db1.end(); ++it) {
        delete (*it);
    }


    return 0;
}