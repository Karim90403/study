#include <iostream>
#include <ctime>
#include <omp.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int N = 0, K = 0;
    float Q = 28, multiplication = 1, summ = 0;
    cout << "Введите количество трок матрицы: \n";
    cin >> K;
    cout << "Введите количество столбцов матрицы: \n";
    cin >> N;
    float** arr = new float* [K + 1];
    for (int i = 0; i <= K; i++)
        arr[i] = new float[N + 1];
    unsigned long start_time = clock();
#pragma omp parallel
    {
#pragma omp for schedule(static)
        for (int i = 1; i <= K; i++) {
            summ = 0;
            for (int j = 1; j <= N; j++) {
                arr[i][j] = j * Q / 100;
                summ += abs(arr[i][j]);
                
            }
            multiplication *= summ;
        }
    }
    for (int i = 1; i < K; i++) {
        for (int j = 1; j < N; j++) {
            cout << round(arr[i][j] * 10) / 10 << " ";
        }
        cout << endl;
    }
    cout << "Итоговое прозведение:" << multiplication << "\n";
    cout << "Время работы програмы:" << clock() - start_time << "ms \n";

    return 0;
