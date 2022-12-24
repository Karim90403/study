#include <iostream>
#include <vector>
#include <string>
#include <vector>

using namespace std;

class Detail
{
    float size;
    string type;
    bool isGood;
    friend void append(vector<Detail*> v);
protected:
    Detail(){}
    Detail(float detailSize, string detailType, bool detailIsGood){
        size = detailSize;
        type = detailType;
        isGood = detailIsGood;
    }
    virtual void print(){
        cout << "Detail" << ": size-" << size << ", type-" << type << ", is detail good-" << isGood << '\n';
    }
public:
    virtual ~Detail(){}
};

class Build: public Detail
{
    int count_det;
    friend void append(vector<Detail*> v);
protected:
    Build(){}
    Build(int c){
        count_det = c;
    }
    void print(){
        cout << "Build" << ": " << count_det << '\n';
    }
};

void append(vector<Detail*> v){
    vector<string> details = *new vector<string>();
    details = {"Крыша", "Поршень", "Подшипник", "Процессор"};
    for(int i = 0; i < 4; i++){
        v.push_back(new Detail(i, details[i], i%2) );
        v.push_back(new Build(i) );
    }
    for(int i = 0; i < v.size(); i++)
        v[i]->print();
}

int main(){
    vector<Detail*> v;
    append(v);
    
    for(int i = 0; i < v.size(); i++)
        delete v[i];
    v.clear();
    
    return 0;
}
