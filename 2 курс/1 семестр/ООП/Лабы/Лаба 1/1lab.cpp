#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
class Library
{
private:
 string Author;
 string Name;
 string Type;
public:
 Library(){}
 virtual int get_type() = 0;
 virtual ~Library(){}
};
 
class Art :public Library
{
private:
 string Author;
 string Name;
public:
 Art() {}
 Art(string Name, string Author, string Type)
 {
  cout << "Вы выбрали художественную книгу" << "\n";
  cout << "Укажите автора книги:";
  cin >> Author;
  cout << "Укажите название книги:";
  cin >> Name;
  cout << "\n";
 }
 int get_type()
 {
  return 1;
 }
 ~Art() {}
};
 
class Tehn :public Library
{
private:
 string Author;
 string Name;
 string Type;
public:
 Tehn(){}
 Tehn(string Name, string Author, string Type)
 {
  cout << "Вы выбрали техническую книгу" << "\n";
  cout << "Укажите автора книги:";
  cin >> Author;
  cout << "Укажите название книги:";
  cin >> Name;
  cout << "\n";
 }
 int get_type()
 {
  return 2;
 }
 ~Tehn(){}
};
 
int main()
{
 setlocale(0, "");
 vector < Library*> library;
 int SizeBooks;
 int sizeArt = 0,sizeTehn = 0;
 cout << "Введите кол-во книг, которое хотите взять:";
 cin >> SizeBooks;
 string Name, Author, Type;
 char NameType;
 for (int i = 0; i < SizeBooks; i++)
 {
  cout << "\n" << "Введите тип книги(Художественная - 1, или Техническая - 2):" << "\n";
  cin >> NameType;
  if (NameType == '1')
  {
      library.push_back(new Art(Name, Author, Type));
   sizeArt++;
  }
  else if (NameType == '2')
  {
      library.push_back(new Tehn(Name, Author, Type));
   sizeTehn++;
  }
  else if((NameType!='1')||(NameType != '2'))
  {
  cout << "\n" << "Введите 1 или 2 для выбора типа книги" << "\n";
  i--;
  }
 }
 cout << "Кол-во Художественных книг(without switch) = " << sizeArt << "\n" << "Кол-во Технических книг (without switch) = " << sizeTehn << "\n";
 sizeArt = 0; sizeTehn = 0;
 for (int i = 0; i < library.size(); i++)
 {
  switch (library[i] -> get_type())
  {
  case 1:
   sizeArt++;
   break;
  case 2:
   sizeTehn++;
   break;
  }
 }
 cout << "\n" << "Кол-во Художественных книг(using switch) = " << sizeArt << "\n" << "Кол-во Технических книг (using switch) = " << sizeTehn << "\n" << "\n";
 for (int i = 0; i < library.size(); i++)
 {
  delete library[i];
 }
}
