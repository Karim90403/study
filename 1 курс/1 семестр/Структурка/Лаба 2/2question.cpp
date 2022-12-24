//
//  main.cpp
//  C++
//
//  Created by Карим Музафаров on 26.09.2021.
//

#include<iostream>
#include<cstdlib>
#include <cmath>

using namespace std;

int main()
{
    float n;
    float once;
    float all=1;
    float X;
    float summ;
    cout << "Введите n:";
    cin >> n;
    cout << "Введите X:";
    cin >> X;
    for(int k=1;k<=n;k++){
        once = (fabs(cos(sqrt(k*X)))+log(X))/pow(pow(X,2),1.0/3.0)+1.0/3.0;
        all = all*once;
        cout << "При k равном:" << k;
        cout << "\n";
        cout << "Значение выражения:" << once;
        cout << "\n";
        cout << "А значение произведения:" << all;
        cout << "\n";
    }
    summ = n*exp(X)+all;
    cout << "Общая сумма(Ответ):" << summ;
    cout << "\n";
    return 0;
}
