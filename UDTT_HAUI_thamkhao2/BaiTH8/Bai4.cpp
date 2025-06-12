#include <iostream>

using namespace std;

const int MAX_N = 10;

struct DienThoai {
    string nhanHieu;
    int kichThuoc;
    int giaBan;
};

// Hàm để tìm giá trị lớn nhất
int max(int a, int b) 
{
    return (a > b) ? a : b;
}

// Hàm để in bảng lựa chọn
void inBang(int K[][MAX_N + 1], int n, int s) 
{
    cout << "Bang lua chon:" << endl;
    cout << "\t";
    for (int i = 0; i <= s; i++) cout << i << "\t";
    cout << endl;
    for (int i = 0; i <= n; i++) {
        cout << i;
        for (int w = 0; w <= s; w++) {
            cout << "\t" << K[i][w] << " ";
        }
        cout << endl;
    }
}

// Thuật toán quy hoạch động để giải quyết bài toán Knapsack
void Q1(DienThoai d[], int s, int n, int &x, DienThoai a[]) {
    int K[MAX_N + 1][MAX_N + 1];

    // Xây dựng bảng K[][] theo cách bottom up
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= s; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (d[i - 1].kichThuoc <= w)
                K[i][w] = max(d[i - 1].giaBan + K[i - 1][w - d[i - 1].kichThuoc], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    // In bảng lựa chọn
    inBang(K, n, s);

    // Lưu tổng giá trị lớn nhất vào x
    x = K[n][s];

    // Truy vết để tìm danh sách các điện thoại
    int w = s;
    int count = 0;
    for (int i = n; i > 0 && x > 0; i--) {
        if (x == K[i - 1][w])
            continue;
        else {
            // Điện thoại này được chọn
            a[count++] = d[i - 1];
            // Trừ đi kích thước và giá của điện thoại được chọn
            x -= d[i - 1].giaBan;
            w -= d[i - 1].kichThuoc;
        }
    }
}

int main() {
    DienThoai d[MAX_N] = {
        {"iPhone X", 3, 1000},
        {"Samsung", 4, 1500},
        {"Xiaomi", 2, 700},
        {"iPhone 12", 5, 2000},
        {"Samsung Z", 6, 2200},
        {"Redmi", 3, 900},
        // Thêm các điện thoại khác theo định dạng
    };
    int n = 6; // Số lượng điện thoại
    int s = 9; // Kích thước túi
    DienThoai a[MAX_N]; // Danh sách điện thoại được chọn
    int x; // Tổng giá trị

    Q1(d, s, n, x, a);

    cout << "So luong dien thoai duoc chon: " << x << endl;
    cout << "Danh sach dien thoai: " << endl;
    for (int i = 0; i < n; i++) {
        if (a[i].giaBan > 0) {
            cout << "Nhan hieu: " << a[i].nhanHieu << ", Gia ban: " << a[i].giaBan << endl;
        }
    }

    return 0;
}