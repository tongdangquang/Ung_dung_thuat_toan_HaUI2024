#include <iostream>

using namespace std;

// Hàm tính tổng các số lẻ trong mảng a
int tinhTongLe(int a[], int n) {
    if (n == 0) 
        return 0;

    int tong = tinhTongLe(a, n - 1);

    if (a[n - 1] % 2 != 0) 
        tong += a[n - 1];

    return tong;
}

int A(int a[], int n)
{
    if(n == 0)
        return 0;

    int tong = 0;
    if(a[n - 1] % 2 != 0)
        tong += a[n - 1];

    return tong + A(a, n - 1);
}

int main() {
    int n = 10;
    int a[n] = {5, 3, 9, 2, 4, 6, 4, 8, 8, 3};
    cout << "Tổng các số lẻ trong mảng là: " << A(a, n) << endl;
    return 0;
}