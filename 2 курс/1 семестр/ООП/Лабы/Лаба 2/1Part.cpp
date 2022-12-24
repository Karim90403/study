#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Car
{
public:
    Car() {}
    virtual ~Car() {}
};

class Porsche: public Car
{
    string model;
public:
    Porsche(string car) { model = car; }
    ~Porsche() { cout << "Porsche " << model << endl; }
};
class Tesla: public Car
{
    string model;
public:
    Tesla(string car) { model = car; }
    ~Tesla() { cout << "Tesla " << model << endl; }
};
class Lada: public Car
{
    string model;
public:
    Lada(string car){ model = car; }
    ~Lada() { cout << "Lada " << model << endl;}
};

int main()
{
    setlocale(LC_ALL, "Russian");
    vector <Car*> v;
    ifstream File("/Users/karimmuzafarov/Desktop/myfile.txt");
    string iter;
    cout << "Список автомобилей: \n";
    while (!File.eof())
    {
        File >> iter;
        if (iter == "Porsche") {
            File >> iter;
            v.push_back(new Porsche(iter));
        }

        else if (iter == "Tesla")
        {
            File >> iter;
            v.push_back(new Tesla(iter));
        }
        else if (iter == "Lada")
        {
            File >> iter;
            v.push_back(new Lada(iter));
        }
    }

    for (int i = 0; i < v.size(); i++)
        delete v[i];

return 0;
}
