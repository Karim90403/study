#include <iostream>
#include <cstdlib>
#include <clocale>
#include <ctime>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    int n,m,c;
    int counter = 0;
    cout << "Введите число строк: ";
    cin >> n;
    cout << "Введите число столбцоов: ";
    cin >> m;
    int** matrix = new int*[n];
    bool* array = new bool[m]{};
    
    for(int i =0; i < n; i++)
        matrix[i] = new int[m];
    
    for(int i=0; i < n; i++)
    {
        for(int j=0; j < m; j++)
        {
            matrix[i][j]=10+rand()%90;
        }
    }
    
    for(int i=0; i < n; i++)
    {
        cout << "|";
        for(int j=0; j < m; j++)
        {
            cout << " " << matrix[i][j] << " ";
        }
        cout << "|";
        cout << "\n";
    }
    
    cout << "Введите C: ";
    cin >> c;
    for(int j=0; j < m; j++)
    {
        for(int i=0; i < n; i++)
        {
            if (matrix[i][j]>c)
            {
                array[j]=true;
                counter++;
            }
        }
    }
    
    cout << "|";
    for(int j=0; j < m; j++)
    {
        cout << "  " << array[j] << " ";
    }
    delete[] array;
    
    cout << "|";
    cout << "\n";
    cout << "Количество чисел превышвющих C :" << counter;
    cout << "\n";
    
    for(int i=0; i < n; i++)
    {
            delete[] matrix[i];
    }
    
    delete[] matrix;
    return 0;
}
