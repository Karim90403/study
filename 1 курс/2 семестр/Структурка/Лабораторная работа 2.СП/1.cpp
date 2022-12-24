//
//  main.cpp
//  C++
//
//  Created by Карим Музафаров on 11.10.2021.
//
#include <iostream>
#include<ctime>
#include<cstdlib>
using namespace std;


int** CreateMatrix(int n)
{
    srand(time(0));
    int** NewMartix = new int* [n];
    for (int i = 0; i < n; i++) {
        NewMartix[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            NewMartix[i][j] = (rand() % 89) + 10;

        }
    }
    return NewMartix;
}

int** Transpose(int** Matrix,int n)
{
    int t;
    for(int i = 0; i < n; ++i)
    {
        for(int j = i; j < n; ++j)
        {
            t = Matrix[i][j];
            Matrix[i][j] = Matrix[j][i];
            Matrix[j][i] = t;
        }
    }
    int** TransposeMatrix = Matrix;
    return TransposeMatrix;
}


int main()
{
    setlocale(LC_ALL, "rus");
    int n,indexI,indexJ,sum=0,max=0;
    cout << "Введите n: ";
    cin >> n;
    int** Matrix = CreateMatrix(n);
    for(int i=0; i < n; i++)
    {
        cout << "|";
        for(int j=0; j < n; j++)
        {
            cout <<  " " << Matrix[i][j] <<  " ";
            if(Matrix[i][j]>max)
            {
                max = Matrix[i][j];
                indexI = i;
                indexJ = j;
            }
        }
        cout << "|" <<"\n";
    }
    cout << "Максимальный элемент = " << max << "\n";
    cout << "Его индекс:(" << indexI << "," << indexJ << ")"<< "\n" ;
    
    if(indexI > indexJ)
    {
        Matrix = Transpose(Matrix, n);
        cout << "Максимальный элемент выше главной диагонали"  << "\n";
        cout << "Транспонированная матрица: "  << "\n";
    }
    for(int i=0; i < n; i++)
    {
        for(int j=0; j < n; j++)
        {
            if(indexI > indexJ)
            {
                if(j==0)
                {
                    cout << "\n" << "|";
                }
                cout <<  " " << Matrix[i][j] <<  " ";
                if(j==n-1)
                {
                    cout << "|";
                }
            } else
            {
                if(indexI == i || indexJ == j)
                {
                    sum += Matrix[i][j];
                }
            }
        }
    }
    if(sum != 0)
    {
        cout << "Максимальный элемент не выше главной диагонали"  << "\n";
        cout << "Сумма элементов = " << sum;
    }
    cout << "\n";
    for(int i=0; i < n; i++)
    {
            delete[] Matrix[i];
    }
    
    delete[] Matrix;
    return 0;
}


