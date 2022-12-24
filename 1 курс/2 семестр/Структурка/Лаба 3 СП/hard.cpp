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

class BaseArrayProcessor
{
protected:
    float** array;
    int n, m, diff, val, max=-100, min=100;
    
public:
    BaseArrayProcessor(int n, int m)
    {
        this->n = n;
        this->m = m;
        array = new float*[this->n];
        for(int i = 0; i < this->n; i++)
            array[i] = new float[this->m];
            
        cout<<"Матрица создана"<<endl;
    }
   
   ~BaseArrayProcessor()
   {
       for(int i =0; i < n; i++)
            delete[] array[i];
       
       delete[] array;
   }
};

class DerivedArrayProcessor : public BaseArrayProcessor
{
private:
    void GenerateMatrixElements()
    {
        for(int i =0; i < n; i++)
        {
            for(int j =0; j < m; j++)
            {
                array[i][j] = rand() % 190 - 100;
            }
        }
        
        cout<<endl;
    }
    
    bool ChangeMaxMinItem()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (0 > array[i][j])
                {
                    if (array[i][j] > max)
                    {
                        max= array[i][j];
                    }
                } else if (0 < array[i][j])
                {
                    if (array[i][j] < min)
                    {
                        min = array[i][j];
                    }
                }
            }
        }
        if (max == -100 || min == 100)
        {
            cout << "Не повезло, в массиве числа принадлежащие только одному знаку(("<< "\n";
            return true;
        }
        cout << "Максимальный отрицательный элемент = " << max << "\n";
        cout << "Минимальный положительный элемент = " << min << "\n";
        return false;
    }
    
    void ShowMatrix()
    {
        for(int i =0; i < n; i++)
        {
            for(int j =0; j < m; j++)
                cout<<array[i][j]<<' ';
            cout<<endl;
        }
        
        cout<<endl;
    }
    
    void EnterComparisonValue()
    {
        cout << "Величина: " ;
        cin >> val;
    }
    

    
    bool ChangeMatrix()
    {
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
                    if (0 > array[i][j])
                    {
                        array[i][j] = abs(array[i][j]);
                    }
                }
            }
            return true;
        }else {
            cout << "Разница значений(по модулю) меньше заданного значения" << "\n";
            return false;
        }
    }
public:
    DerivedArrayProcessor(int n, int m) : BaseArrayProcessor(n, m)
    {
        srand(time(0));
        GenerateMatrixElements();
    }
    
    void Run()
    {
        ShowMatrix();
        if(ChangeMaxMinItem())
        {
            cout<<"Условие не выполнено. Завершение программы."<<endl;
            return;
        }
        EnterComparisonValue();
        if(ChangeMatrix())
        {
            ShowMatrix();
        }
    }
    
    ~DerivedArrayProcessor()
    {
        cout<<"Матрица удалена"<<endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    int n, m;
    cout << "Строки: ";
    cin >> n;
    cout << "Столбцы: ";
    cin >> m;
    
    DerivedArrayProcessor arrayProcessor(n, m);
    arrayProcessor.Run();
    return 0;
}




