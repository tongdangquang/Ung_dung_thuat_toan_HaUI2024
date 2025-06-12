#include <iostream>

#define MAX 6 // so luong phan tu co trong mang max = 10
#define MIN 4 // so luong phan tu de yeu cau chon ra

using namespace std;

// khai bao cho thuat toan quay lui
int x[MAX], k = MIN, n = MAX;
int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
int sum1 = 0;

struct ManHinh
{
    string hsx;
    int gia;
    int namSX;
};

ManHinh mh[] = {
    {"DELL", 100, 2020}, // 1
    {"ASUS", 150, 2021}, // 2
    {"AOGS", 120, 2019}, // 3
    {"DELL", 200, 2022},
    {"DELL", 160, 2021},
    {"ASUS", 130, 2019}, // 6
    {"AOGS", 220, 2021},
    {"DELL", 180, 2024},
    {"ASUS", 250, 2023},
    {"AOGS", 270, 2023},
};

// so ban 
char B[] = {'A', 'B', 'C', 'D', 'E', 'F'};

// in danh sach bang de quy

void deQuy1(int i) {
    if (i < MAX) {
        cout << i << ". " << mh[i].hsx << " " << mh[i].namSX << endl;
        deQuy1(i + 1);
    }
}   

// in nguoc danh sach

void deQuy2(int i) {
    if (i < 0) return;
    cout << i << ". " << mh[i].hsx << " " << mh[i].namSX << endl;
    deQuy2(i - 1);
}

// in danh sach co nam sx > 2020

void deQuy3(int i) {
    if (i < MAX) {
        if (mh[i].namSX > 2020) {
            cout << i << ". " << mh[i].hsx << " " << mh[i].namSX << endl;
            c1++;
        }
        deQuy3(i + 1);
    }
}

// in danh sach co nam sx <= 2020

void deQuy4(int i) {
    if (i < MAX) {
        if (mh[i].namSX <= 2020) {
            cout << i << ". " << mh[i].hsx << " " << mh[i].namSX << endl;
            c2++;
        }  
        deQuy4(i + 1);
    }
}

// de quy tinh tong gia tien

void deQuy5(int i) {
    if (i < MAX) {
        sum1 += mh[i].gia;
        deQuy5(i + 1);
    }
}

// tim kiem nhi phan

// 

// thuat toan sinh

void view_config(int x[], int k) {
    for (int i = 1; i <= k; i++)
        cout << mh[x[i] - 1].hsx << " " << B[i - 1] << ", ";
    cout << endl;
}

void next_config(int x[], int k, int i) {
    x[i] += 1;
    i++;
    while (i <= k) {
        x[i] = x[i - 1] + 1;
        i++;
    }
}

void list_configs(int k, int n) {
    int i, x[k + 1] = {0};
    for (i = 1; i <= k; i++) x[i] = i;
    do {
        view_config(x, k);
        i = k;
        while (i > 0 && x[i] == n - k + i) i--;
        if (i > 0) next_config(x, k, i);
        c3++;
    } while (i > 0);
}

// thuat toan quay lui

void show(int x[]) {
    for (int i = 1; i <= k; i++)
        cout << mh[x[i] - 1].hsx << " " << B[i - 1] << ", ";
    cout << endl;
}

void Try(int i) {
    for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
        x[i] = j;
        if (i == k) {
            c4++;
            show(x);
        } else {
            Try(i + 1);
        }
    }
}

int main() {
    deQuy1(0);
    cout << "====================" << endl;
    deQuy2(MAX - 1);
    cout << "====================" << endl;
    deQuy3(0);
    cout << "So man hinh > 2020: " << c1 << endl;
    cout << "====================" << endl;
    deQuy4(0);
    cout << "So man hinh <= 2020: " << c2 << endl;
    cout << "====================" << endl;
    deQuy5(0);
    cout << "Tong gia cua cac man hinh trong danh sach la: " << sum1 << endl;
    cout << "====================" << endl;
    list_configs(MIN, MAX);
    cout << "So lan chon " << MIN << " man hinh tu " << MAX << " bang thuat toan sinh la:" << c3 << endl;
    cout << "====================" << endl;
    Try(1);
    cout << "So lan chon " << MIN << " man hinh tu " << MAX << " bang thuat toan quay lui la:" << c4 << endl;
}