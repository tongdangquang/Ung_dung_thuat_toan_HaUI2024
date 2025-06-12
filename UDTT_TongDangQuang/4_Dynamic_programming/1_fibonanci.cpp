#include <bits/stdc++.h>
using namespace std;

int fibonanci(int n)
{
    if(n <= 1)
        return 1;

    int * fib = new int [n + 1];
    fib[0] = fib[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}

int main()
{
    int n;
    cout << "Nhap n = "; cin >> n;
    cout << "Fibonanci(" << n << ") = " << fibonanci(n) << endl;

}