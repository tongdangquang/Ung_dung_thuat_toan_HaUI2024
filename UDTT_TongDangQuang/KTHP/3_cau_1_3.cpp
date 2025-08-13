#include <bits/stdc++.h>
using namespace std;

double Tong(double a[], int left, int right)
{
    if (left > right)
        return 0;

    if (left == right)
    {
        if (a[left] >= 0)
            return a[left];
        else
            return 0;
    } 
    int mid = (left + right)/2;
    double Tong_trai = Tong(a, left, mid);
    double Tong_phai = Tong(a, mid + 1, right);
    return Tong_trai + Tong_phai;
}

int main()
{
    int n = 10;
    double a[n] = {2.3, -5.1, 3.5, 6.7, -2.4, 4.5, -2.7, 8.4, -5.7, 3.9};
    cout << "Tong cac so duong = " << Tong(a, 0, n - 1) << endl;
}
