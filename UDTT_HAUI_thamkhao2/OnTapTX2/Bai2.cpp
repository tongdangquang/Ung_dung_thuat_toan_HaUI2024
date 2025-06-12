#include <iostream>
#include <string.h>

using namespace std;

struct laptop
{
    char ten[50];
    char cauhinh[50];
    double gia;
};

void hienthi(laptop *d, int *kq, int dem) {
    for (int i = 0; i < dem; i++) {
        cout << d[kq[i]].ten << " - " << d[kq[i]].cauhinh << " - " << d[kq[i]].gia << endl;
    }
}

// sap xep giam dan
void sapxep(laptop *d, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (d[i].gia < d[j].gia) {
                laptop temp = d[i];
                d[i] = d[j];
                d[j] = temp;
            }
        }
    }
}

bool thamlam(laptop *d, int n, int *kq, double p, int &dem) {
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

int char_in_string(char a, char *q) {
    for (int i = 0; i < strlen(q); i++) {
        if (a == q[i]) return 1;
    }
    return -1;
}

bool bmh(char *q, char *t) {
    int v = strlen(q);
    int i = v - 1;
    while (i < strlen(t)) {
        int k = v - 1;
        while (t[i] == q[k] && k >= 0) {
            i--;
            k--;
        }

        if (k < 0) return true;
        else {
            int x = char_in_string(t[i], q);
            if (x < 0) {
                i += v;
            } else {
                i += (v - x - 1);
            }
        }
    }
    return false;
}

int main()
{
    int n = 7;
    laptop *d = new laptop[n];
    d[0] = {"Hang A", "CPU UPTO 2.5GHz-RAM 16GB-HDD 256GB", 100};
	d[1] = {"Hang B", "CPU UPTO 2.4GHz-RAM 12GB-HDD 128GB", 300};
	d[2] = {"Hang C", "CPU UPTO 2.4GHz-RAM 12GB-HDD 128GB", 600};
	d[3] = {"Hang D", "CPU UPTO 2.8GHz-RAM 12GB-HDD 256GB", 900};
	d[4] = {"Hang E", "CPU UPTO 2.7GHz-RAM 16GB-HDD 516GB", 300};
	d[5] = {"Hang F", "CPU UPTO 3.0GHz-RAM 16GB-HDD 128GB", 450};
	d[6] = {"Hang G", "CPU UPTO 3.2GHz-RAM 24GB-HDD 256GB", 680};

    int *kq = new int[n];
    double p = 1200;
    int dem = 0;

    if (thamlam(d, n, kq, p, dem)) {
        hienthi(d, kq, dem);
        cout << "So luong tu lanh mua duoc toi thieu la: " << dem << endl;
    } else {
        cout << "Khong co ket qua"<< endl;
    }

    char q[10] = "RAM 16GB";
    int demchuoi = 0;
    for (int i = 0; i < n; i++) {
        demchuoi += bmh(q, d[i].cauhinh);
    }

    cout << "So lan xuat hien cua chuoi q trong d la: " << demchuoi << endl;
}