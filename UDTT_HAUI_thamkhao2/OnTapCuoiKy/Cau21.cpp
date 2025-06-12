#include <iostream>
#include <string.h>

using namespace std;

void sort(double a[], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i] < a[j]) {
                double temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}

void greedyAlgorithm(double a[], int n, double C)
{
    sort(a, n);
    for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
    double sum = 0;
    int D = 0, c = 0;
    double kq[n];

    for (int i = 0; i < n; i++)
    {
        if (sum + a[i] <= C)
        {
            kq[c] = a[i];
            sum += a[i];
            D++;
            c++;
        }
    }

    cout << "D = " << D << endl;
    cout << "M = " << sum << endl;
    cout << "Danh sach ket qua: ";
    for (int i = 0; i < c; i++) cout << kq[i] << " ";
    cout << endl;
}

bool bmh(const char *Q, const char *P) {
    int n = 0, m = 0;
    // Đếm độ dài của chuỗi P và Q
    while (P[m] != '\0') ++m;
    while (Q[n] != '\0') ++n;
    for (int i = 0; i <= m - n; ++i) {
        int j;
        for (j = 0; j < n; ++j)
            if (P[i + j] != Q[j])
                break;
        if (j == n) return true; // Tìm thấy chuỗi Q trong chuỗi P
    }
    return false; // Không tìm thấy chuỗi Q trong chuỗi P
}

int main()
{
    int n = 10;
    double a[n] = {2.3, 5.1, 3.5, 6.7, 2.4, 4.5, 2.7, 8.4, 5.7, 3.9};

    double C = 25.4;

    const char *P = "ngay 25 thang 6 la ngay binh thuong";
    const char *Q = "ngay 25 thang 6 la ngay binh thuong";

    greedyAlgorithm(a, n, C);

    if (bmh(Q, P))
        cout << "Q là chuỗi con của P." << endl;
    else
        cout << "Q không là chuỗi con của P." << endl;
}