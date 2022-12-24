#include <mutex>
#include <vector>
#include <thread>
#include <iostream>
#include <cmath>


using namespace std;
using namespace this_thread;


int main()
{

    setlocale(LC_ALL, "Russian");
    int N = 0, K = 0;
    float Q = 28, multiplication = 1, *multiplicationPointer = &multiplication;
    cout << "Введите количество трок матрицы: \n";
    cin >> K;
    cout << "Введите количество столбцов матрицы: \n";
    cin >> N;
    mutex threadMtx;
    float** arr = new float* [K+1];
    unsigned long start_time =  clock();
    thread tr([&threadMtx ,N ,K ,Q ,arr ,multiplicationPointer ]()
            {
            for (int i = 1; i <= K; ++i)
            {
                cout << "| ";
                arr[i] = new float[N+1];
                float summ = 0;
                for (int j = 1; j <= N; ++j)
                {
                    lock_guard<mutex> lockGuard(threadMtx);
                    arr[i][j] = j*Q/100;
                    summ += abs(arr[i][j]);
                    cout << round(arr[i][j]*10)/10 <<" ";
                }
                *multiplicationPointer *= summ;
            cout <<"| \n";
        }
    });

    tr.join();

    cout << "Итоговое прозведение:" << multiplication << "\n";
    cout << "Время работы програмы:" << clock() - start_time << "ms \n";

    return 0;
}
