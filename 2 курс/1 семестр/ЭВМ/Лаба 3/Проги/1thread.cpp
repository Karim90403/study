#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;
int main()
{
    unsigned long start_time =  clock();
    setlocale(LC_ALL, "Russian");
    int N, K, summ = 0;
    double Q = 28, multiplication = 0;
    cout << "Введите количество трок матрицы: \n";
    cin >> K;
    cout << "Введите количество столбцов матрицы: \n";
    cin >> N;
    double** arr = new double* [K+1];
    for (int i = 1; i <= K; i++)
    {
        cout <<"| ";
        arr[i] = new double[N+1];
        for (int j = 1; j <= N; j++)
        {
            arr[i][j] = j*Q/100;
            summ += abs(arr[i][j]);
            cout << round(arr[i][j]*10)/10 <<" ";
        }
        multiplication *= summ;
        cout <<"| \n";
    }
    cout << "Итоговое прозведение:" << multiplication << "\n";
    cout << "Время работы програмы:" << clock() - start_time << "ms \n";
}
