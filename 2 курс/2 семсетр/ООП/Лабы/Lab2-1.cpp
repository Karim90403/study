#include <iostream>
#include <vector>

using namespace std;

class Lib {

public:
    Lib() {}
    Lib(int Data, string Name, int Page) {
    }
    virtual Lib* Copy() {
        return new Lib(*this);
    }
    Lib(const Lib& obj) {

    }
    virtual int Get_data() {
        return 0;
    }
    virtual string Get_name() {
        return "";
    }
    virtual int Get_page() {
        return 0;
    }
    virtual void Print() {}
    virtual ~Lib() {}
};

class News : public Lib {
    int data;
    string name;
    int page;
public:
    News() {}
    News(int Data, string Name, int Page) {
        data = Data;
        name = Name;
        page = Page;
    }
    News* Copy() {
        return new News(*this);
    }
    News(const News& obj) {
        data = obj.data;
        name = obj.name;
        page = obj.page;
    }
    int Get_data() {
        return data;
    }
    string Get_name() {
        return name;
    }
    int Get_page() {
        return page;
    }
    void Print() {
        cout << data << "---" << name << "---" << "page" << endl;
    }
    ~News() {}
};

class Book : public Lib {
    int data;
    string name;
    int page;
public:
    Book() {}
    Book(int Data, string Name, int Page) {
        data = Data;
        name = Name;
        page = Page;
    }
    Book* Copy() {
        return new Book(*this);
    }
    Book(const Book& obj) {
        data = obj.data;
        name = obj.name;
        page = obj.page;
    }
    int Get_data() {
        return data;
    }
    string Get_name() {
        return name;
    }
    int Get_page() {
        return page;
    }
    void Print() {
        cout << data << "---" << name << "---" << "page" << endl;
    }
    ~Book() {}
};

class FirstLib : public Lib {
    int data;
    string name;
    int page;
public:
    FirstLib() {}
    FirstLib(int Data, string Name, int Page) {
        data = Data;
        name = Name;
        page = Page;
    }
    FirstLib* Copy() {
        return new FirstLib(*this);
    }
    FirstLib(const FirstLib& obj) {
        data = obj.data;
        name = obj.name;
        page = obj.page;
    }
    int Get_data() {
        return data;
    }
    string Get_name() {
        return name;
    }
    int Get_page() {
        return page;
    }
    void Print() {
        cout << data << "---" << name << "---" << "page" << endl;
    }
    ~FirstLib() {}
};

class SecondLib : public Lib {
    int data;
    string name;
    int page;
public:
    SecondLib() {}
    SecondLib(int Data, string Name, int Page) {
        data = Data;
        name = Name;
        page = Page;
    }
    SecondLib* Copy() {
        return new SecondLib(*this);
    }
    SecondLib(const SecondLib& obj) {
        data = obj.data;
        name = obj.name;
        page = obj.page;
    }
    int Get_data() {
        return data;
    }
    string Get_name() {
        return name;
    }
    int Get_page() {
        return page;
    }
    void Print() {
        cout << data << "---" << name << "---" << "page" << endl;
    }
    ~SecondLib() {}
};

int main()
{
    vector<Lib*> v112;
    vector<Lib*> v362;
    v112.push_back(new Book(2003, "LordOfRings", 1000));
    v112.push_back(new Book(2004, "LordOfRings", 1000));
    v112.push_back(new News(2005, "GarryPottter1", 500);
    v112.push_back(new SecondLib(2006, "GarryPottter1", 500));
    v112.push_back(new SecondLib(2008, "GarryPottter2", 600));
    v112.push_back(new FirstLib(2010, "GarryPottter3", 700));
    v362.push_back(new Book(2016, "GarryPottter4", 800));
    v362.push_back(new News(2018, "GarryPottter5", 900));
    v362.push_back(new SecondLib(2018, "GarryPottter6", 500));
    v362.push_back(new FirstLib(2020, "GarryPottter7", 500));
    cout << "362 - library" << endl;
    for (int i = 0; i < v362.size(); i++) {
        v362[i]->Print();
    }
    cout << endl;
    cout << "112 - library" << endl;
    for (int i = 0; i < v112.size(); i++) {
        v112[i]->Print();
    }
    cout << endl;
    int check = 0;
    for (int i = 0; i < v112.size(); i++) {
        for (int j = 0; j < v362.size(); j++) {
            if (v112[i]->Get_data() == v362[j]->Get_data() && v112[i]->Get_name() == v362[j]->Get_name() &&
                v112[i]->Get_page() == v362[j]->Get_page()) {
                check = 1;
            }
        }
        if (check == 0) {
            v362.push_back(v112[i]->Copy());
        }
        check = 0;
    }
    cout << "362 - library" << endl;
    for (int i = 0; i < v362.size(); i++) {
        v362[i]->Print();
    }
    for (int i = 0; i < v362.size(); i++)delete v362[i];
    for (int i = 0; i < v112.size(); i++)delete v112[i];
}
