#include <iostream>
#include <vector>
#include <ctime>
#include <random>

using namespace std;

class Base {
public:
    int* num2;
    Base() {
        num2 = new int(rand()%1000);
    }
    Base(const Base& obj) {
        num2 = new int;
        *num2 = *obj.num2;
    }
    virtual Base* copy() {
        return new Base(*this);
    }
    virtual ~Base(){
        delete num2;
    }
    
    virtual void print()
    {
        cout << typeid(*this).name() << ": " << *num2;
    }
};

class Derived : public Base {
public:
    int num2;
    Derived() {
        num2 = rand()%100;
    }
    Derived(const Derived& obj){
        num2 = obj.num2;
    }
    virtual Derived* copy() {
        return new Derived(*this);
    }
    void print()
    {
        Base::print();
        cout << " " << num2;
    }
    ~Derived() {}
};

void add(const vector<Base*>& v1, vector<Base*>& v2)
{
    for(int i = 0; i < v1.size(); i++)
        v2.push_back(v1[i] -> copy());
}

int main()
{
    srand(time(NULL));
    vector<Base*> v1, v2;
    

    for(int i = 0; i < 4; i++)
    {
        if(rand() % 10 % 2)
            v1.push_back(new Base);
        else
            v1.push_back(new Derived);
    }
    
    add(v1, v2);
    
    for(int i = 0; i < v1.size(); i++)
    {
        v1[i] -> print();
        cout << "\n";
    }
    
    return 0;
}
