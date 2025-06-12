#include <iostream>
#include <cstring>

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

    for (int i = n - 1; i >= 0; i--)
    {
        if (sum + a[i] <= C + a[i])
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

int char_in_string(char a, const char *P) {
    for (int i = 0; i < strlen(P); i++) {
        if (a == P[i]) return 1;
    }
    return -1;
}

int bmh(const char *P, const char *Q) {
    int n = strlen(Q);
    int m = strlen(P);

    // Tạo bảng dịch chuyển
    int temp[256];
    for (int i = 0; i < 256; ++i) {
        temp[i] = m;
    }
    for (int i = 0; i < m - 1; ++i) {
        temp[P[i]] = m - 1 - i;
    }

    // Tìm kiếm
    int i = m - 1;
    while (i < n) {
        int j = m - 1;
        while (j >= 0 && Q[i] == P[j]) {
            --i;
            --j;
        }
        if (j < 0) {
            // Tìm thấy chuỗi P tại vị trí i + 1
            return i + 1;
        }
        i += temp[Q[i]];
    }
    return -1; // Không tìm thấy
}

int main()
{
    int n = 10;
    double a[n] = {2.3, 5.1, 3.5, 6.7, 2.4, 4.5, 2.7, 8.4, 5.7, 3.9};

    double C = 25.4;

    const char *Q = "ngay 27 thang 07 la ngay thi ket thuc hoc phan mon ung dung thuat toan";
    const char *P = "ngay thi ket thuc hoc phan mon ung dung thuat toan";

    greedyAlgorithm(a, n, C);

    int pos = bmh(P, Q);

    if (pos != -1)
        cout << "Chuỗi P xuất hiện tại vị trí " << pos << endl;
    else
        cout << "Chuỗi P không xuất hiện trong chuỗi Q" << endl;
}