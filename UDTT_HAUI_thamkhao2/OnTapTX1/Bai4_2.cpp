#include <iostream>

#define MAX 6

using namespace std;

struct ChuyenBay
{
    string soHieu;
    int giaVe;
};

ChuyenBay cb[] = {
    {"VN05", 100},
    {"VN09", 200},
    {"VN03", 300},
    {"VN08", 400},
    {"VN01", 300},
    {"VN06", 400},
};

void deQuy(int i) {
    if (i < MAX) {
        if (cb[i].giaVe >= 200)
            cout << cb[i].soHieu << " " << cb[i].giaVe << endl;
        deQuy(i + 1);
    }
}

void merge(int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    ChuyenBay L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = cb[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = cb[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i].soHieu <= R[j].soHieu)
        {
            cb[k] = L[i];
            i++;
        }
        else
        {
            cb[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        cb[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        cb[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int l, int r)
{
    if (r > l)
    {
        int m = l + (r - l) / 2;
        mergeSort(l, m);
        mergeSort(m + 1, r);
        merge(l, m, r);
    }
}

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
    cout << "Danh sach chuyen bay co gia ve tren 200 la: \n";
    deQuy(0);
    mergeSort(0, MAX - 1);
    cout << "Danh sach sau khi duoc sap xep: \n";
    for (int i = 0; i < MAX; i++)
		cout << cb[i].soHieu << " " << cb[i].giaVe << " \n";
    cout << "Danh sach 4 cb: \n";
    Try(1);
}
