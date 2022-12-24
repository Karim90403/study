#include <iostream>

using namespace std;

class A{
public:
    A(){}
    ~A(){}
    virtual void print(){cout << "a" << endl;}
};

class B: public A{
public:
    void print(){cout << "b" << endl;}
};

void print_all(A**v, int size){
    //print all
    int i = 0;
    while (i < size) {
        (v[i]) -> print( );
        i = i+1;
    }
}

int main(){
    A a;
    B b;
    A m[2];
    m[1] = b;
    A*m0[2]={&m[0],&m[1]};
    print_all(m0,2);
    A*m1[2];
    m1[0] = new A;
    m1[1] = new B;
    print_all(m1, 2);
    return 1;
}
