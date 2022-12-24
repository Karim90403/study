#include <iostream>
#include <vector>
using namespace std;


class Parent
{
public:
    float* f;
    Parent() {
        f = new float(123.45);
    }

    virtual ~Parent(){
        delete f;
    }
    
    Parent(const Parent& object) {
        f = new float(*object.f);
    }
    
    virtual Parent* copy(){
        return new Parent(*this);
    }
};

class Child: public Parent
{
    ~Child() {}
    virtual Parent* copy(){
        return new Child(*this);
    }

};

int main()
{
    vector<Parent*> data1;

    for(int i = 0; i < 8; i++){
        if (i%2)
            data1.push_back(new Parent);
        else
            data1.push_back(new Child);
    }
    
    vector<Parent*> data2;

    for (vector <Parent*>::iterator it = data1.begin(); it != data1.end(); ++it) {
        Parent* new_object = (*it)->copy();
        data2.insert(data2.end(), new_object);
    }
    
    for(int i = 0; i < data1.size(); i++)
    {
        delete data1[i];
    }
    
    for(int i = 0; i < data2.size(); i++)
    {
        delete data2[i];
    }
    
    return 0;
}
