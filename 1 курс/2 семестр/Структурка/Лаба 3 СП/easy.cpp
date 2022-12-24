//
//  main.cpp
//  C++
//
//  Created by Карим Музафаров on 11.10.2021.
//
#include <iostream>
#include <cstdlib>
#include<clocale>

using namespace std;

class BaseMatrixProcessor
{
protected:
    int n, m;
    
public:
    int** Matrix;
    BaseMatrixProcessor(int n, int m)
    {
        this->n = n;
        this->m = m;
        Matrix = new int*[this->n];
        for(int i = 0; i < this->n; i++)
            Matrix[i] = new int[this->m];
        
        cout<<"Создана матрица"<<endl;
    }
    
    ~BaseMatrixProcessor()
    {
        for(int i =0; i < n; i++)
            delete[] Matrix[i];
        
        delete[] Matrix;
        cout<<"Удалена матрица"<<endl;
    }
};

class DerivedMatrixProcessor : public BaseMatrixProcessor
{
public:
    DerivedMatrixProcessor(int n, int m) : BaseMatrixProcessor(n,m)
    {
        for(int i =0; i < n; i++)
        {
            for(int j =0; j < m; j++)
            {
                Matrix[i][j] = rand()%190 - 100;
                cout<<Matrix[i][j]<<'\t';
            }
            
            cout<<endl;
        }
        
        cout<<endl;
    }
};

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
    DerivedMatrixProcessor OurMatrix(n,m);
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (0 > OurMatrix.Matrix[i][j])
            {
                if (OurMatrix.Matrix[i][j] > max)
                {
                    max= OurMatrix.Matrix[i][j];
                }
            } else if (0 < OurMatrix.Matrix[i][j])
            {
                if (OurMatrix.Matrix[i][j] < min)
                {
                    min = OurMatrix.Matrix[i][j];
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
                if (0 > OurMatrix.Matrix[i][j])
                {
                    OurMatrix.Matrix[i][j] = abs(OurMatrix.Matrix[i][j]);
                }
                cout << OurMatrix.Matrix[i][j] << " ";
            }
            cout << "\n";
        }
        
    }else {
        cout << "Разница значений(по модулю) меньше заданного значения" << "\n";
    }
    return 0;
}
