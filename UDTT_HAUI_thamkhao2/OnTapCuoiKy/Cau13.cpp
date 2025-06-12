#include <iostream>
using namespace std;

double cdt(double a[], int left, int right) {
    if (left == right) {
        return (a[left] > 0) ? a[left] : 0;
    }

    int mid = (left + right) / 2;
    double tongTrai = cdt(a, left, mid);
    double tongPhai = cdt(a, mid + 1, right);

    return tongTrai + tongPhai;
}

int main() {
    int n = 10;
    double a[n] = {2.3, -5.1, 3.5, 6.7, -2.4, 4.5, -2.7, 8.4, -5.7, 3.9};
    double tong = cdt(a, 0, n - 1);
    cout << "Tổng các số duong trong mảng a: " << tong << endl;
    return 0;
}