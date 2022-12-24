//
//  main.cpp
//  C++
//
//  Created by Карим Музафаров on 11.10.2021.
//

#include <iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<fstream>

using namespace std;
int** CreateArray(int n, int m)
{
    srand(time(0));
    ofstream file;
    file.open("/Users/karimmuzafarov/Desktop/Лабораторная работа 1.СП/file.txt");
    int** arr= new int* [n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }
    
    cout << "\n";
    cout <<"Матрица: " << "\n";
    file << "\n";
    file <<"Матрица: " << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = rand() % 101 - 50;
            cout << arr[i][j] << "\t";
            file << arr[i][j] << "\t";
        }
        cout << "\n";
        file << "\n";
    }
    file.close();
    return arr;
}

double FindAvaerage(int** arr, int n, int m)
{
    float sum = 0;
    float counter = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] >= 0)
            {
                sum += arr[i][j];
                counter++;
            }
        }
    }
    float average = sum / counter;
    return average;
}
int Count(int** arr, int n, int m)
{
    ofstream file;
    file.open("/Users/karimmuzafarov/Desktop/Лабораторная работа 1.СП/file.txt", ios_base::app);
    int k=0;
    for (int i = 0; i < n; i++)
    {
        int k = 0;
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] >= 0)
                k++;
        }
        cout << "\n";
        cout<<"Количество неотрицательных элементов в строке  " << i + 1 << ":" << k;
        file << "\n";
        file << "Количество неотрицательных элементов в строке  " << i + 1 << ":" << k;
    }
    file.close();
    return k;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    
    int n = 0, m = 0;
    cout << "Введите количество строк в массивах:";
    cin >> n;
    cout << "Введите количество столбцов в массивах:";
    cin >> m;
    
    int** arr = CreateArray(n, m);
    float average = FindAvaerage(arr, n, m);
    Count(arr, n, m);
    cout << "\n";
    ofstream file;
    file.open("/Users/karimmuzafarov/Desktop/Лабораторная работа 1.СП/file.txt", ios_base::app);
    cout << "Среднее арифметическое неотрицательных элементов: " << average << "\n";
    file << "\n";
    file << "Среднее арифметическое неотрицательных элементов: " << average << "\n";
    file.close();
    int* Arr = new int[n] {};
    int** Arr1 = new int* [n];
    for (int i = 0; i < n; i++)
    {
        Arr1[i] = new int[m];
    }
    cout << "\n" << "\n";
    cout << "Задание 2" << "\n";
    cout << "Матрица:" << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            Arr1[i][j] = rand() % 21 - 10;
            cout << Arr1[i][j] << "\t";
        }
        cout << "\n";
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            sum += Arr1[i][j];
        }
    }
    cout << "\n";
    cout << "Сумма элементов матрицы: " << sum << "\n";
    for (int i = 0; i < n; i++)
    {
        if (i > m - 1)
            continue;
        
        int count = 0;
        for (int j = 0; j < m; j++)
        {
            if (i != j && Arr1[i][i] > Arr1[i][j])
                count++;
        }
        
        if (count == m - 1)
        {
            Arr[i] = 1;
        }
        else
        {
            Arr[i] = 0;
        }
    }
    cout << "\n";
    cout << "Полученный одномерный массив:" << "\n";
    for (int i = 0; i < n; i++)
    {
        if (i > m - 1)
            continue;
        cout << Arr[i] << " ";
    }
    for (int i = 0; i < n; i++)
    {
        delete[] Arr1[i];
    }
    delete[] Arr1;
    delete[] Arr;
    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    int** Arr2 = new int* [n];
    for (int i = 0; i < n; i++)
    {
        Arr2[i] = new int[m];
    }
    cout << "\n" << "\n";
    cout << "Матрица:" << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            Arr2[i][j] = rand() % 101 - 50;
            cout << Arr2[i][j] << "\t";
        }
        cout << "\n";
    }
    int sumMain = 0;
    cout << "\n" << "\n";
    cout << "Задание 3" << "\n";
    cout << "Изменённая матрица:" << "\n";
    if(n>m){
        for (int j = 0; j < m; j++)
            sumMain += Arr2[j][j];
    }
    for (int i = 0; i < n; i++)
    {
        if(n<=m){
            sumMain += Arr2[i][i];
        }
        for (int j = 0; j < m; j++)
        {
            if (j > i)
                Arr2[i][j] = abs(Arr2[i][j]);
            
            cout << Arr2[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
    cout << "Сумма элементов главной матрицы: " << sumMain << "\n";
    for (int i = 0; i < n; i++)
    {
        delete[] Arr2[i];
    }
    delete[] Arr2;
    return 0;
}
