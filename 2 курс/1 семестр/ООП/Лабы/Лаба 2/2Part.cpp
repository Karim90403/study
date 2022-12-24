#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;
struct Leaks
{
      ~Leaks() { _CrtDumpMemoryLeaks(); }
};
Leaks _l;
class Class1 {
      int a;
public:
      Class1() { a = 0; }
      Class1(int a1) {
             a = a1;
      }
      Class1(const Class1& obj) {
          a = obj.a;
      }
      virtual Class1* my_copy() {
             Class1* new_obj = new Class1(*this);
             return new_obj;
      }
      virtual ~Class1() = default;
};
class Class2 : public Class1
{
    double b;
public:
    Class2()
    {
        b = 0.0;
    }
      Class2(double b1) {
          b = b1;
      }
      Class2(const Class2& obj) : Class1(obj) {
             b = obj.b;
      }
      Class2* my_copy() {
             Class2* new_obj = new Class2(*this);
             return new_obj;
      }
      ~Class2() = default;
};
int main() {
      vector <Class1*> DB;
      auto a = 5; auto b = 7.3;
      Class1* a1 = new Class1(a);
      Class2* b1 = new Class2(b);
      DB.push_back(a1->my_copy());
      DB.push_back(b1->my_copy());
      for (int i = 0; i < DB.size(); i++) {
          cout << typeid(DB[i]).name() << endl;
      }
      for (int i = 0; i < DB.size(); i++) {
             delete DB[i];
}
delete a1;
delete b1;
return 0;
}
