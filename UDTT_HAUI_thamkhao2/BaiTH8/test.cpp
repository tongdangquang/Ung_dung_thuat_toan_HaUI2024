#include <iostream>
#include <string>

using namespace std;
// Khai báo cấu trúc dữ liệu cho quạt bàn
struct Fan {
    string manufacturer;
    string color;
    int price;
};

// Hàm sắp xếp tăng dần theo giá bán
void sortFans(Fan fans[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (fans[i].price > fans[j].price) {
                Fan temp = fans[i];
                fans[i] = fans[j];
                fans[j] = temp;
            }
        }
    }
}

// Hàm G1 - Chiến lược tham lam để mua nhiều quạt nhất có thể
void G1(Fan fans[], int n, int p, int &c, Fan s[]) {
    sortFans(fans, n); // Sắp xếp danh sách quạt theo giá
    c = 0; // Khởi tạo số lượng quạt mua được là 0
    int totalCost = 0; // Tổng giá tiền của các quạt đã mua

    for (int i = 0; i < n; ++i) {
        if (totalCost + fans[i].price <= p) {
            if (p - totalCost > fans[i].price) cout << i << " hop le " << totalCost;
            s[c++] = fans[i]; // Thêm quạt vào danh sách mua được
            totalCost += fans[i].price; // Cập nhật tổng giá tiền
        }
    }
}

int main() {
    // Khởi tạo số tiền và danh sách quạt
    int p = 500; // Ví dụ số tiền là 500000
    int n = 7; // Ví dụ có 7 chiếc quạt
    Fan fans[] = {   
        {"Toshiba", "Xanh", 110},     
        {"Sharp", "Xám", 115},
        {"Sony", "Đen", 120},
        {"Hitachi", "Nâu", 125},
        {"Samsung", "Đỏ", 128},
        {"LG", "Vàng", 140},
        {"Panasonic", "Trắng", 150}

    };
    Fan s[12]; // Danh sách quạt mua được
    int c; // Số lượng quạt mua được

    // Gọi hàm G1
    G1(fans, n, p, c, s);

    // Hiển thị kết quả
    cout << "So luong quat mua duoc: " << c << endl;
    cout << "Danh sach quat mua duoc:" << endl;
    for (int i = 0; i < c; ++i) {
        p -= s[i].price;
        cout << "Hang san xuat: " << s[i].manufacturer << " - Gia ban: " << s[i].price << " - Tien con lai: " << p << endl;
    }

    return 0;
}