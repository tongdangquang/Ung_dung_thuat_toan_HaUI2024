#include <bits/stdc++.h>
using namespace std;

struct Chuyenbay
{
    string sohieu;
    double giave;
    int soghe;
};

void show(Chuyenbay b)
{
    cout << left << setw(10) << b.sohieu << left << setw(10) << b.giave << left << setw(10) << b.soghe << endl;
}

void A1(Chuyenbay * b, int n, int i)
{
    if(i < n)
    {
        if(b[i].giave > 700000)
            show(b[i]);
        A1(b, n, i + 1);
    }
}

Chuyenbay A2(Chuyenbay * b, int left, int right)
{
    if(left == right)
        return b[left];
    
    int mid = (left + right)/2;
    Chuyenbay min_left = A2(b, left, mid);
    Chuyenbay min_right = A2(b, mid + 1, right);

    return (min_left.giave < min_right.giave) ? min_left : min_right;
}

void show2(Chuyenbay * b, int * x, int k)
{
    for (int i = 1; i <= k; i++)
    {
        cout << left << setw(10) << b[x[i] - 1].sohieu << left << setw(10) << b[x[i] - 1].soghe << endl;
    }
    cout << endl;
}

void A3(Chuyenbay * b, int * x, int n, int k, int i, int & c)
{
    for(int j = x[i - 1] + 1; j <= n - k + i; j++)
    {
        x[i] = j;
        if(i == k)
        {
            c++;
            show2(b, x, k);
        }
        else
            A3(b, x, n, k, i + 1, c);
    }
}

// sắp xếp danh sách chuyến bay tăng dần theo giá vé bằng thuật toán merge sort
void merge(Chuyenbay * b, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Chuyenbay * a1 = new Chuyenbay [n1];
    Chuyenbay * a2 = new Chuyenbay [n2];

    for (int i = 0; i < n1; i++)
        a1[i] = b[left + i];
    for (int i = 0; i < n2; i++)
        a2[i] = b[mid + 1 + i];
    
    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2)
    {
        if(a1[i].giave < a2[j].giave)
        {
            b[k] = a1[i];
            i++;
        }
        else
        {
            b[k] = a2[j];
            j++;
        }
        k++;
    }
    while(i < n1)
    {
        b[k] = a1[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        b[k] = a2[j];
        j++;
        k++;
    }
}

void A4(Chuyenbay * b, int left, int right)
{
    if(left < right)
    {
        int mid = (left + right)/2;
        A4(b, left, mid);
        A4(b, mid + 1, right);
        merge(b, left, mid, right);
    }
}   

int main()
{
    int n = 6;
    Chuyenbay * b = new Chuyenbay[n]{
        {"VN001", 600000, 150},
        {"VN002", 700000, 130},
        {"VN003", 800000, 120},
        {"VN004", 400000, 180},
        {"VN005", 200000, 200},
        {"VN006", 900000, 100}
    };

    cout << "Danh sach chuyen bay co gia tren 700000: " << endl;
    cout << left << setw(10) << "SO HIEU" << left << setw(10) << "GIA VE" << left << setw(10) << "SO GHE" << endl;
    A1(b, n, 0);
    cout << "------------------------------------------" << endl;

    cout << "Thong tin chuyen bay co gia ve thap nhat: " << endl;
    show(A2(b, 0, n - 1));
    cout << "------------------------------------------" << endl;

    int * x = new int[n + 1];
    for (int i = 0; i <= n; i++)
        x[i] = 0;
    int k = 4, c = 0;
    cout << "Cac phuong an chon ra 4 chuyen bay: " << endl;
    A3(b, x, n, k, 1, c);
    cout << "Tong so phuong an: " << c << endl;
    cout << "------------------------------------------" << endl;

    A4(b, 0, n - 1);
    cout << "Danh sach chuyen bay sap xep tang dan theo gia ve: " << endl;
    cout << left << setw(10) << "SO HIEU" << left << setw(10) << "GIA VE" << left << setw(10) << "SO GHE" << endl;
    for (int i = 0; i < n; i++)
        show(b[i]);
}