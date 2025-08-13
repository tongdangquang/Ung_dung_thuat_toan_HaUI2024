#include <bits/stdc++.h>
using namespace std;

double Tinh_tong(double a[], int left, int right)
{
    if (left > right)
        return 0;

    if (left == right)
        return a[left];

    int mid = (left + right)/2;
    double Tong_trai = Tinh_tong(a, left, mid);
    double Tong_phai = Tinh_tong(a, mid + 1, right);

    return Tong_trai + Tong_phai;
}

int main()
{
    int n = 10;
    double a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Tong a = " << Tinh_tong(a, 0, n - 1);
}