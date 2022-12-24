//
//  main.cpp
//  C++
//
//  Created by Карим Музафаров on 11.10.2021.
//

#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    ofstream file("file.txt");
    
    if (!file)
    {
    cout << "файл не открыт" << "\n";
    exit(-1);
    }
    
    int n;
    cout << "Введите n: ";
    cin >> n;
    
    file << "n = " << n << "\n";
    float x;

    x = rand()%100 + rand()%100/100.;

    file << "Аргумент функции x = " << x << endl;

    for(int k = 1; k <= n; k++)
    x += (pow(x, 1./k) + abs(cos(x)));

    file << "Функция f(x) = " << x << "\n";

    file.close();

    ifstream file2("file.txt");

    while (file2)
    {
    char str[sizeof(file2)];
    file2.getline(str, sizeof(str));
    cout << str << "\n";
    }

    file2.close();

    return 0;
}
