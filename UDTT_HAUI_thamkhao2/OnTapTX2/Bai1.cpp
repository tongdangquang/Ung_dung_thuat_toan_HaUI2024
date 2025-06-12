#include <iostream>

using namespace std;

struct tulanh {
    char hang[30];
    int dientich;
    double gia;
};

void hienthi(int *kq, tulanh *d, int dem) {
    for (int i = 0; i < dem; i++) {
        cout << d[kq[i]].hang << " - " << d[kq[i]].dientich << " - " << d[kq[i]].gia << endl;
    }
}

// sap xep tang dan
void sapxep(tulanh *d, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (d[i].gia > d[j].gia) {
                tulanh temp = d[i];
                d[i] = d[j];
                d[j] = temp;
            }
        }
    }
}

bool thamlam(tulanh *d, int *kq, double p, int n, int &dem) {
    sapxep(d, n);
    for (int i = 0; i < n; i++) {
        if (p >= d[i].gia) {
            p -= d[i].gia;
            kq[dem++] = i;
        }
    }
    if (p >= 0) return true;
    return false;
}

void qhd(tulanh *d, int n, int kt, double bang[][50]) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= kt; j++) {
            bang[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= kt; ++j) {
            bang[i][j] = bang[i - 1][j];
            if (d[i - 1].dientich <= j) {
                int temp = d[i - 1].gia + bang[i - 1][j - d[i - 1].dientich];
                if (bang[i][j] < temp) {
                    bang[i][j] = temp;
                }
            }
        }
    }
}

void ketqua(tulanh *d, int n, int kt, double bang[][50], int &sl, int *kqua) {
    double max = bang[n][kt];
    int w = kt;

    for (int i = n; i > 0 && max > 0; i--) {
        if (max != bang[i - 1][w]) {
            kqua[sl] = i - 1;
            w -= d[i - 1].dientich;
            max -= d[i - 1].gia;
            sl++;
        }
    }
}

int main() {
    int n = 7;
    tulanh *d = new tulanh[n];
    d[0] = {"Sanyo 1", 1, 15};
    d[1] = {"Sanyo 2", 5, 44};
    d[2] = {"Sanyo 3", 4, 61};
    d[3] = {"Sanyo 4", 4, 55};
    d[4] = {"Sanyo 5", 6, 32};
    d[5] = {"Sanyo 6", 8, 34};
    d[6] = {"Sanyo 7", 9, 40};

    // cau 1
    int *kq = new int[n];
    double p = 100.5;
    int dem = 0;

    if (thamlam(d, kq, p, n, dem)) {
        hienthi(kq, d, dem);
        cout << "So luong tu lanh mua duoc toi da la: " << dem << endl;
    } else {
        cout << "Khong tim ra ket qua" << endl;
    }

    // cau 2
    int kt = 15;
    double bang[50][50];
    int kqua[kt];
    int sl = 0;

    qhd(d, n, kt, bang);
    ketqua(d, n, kt, bang, sl, kqua);

    cout << "Cau 2:" << endl << "So luong dien thoai: " << sl << endl;
    cout << "Danh sach dien thoai: " << endl;
    hienthi(kqua, d, sl);
    return 0;
}