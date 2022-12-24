#include <iostream>
#include <vector>
using namespace std;

class Muzafarov
{
 float *f;
public:
 Muzafarov()
 {
 f = new float(12.2);
 }
 
 virtual ~Muzafarov()
 {
 delete f;
 }
};

class Karim: public Muzafarov
{
 int a;
public:
 Karim()
 {
 a = 1;
 }
 
};

vector<Muzafarov*> Wagon;
vector<Muzafarov*> Lorry;

void fill()
{
 Muzafarov *b = new Muzafarov[5];
 
 for(int i=0; i<5; i++)
 {
 Wagon.push_back(&b[i]);
 }
 
 delete[] b;
}

int main()
{
 fill();
 
 for(int i=0; i<5; i++)
 {
 Lorry.push_back(Wagon[i]);
 }
 
 return 0;
}
