#include <iostream>

#define MAX 6

using namespace std;

struct ChuyenBay
{
    string soHieu;
    int giaVe;
    int soGhe;
};

// khoi tao

ChuyenBay cb[] = {
    {"VN005", 300000, 200},
    {"VN006", 400000, 200},
    {"VN003", 500000, 180},
    {"VN001", 600000, 150},
    {"VN014", 700000, 150},
    {"VN015", 850000, 150},
    {"VN017", 950000, 150},
    {"VN020", 1000000, 150},
    {"VN021", 1500000, 150},
    {"VN023", 2000000, 150}
};

// giai thuat de quy

void deQuy(int i) {
    if (i < MAX) {
        if (cb[i].giaVe >= 700000)
           cout << cb[i].soHieu << " " << cb[i].giaVe << " " << cb[i].soGhe << endl;
        deQuy(i + 1);
    }   
}

// de quy in nguoc

void inNguoc(int i) {
    if (i == 0) return;
    cout << cb[i].soHieu << " " << cb[i].giaVe << " " << cb[i].soGhe << endl; 
    inNguoc(i - 1);
}

// thuat toan chia de tri

void merge(int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    ChuyenBay L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = cb[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = cb[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].soHieu <= R[j].soHieu) {
            cb[k] = L[i];
            i++;
        } else {
            cb[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        cb[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        cb[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int l, int r) {
    if (r > l) {
        int m = l + (r - l) / 2;
        mergeSort(l, m);
        mergeSort(m + 1, r);
        merge(l, m, r);
    }
}

// thuat toan sinh

void view_config(int x[], int k) {

}

void next_config(int x[], int k, int i) {

}

void list_configs(int k, int n) {

}

// thuat toan quay lui

int x[MAX], k = 4, n = MAX;

void show(int x[]) {
    for (int i = 1; i <= k; i++)
        cout << cb[x[i] - 1].soHieu << " ";
    cout << endl;
}

void Try(int i) {
    for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
        x[i] = j;
        if (i == k) {
            show(x);
        } else {
            Try(i + 1);
        }
    }
}

int main()
{
    cout << "Chuyen bay co gia ve lon hon 700000 la: \n";
    deQuy(0);
    cout << "In nguoc: \n";
    inNguoc(MAX - 1);
    cout << "Chuyen bay co gia ve thap nhat la: \n";
    mergeSort(0, MAX - 1);
    for (int i = 0; i < MAX; i++)
    cout << cb[i].soHieu << " " << cb[i].giaVe << " " << cb[i].soGhe << endl;
    cout << "Tat ca cac phuong an khac nhau de chon ra 4 chuyen bay tu danh sach la: \n";
    Try(1);
    cout << "So lan chon: \n";
}
