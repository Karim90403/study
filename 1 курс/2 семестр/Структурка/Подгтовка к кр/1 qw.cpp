//
//  main.cpp
//  C++
//
//  Created by Карим Музафаров on 11.10.2021.
//

#include <iostream>
#include <cstdlib>
#include <clocale>
#include <ctime>
using namespace std;
void ZM(int x[5])
{
    for (int i=0;i<5;i++)
    {
        x[i]=rand()%100;
        cout<<x[i]<<"  ";
    }
    cout << "\n";
}
int main()
{
    setlocale(LC_ALL, "rus");
    srand(time_t(0));
    int A[5],B[5],C[5];
    ZM(A);
    ZM(B);
    cout << "\n";
    for(int i; i<5; i++)
    {
        if(A[i]>B[i])
        {
            C[i]=A[i];
        } else
        {
            C[i]=B[i];
        }
        cout << C[i] << "  ";
    }
    cout << "\n";
    return 0;
}
