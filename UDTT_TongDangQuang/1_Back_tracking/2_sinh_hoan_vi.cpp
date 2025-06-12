#include <bits/stdc++.h>
using namespace std;

void show(int * x, int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}

void Try(int k, int * x, int n, bool *dd)
{
    for (int i = 1; i <= n; i++)
    {
       if(dd[i] == false)
        {
            x[k] = i;
            if(k == n)
                show(x, n);
            else
            {
                dd[i] = true;
                Try(k + 1, x, n, dd);
                dd[i] = false; // back track
            }
        }
    }
}

int main()
{
    int n;
    cout << "Nhap n = "; cin >> n;
    bool * dd = new bool[n + 1];
    int * x = new int[n + 1];
    for (int i = 1; i <= n; i++)
        dd[i] = false;
    
    Try(1, x, n, dd);
}