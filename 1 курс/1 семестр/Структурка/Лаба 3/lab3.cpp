//
//  main.cpp
//  C++
//
//  Created by Карим Музафаров on 11.10.2021.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <clocale>
using namespace std;
const int n = 5;
int main()
{
    setlocale(LC_ALL, "rus");
    ofstream file("/Users/karimmuzafarov/Desktop/fillle.txt");
    if (!file)
    {
    cout << "файл не открыт" << "\n";
    exit(-1);
    }
    srand(time(NULL));
    int sum = 0;
    int SumPositive = 0;
    int EqualZero = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int value = (rand()%100+(-50));
            if (i > 1)
            {
                sum += value;
                if(value >= 0){
                    if (value == 0)
                        EqualZero++;
                    else
                        SumPositive++;
                }
            }
                        
            file << value << '\t';
        }

        file << "\n";
    }

    file << "Сумма чисел: " << sum << "\n";
    file << "Число положительных чисел: " << SumPositive << "\n";
    file << "Число чисел равных нулю: " << EqualZero << "\n";
    file.close();

    ifstream file2("/Users/karimmuzafarov/Desktop/file.txt");
    if (!file2)
    {
    cout << "файл не открыт" << "\n";
    exit(-1);
    }
    while (file2)
    {
        char str[sizeof(file2)];
        file2.getline(str, sizeof(str));
        cout << str << "\n";
    }

    file2.close();
    return 0;
}

