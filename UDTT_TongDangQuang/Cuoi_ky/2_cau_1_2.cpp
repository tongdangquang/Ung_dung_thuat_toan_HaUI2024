#include <bits/stdc++.h>
using namespace std;

int T(int a[], int n)
{
    if (n == 0)
        return 0;
    else
    {
        if (a[n - 1] % 2 != 0)
            return a[n - 1] + T(a, n - 1);
        else   
            return T(a, n - 1);
    }
}

int main()
{
    int n = 10;
    int a[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    cout << "Tong so le = " << T(a, n) << endl;
}