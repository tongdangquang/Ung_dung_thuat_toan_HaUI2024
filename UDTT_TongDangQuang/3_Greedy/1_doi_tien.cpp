#include <bits/stdc++.h>
using namespace std;

void Sort_desc(int * x, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if(x[i] < x[j])
                swap(x[i], x[j]);
        }
    }
}

bool Doi_tien(int * x, int n, long m, int * s)
{
    Sort_desc(x, n);
    int i = 0;
    while(i < n && m > 0)
    {
        s[i] = m / x[i];
        m = m % x[i];
        i++;
    }
    return (m > 0) ? false : true;
}


int main()
{
    int n = 5;
    int * x = new int [5] {1, 5, 10, 25, 100};
    int * s = new int [n]();
    long m = 63;
    int c = 0;
    if(Doi_tien(x, n, m, s))
    {
        cout << "SO DONG XU CAN DOI: " << endl;
        cout << left << setw(15) << "MENH GIA" << left << setw(10) << "SO LUONG" << endl;
        for (int i = 0; i < n; i++)
        {
            if(s[i] != 0)
            {
                c += s[i];
                cout << left << setw(15) << x[i] << left << setw(10) << s[i] << endl;
            }
        }
        cout << "----------------------------------------------------" << endl;
        cout << "Tong so dong xu can doi la: " << c << endl;
    }
}