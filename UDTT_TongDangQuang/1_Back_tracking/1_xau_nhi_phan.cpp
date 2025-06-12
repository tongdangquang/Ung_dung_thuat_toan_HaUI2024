#include <bits/stdc++.h>
using namespace std;

// hàm in kết quả
void show(int * x, int n)
{
    for (int i = 1; i <= n; i++)
        cout << x[i];
    cout << endl;
}

void Try(int k, int * x, int n)
{
    for (int i = 0; i <= 1; i++)
    {
        x[k] = i;
        if (k == n)
            show(x, n);
        else
            Try(k + 1, x, n);
    }
}

int main()
{
    int n;
    cout << "Nhap n = "; cin >> n;
    int * x = new int [n + 1];
    Try(1, x, n);
}
