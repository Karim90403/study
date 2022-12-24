#include <iostream>

using namespace std;

//struct Leaks{ ~Leaks() { _CrtDumpMemoryLeaks(); } };
//Leaks _l;

class Base
{
public:
    bool* isBase = new bool;
    
    Base(){ *isBase = true; }

    Base(const Base& obj){ *isBase = *obj.isBase; }

    virtual Base* copy(){ return new Base(*this); }

    void print(){
        cout << "class: ";
        if(*isBase){ cout << "Base\n"; }
        else{ cout << "Derived\n"; }
    }
    
    virtual ~Base(){ delete isBase; };
};

class Derived : public Base {
public:
    Derived() { *isBase = false; }
    
    Derived* copy() { return new Derived(*this); }
    
    Derived(const Derived& obj) : Base(obj) { *isBase = *obj.isBase; }
    
    ~Derived(){};
};

Base** g_Array = new Base* [5];

void append(Base* obj, int i) { g_Array[i] = obj; }

int main()
{
    int size = 5;
    
    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0) { append(new Base, i); }
        else { append(new Derived, i); }
    }

    Base** new_array = new Base* [10];

    for (int i = 0; i < 5; i++)
        new_array[i] = g_Array[i]->copy();

    for (int i = 5; i < 10; i++)
    {
        new_array[i] = g_Array[i - 5]->copy();
        delete g_Array[i - 5];
    }
    
    delete[] g_Array;
    g_Array = new_array;
    
    for (int i = 0; i < 10; i++)
        g_Array[i]->print();
    
    for (int i = 0; i < 10; i++)
        delete g_Array[i];
    
    delete[] g_Array;
}
