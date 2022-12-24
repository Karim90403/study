//
//  main.cpp
//  C++
//
//  Created by Карим Музафаров on 11.10.2021.
//

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    float x;
    cout << "n=";
    cin>> n;
    cout << "x=";
    cin>> x;
    float f = abs(x*cos(x));
    float p = 1;
    for(int k=1; k<=n;k++)
        p*=((k+1)+x*sin(abs(x)));
    cout << "f=" << f + p <<"\n";
    cout << "p=" << p << "\n";

    return 0;
}
