#include<iostream>
#include <thread>
#include <ctime>
#include <mutex>
#include <cmath>

using namespace std;

float multiplication = 1, summ = 0;;
mutex s;

void Matrix(float start_i, int rows, int col)
{
    setlocale(LC_ALL, "ru");
    float Q = 28, arr;
    for (float i = start_i; i <= rows; i++)
    {
        summ = 0;
        for (float j = 1; j <= col; j++)
        {
            arr = j*Q/100;
            summ += abs(arr);
        }
        multiplication *= summ;
    }
    }

int main()
{
    setlocale(LC_ALL, "ru");
    int N, K;
    cout << "Введите количество трок матрицы: \n";
    cin >> K;
    cout << "Введите количество столбцов матрицы: \n";
    cin >> N;
    unsigned long start_time =  clock();
    thread t1(Matrix, (N / 8) * 0 + 1, (K / 8) * 1, N);
    thread t2(Matrix, (N / 8) * 1 + 1, (K / 8) * 2, N);
    thread t3(Matrix, (N / 8) * 2 + 1, (K / 8) * 3, N);
    thread t4(Matrix, (N / 8) * 3 + 1, (K / 8) * 4, N);
    thread t5(Matrix, (N / 8) * 4 + 1, (K / 8) * 5, N);
    thread t6(Matrix, (N / 8) * 5 + 1, (K / 8) * 6, N);
    thread t7(Matrix, (N / 8) * 6 + 1, (K / 8) * 7, N);
    thread t8(Matrix, (N / 8) * 7 + 1, N, N);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();

    cout << "Итоговое прозведение:" << multiplication << "\n";
    cout << "Время работы програмы:" << clock() - start_time << "ms \n";

    return 0;
}
