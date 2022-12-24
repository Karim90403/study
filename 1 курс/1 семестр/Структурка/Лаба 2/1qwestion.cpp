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
    int N;
    float A;
    float B;
    float step;
    float x;
    float value;
    cout << "Введите A:";
    cin >> A;
    cout << "Введите B:";
    cin >> B;
    cout << "Введите N:";
    cin >> N;
    step = (B-A)/(N-1);
    for(int i=0;i<N;i++){
        x = A + i*step;
        value=(1.0/3.0)*sqrt(fabs(sin(x)))*cbrt(exp(0.12*x));
        cout <<"При Х равном:"<< x;
        cout<<"\n";
        cout<<"Выражение будет равно:"<<value;
        cout<<"\n";
    }
    return 0;
}
