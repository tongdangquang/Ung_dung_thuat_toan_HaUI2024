#include <iostream>
#include <vector>

using namespace std;

struct ChuyenBay {
    string soHieu;
    int giaVe;
    int soGhe;
};

// Recursive algorithm
void A1(vector<ChuyenBay> b, int n) {
    if (n >= 0) {
        if (b[n].giaVe > 700000)
            cout << b[n].soHieu << " " << b[n].giaVe << " " << b[n].soGhe << endl;
        A1(b, n - 1);
    }
}

// Divide and conquer algorithm
int A2(vector<ChuyenBay> b, int left, int right) {
    if (left == right) return b[left].giaVe;

    int mid = left + (right - left) / 2;
    int min_left = A2(b, left, mid);
    int min_right = A2(b, mid + 1, right);
    return min(min_left, min_right);
}

// Backtracking algorithm
void show(vector<ChuyenBay> b, int x[], int k) {
    for (int i = 1; i <= k; i++)
        cout << b[x[i] - 1].soHieu << " ";
    cout << endl;
}

void Try(vector<ChuyenBay> b, int i, int x[], int n, int k) {
    for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
        x[i] = j;
        if (i == k) {
            show(b, x, k);
        } else {
            Try(b, i + 1, x, n, k);
        }
    }
}

int main() {
    int n = 6;
    vector<ChuyenBay> b = {
        {"VN005", 300000, 200},
        {"VN006", 400000, 200},
        {"VN003", 500000, 180},
        {"VN001", 600000, 150},
        {"VN014", 700000, 150},
        {"VN015", 850000, 150}
    };

    cout << "Chuyen bay co gia ve lon hon 700000 la: \n";
    A1(b, n - 1);

    cout << "Chuyen bay co gia ve thap nhat la: \n";
    int min_giaVe = A2(b, 0, n - 1);
    for (int i = 0; i < n; i++)
        if (b[i].giaVe == min_giaVe) {
            cout << b[i].soHieu << " " << b[i].giaVe << " " << b[i].soGhe << endl;
        }

    cout << "Tat ca cac phuong an khac nhau de chon ra 4 chuyen bay tu danh sach la: \n";
    int k = 4;
    int x[k + 1] = {0}; // Initialize the array with zeros
    Try(b, 1, x, n, k);

    return 0;
}
