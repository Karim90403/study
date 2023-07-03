#include <iostream>
#include <list>

using namespace std;

struct Leaks {
	~Leaks() { _CrtDumpMemoryLeaks(); }
};
Leaks l_;

class Muzafarov
{
	list<int*> Nums;
public:
	Muzafarov()
	{
		Nums = list<int*>{ new int(1),new int(2) };
	}

	virtual ~Muzafarov()
	{
		for (list<int*>::iterator it = Nums.begin(); it != Nums.end(); it++)
		{
			delete* it;
		}
	}
};

class Karim : public Muzafarov
{
	list<string*>* Texts;
public:
	Karim()
	{
		Texts = new list<string*>{ new string("Первая строка"), new string("Вторая строка") };
	}
	~Karim() 
	{
		for (list<string*>::iterator it = Texts->begin(); it != Texts->end(); ++it) 
		{
			delete (*it);
		}
		delete Texts;
	}
};

int main()
{
	list<Muzafarov*> DB;
	Muzafarov* item1 = new Muzafarov();
	Karim* item2 = new Karim();
	DB.push_back(item1);
	DB.push_back(item2);
	list<Muzafarov*> DB2(move(DB));
	cout << "DB2 contains:";
	for (auto &x : DB2) cout << ' ' << typeid(*x).name();
	cout << "\n";
	for (list<Muzafarov*>::iterator it = DB.begin(); it != DB.end(); ++it)
	{
		delete (*it);
	}
	for (list<Muzafarov*>::iterator it = DB2.begin(); it != DB2.end(); ++it)
	{
		delete (*it);
	}
	return 0;
}