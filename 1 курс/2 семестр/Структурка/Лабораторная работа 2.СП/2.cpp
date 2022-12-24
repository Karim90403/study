//
//  main.cpp
//  C++
//
//  Created by Карим Музафаров on 11.10.2021.
//
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>
using namespace std;
int** CreateMatrix(int n, int m)
{
    int** NewMartix = new int* [n];
    for (int i = 0; i < n; i++)
    {
        NewMartix[i] = new int[m];
    }

    return NewMartix;
}
void FillingMatrix(int** NewMartix, int n, int m)
{
    srand(time(0));
    cout << "Mатрица: " << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            NewMartix[i][j] = rand() % 198 - 99;
            cout << NewMartix[i][j] << "\t";
        }
        cout <<"\n";
    }
}
int main()
{
    setlocale(LC_ALL, "rus");
    int n,m,val,diff,min=100,max=-100;
    cout << "Строки: ";
    cin >> n;
    cout << "Столбцы: ";
    cin >> m;
    cout << "Величина: " ;
    cin >> val;
    cout << "\n";
    int** Matrix = CreateMatrix(n, m);
    FillingMatrix(Matrix, n, m);
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (0 > Matrix[i][j])
            {
                if (Matrix[i][j] > max)
                {
                    max= Matrix[i][j];
                }
            } else if (0 < Matrix[i][j])
            {
                if (Matrix[i][j] < min)
                {
                    min = Matrix[i][j];
                }
            }
        }
    }
    if (max == -100 || min == 100)
    {
        cout << "Не повезло, в массиве числа принадлежащие только одному знаку(("<< "\n";
        return 0;
    }
    cout << "Максимальный отрицательный элемент = " << max << "\n";
    cout << "Минимальный положительный элемент = " << min << "\n";
    diff = abs(abs(max) - min);
    cout << "Разница значений(по модулю) = " << diff << "\n";
    if (diff < val)
    {
        cout << "Разница значений(по модулю) больше заданного значения" << "\n";
        cout << "Изменённая матрица" << "\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (0 > Matrix[i][j])
                {
                    Matrix[i][j] = abs(Matrix[i][j]);
                }
                cout << Matrix[i][j] << " ";
            }
            cout << "\n";
        }

    }else {
        cout << "Разница значений(по модулю) меньше заданного значения" << "\n";
    }
    for(int i=0; i < n; i++)
    {
            delete[] Matrix[i];
    }
    
    delete[] Matrix;
    return 0;
}
