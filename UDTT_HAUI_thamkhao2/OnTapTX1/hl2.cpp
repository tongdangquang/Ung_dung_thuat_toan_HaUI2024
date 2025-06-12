#include <iostream>

#define MAX 7 // so luong phan tu trong danh sach

using namespace std;

double sum1 = 0; // tong gia ban
int sum3 = 0, sum4 = 0;
// khai bao cac bien cho tt quay lui
int x[MAX], k = 6, n = MAX;

struct MAYGIAT
{
    string hsx;
    float kl;
    int gia;
};

MAYGIAT mg[] = {
    {"A", 8, 300},
    {"B", 7.5, 200},
    {"C", 8.3, 250},
    {"D", 9, 350},
    {"E", 7, 300},
    {"F", 8.5, 270},
    {"G", 7.9, 320}, // 7 tong = 1990
    {"H", 9.3, 400}, // 8 tong = 2390
};

// sinh hoan vi

// in cau hinh
void view_config(int x[], int k) {
    for (int i = 1; i <= k; i++)
        cout << mg[x[i] - 1].hsx << " ";
    cout << endl;
}

// cau hinh tiep theo
void next_config(int x[], int k, int i) {
    x[i] += 1;
    i++;
    while (i <= k) {
        x[i] = x[i - 1] + 1;
        i++;
    }
}

// danh sach cau hinh 
void list_configs(int k, int n) {
    int i, x[k + 1] = {0};
    for (i = 1; i <= k; i++) x[i] = i;
    do
    {
        view_config(x, k); // khong can goi neu de khong yeu cau
        i = k;
        while (i > 0 && x[i] == n - k + i) i--;
        if (i > 0) next_config(x, k ,i);
        sum3++;
    } while (i > 0);
}

// quay lui

void show(int x[]) {
    for (int i = 1; i <= k; i++)
        cout << mg[x[i] - 1].hsx << " ";
    cout << endl;
}

void Try(int i) {
    for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
        x[i] = j;
        if (i == k) {
            sum4++;
            show(x);
        } else {
            Try(i + 1);
        }
    }
}

int main()
{

    list_configs(6, MAX);
    cout << sum3 << endl;
    Try(1);
    cout << sum4 << endl;
}