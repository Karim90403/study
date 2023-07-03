#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
#include <string>
#include <algorithm>

struct Leaks { 
    ~Leaks() { 
        _CrtDumpMemoryLeaks(); 
    } 
};
Leaks _l_;

using namespace std;

class Muzafarov
{
public:
    int* x;
    Muzafarov() {
        x = new int(rand() % 100);
    }
    Muzafarov(const Muzafarov& obj) {
        x = new int(*(obj.x));
    }
    virtual Muzafarov* copy() {
        return new Muzafarov(*this);
    }
    virtual void print() {
        cout << typeid(*this).name() << endl << "x = " << *x << endl;
    }
    virtual ~Muzafarov() { 
        delete x; 
    }
};

class Karim : public Muzafarov
{
public:
    float* y;
    Karim() {
        y = new float(rand() % 100 + rand() % 100 / 100.);
    }
    Karim(const Karim& obj) :Muzafarov(obj) {
        y = new float(*(obj.y));
    }
    Muzafarov* copy() {
        return new Karim(*this);
    }
    void print() {
        Muzafarov::print();
        cout << "y = " << *y << endl;
    }
    ~Karim() { 
        delete y; 
    }
};

struct predicate
{
    bool operator()(Muzafarov* p1, Muzafarov* p2)const {
        return *(p1->x) < *(p2->x);
    }
};

class DB
{
    set<Muzafarov*, predicate> s;
public:
    DB() {}
    DB(int n) {
        for (int i = 0; i < n; i++) {
            s.insert(new Muzafarov);
            s.insert(new Karim);
        }
    }
    void deleteData() {
        for (Muzafarov* i : s)
            delete i;
        s.clear();
    }
    void copyData(const DB& db) {
        for (Muzafarov* i : db.s) {
            Muzafarov* no = i->copy();
            s.insert(no);
        }
    }
    DB(const DB& db) { copyData(db); }

    DB& operator= (const DB& db)
    {
        if (this == &db)
            return *this;
        deleteData();
        copyData(db);
        return *this;
    }

    void pushFirst(const DB& db) {
        int k = 0, l = db.s.size() / 2;

        for (Muzafarov* i : db.s) {
            string cn = typeid(*i).name();

            if (cn == "class Muzafarov" and k < l) {
                Muzafarov* no = i->copy();
                s.insert(no);
            }
            k++;
        }
    }

    void pushSecond(const DB& db) {
        int k = db.s.size() / 2, l = db.s.size();

        for (Muzafarov* i : db.s) {
            string cn = typeid(*i).name();

            if (cn == "class Karim" and k < l) {
                Muzafarov* no = i->copy();
                s.insert(no);
            }
            k++;
        }
    }

    void print() {
        for (Muzafarov* i : s)
            i->print();
    }

    ~DB() { deleteData(); }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    DB db1(4), db2, db3;

    db2.pushFirst(db1);
    db3.pushSecond(db1);

    db1.deleteData();

    cout << "db3" << endl; 
    db3.print();

    return 0;
}