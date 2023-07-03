#include <iostream>
#include <Windows.h> 
#include <cwchar>
#include <string>
#include <fcntl.h>
#include <fstream>
#include <io.h>
#include <vector>
#include <codecvt>
#include <locale>
#include <algorithm>

using namespace std;

struct Leaks {
    ~Leaks() { _CrtDumpMemoryLeaks(); }
};
Leaks _l_;

class Base
{
public:
    wstring name, post;
    int year, group;
    Base() {}
    Base(wstring n, int y, int g) {
        name = n;
        year = y;
        group = g;
    }
    void print() {
        wcout << name << " " << year << " " << post << " " << group << endl;
    }
    virtual ~Base() {}
};

class Engin : public Base
{
public:
    Engin() {}
    Engin(wstring p, wstring n, int y, int g) :Base(n, y, g) {
        post = p;
    }
    ~Engin() {}
};

class Lab : public Base
{
public:
    Lab() {}
    Lab(wstring p, wstring n, int y, int g) :Base(n, y, g) {
        post = p;
    }
    ~Lab() {}
};

class Preds : public Base
{
public:
    Preds() {}
    Preds(wstring p, wstring n, int y, int g) :Base(n, y, g) {
        post = p;
    }
    ~Preds() {}
};

class Tech : public Base
{
public:
    Tech() {}
    Tech(wstring p, wstring n, int y, int g) :Base(n, y, g) {
        post = p;
    }
    ~Tech() {}
};

struct 
{
    bool operator()(Base* a, Base* b) const { return a->year < b->year; }
} comp;

class DB
{
public:
    vector<Base*> database;
    DB()
    {
        wstring name, post, s;
        int year, group;
        _setmode(_fileno(stdout), _O_U16TEXT);
        _setmode(_fileno(stdin), _O_U16TEXT);
        _setmode(_fileno(stderr), _O_U16TEXT);
        wifstream file("read.txt");
        file.imbue(locale(file.getloc(), new codecvt_utf8 < wchar_t, 0x10ffff, consume_header >));

        while (!file.eof())
        {
            file >> s;
            name = s;
            file >> s;
            name += L' ' + s;
            file >> s;
            year = stoi(s.substr(0, 4));
            file >> s;
            post = s.substr(0, s.length() - 1);
            file >> s;
            file >> s;
            group = stoi(s);

            if (post == L"инженер")
            {
                database.push_back(new Engin(post, name, year, group));
            }

            if (post == L"лаборант")
            {
                database.push_back(new Lab(post, name, year, group));
            }

            if (post == L"председатель")
            {
                database.push_back(new Preds(post, name, year, group));
            }

            if (post == L"техник")
            {
                database.push_back(new Tech(post, name, year, group));
            }
        }
        file.close();
    }

    void print()
    {
        for (vector <Base*>::iterator it = database.begin(); it != database.end(); it++)
            (*it)->print();
    }

    void printingeners()
    {
        for (auto& i : database)
            if (i->post == L"инженер")
                i->print();
    }

    void printWOPreds()
    {
        sort(database.begin(), database.end(), [](Base *a, Base *b) { return a->year < b->year; });
        for (auto& i : database)
            if (i->post != L"председатель")
                i->print();
    }

    ~DB()
    {
        for (vector<Base*>::iterator it = database.begin(); it != database.end(); it++)
        {
            delete* it;
        }
    }
};

int main()
{
    DB db;
    wcout << "Ingeneers" << "\n";
    db.printingeners();
    wcout << "\n" << "Not predsedatels, wozrastanie" << "\n";
    db.printWOPreds();
    return 0;
}