#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

double summ(vector<double> v, int p) {
    double summ = 0;
    for (int i = 0; i < v.size(); i++)
        summ += pow(v[i], p);
    return summ;
}

void print(vector<double> v) {
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
    cout << endl;
}

vector<double> gauss(vector< vector<double> > a, vector<double> b)
{
    double max, t;
    int k = 0, max_i = 0, n = b.size();
    const double accuracy = 0.00001;
    vector<double> ans(n);
    while (k < n)
    {
        max = abs(a[k][k]);
        max_i = k;
        for (int i = k + 1; i < n; i++)
        {
            if (abs(a[i][k]) > max)
            {
                max = abs(a[i][k]);
                max_i = i;
            }
        }
        if (max < accuracy)
        {
            cout << "bad data" << endl;
            return {};
        }
        swap(b[k], b[max_i]);
        swap(a[k], a[max_i]);
        for (int i = k; i < n; i++)
        {
            t = a[i][k];
            if (abs(t) < accuracy)
                continue;
            for (int j = 0; j < n; j++)
                a[i][j] /= t;
            b[i] /= t;
            if (i == k)
                continue;
            for (int j = 0; j < n; j++)
                a[i][j] -= a[k][j];
            b[i] -= b[k];
        }
        k++;
    }
    for (k = n - 1; k >= 0; k--)
    {
        ans[k] = b[k];
        for (int i = 0; i < k; i++)
            b[i] -= a[i][k] * ans[k];
    }
    return ans;
}

int main()
{
    vector< vector<double> > A;
    vector<double> ans, B, yx, yx2,
        x = { 0.168,
            0.115,
            0.928,
            0.962,
            0.129,
            0.762,
            0.646,
            0.055,
            0.186,
            0.563
            },
        y = { 5.524,
            5.605,
            3.264,
            3.072,
            5.497,
            3.579,
            3.645,
            5.667,
            5.131,
            4.127 
            };
    double lenn = x.size();
    for (int i = 0; i < lenn; i++)
    {
        yx.push_back(x[i] * y[i]);
        yx2.push_back(x[i] * x[i] * y[i]);
    }
    B = { summ(y,1), summ(yx, 1) };
    A = { {summ(x,1), lenn},
             {summ(x,2),summ(x,1)} };
    cout << "Coefficients of the approximating function for the linear case" << endl;
    ans = gauss(A, B);
    print(ans);
    B = { summ(y,1), summ(yx, 1), summ(yx2, 1) };
    A = { {summ(x,2), summ(x,1), lenn},
            {summ(x,3), summ(x,2),summ(x,1)},
            {summ(x,4), summ(x,3),summ(x,2)} };

    cout << "Coefficients of the approximating function for the square case" << endl;
    ans = gauss(A, B);
    print(ans);

    return 0;
}