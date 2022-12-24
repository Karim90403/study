//
//  main.cpp
//  C++
//
//  Created by Карим Музафаров on 11.10.2021.
//

#include <iostream>
#include <cstdlib>
#include <clocale>
#include <string>

using namespace std;
struct ZNAK
{
    string NAME, ZODIAK;
    int BDAY[3];
};
int main()
{
    setlocale(LC_ALL, "rus");
    ZNAK user;
    cout << "Введите имя и фамилию:" << "\n";
    getline(cin,user.NAME);
    cout << "Введите знак зодиака:" << "\n";
    getline(cin,user.ZODIAK);
    cout << "Введите дату рождения:";
    for(int i=0;i<3;i++)
    {
        cin >> user.BDAY[i];
    }
    cout << user.NAME<<"\n";
    cout << user.ZODIAK<<"\n";
    for(int i=0;i<3;i++)
    {
        cout << user.BDAY[i] << ".";
    }
    cout << "\n";
    return 0;
}
