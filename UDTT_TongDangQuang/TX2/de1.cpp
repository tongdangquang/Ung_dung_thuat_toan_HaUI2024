#include <bits/stdc++.h>
using namespace std;

struct Tulanh
{
    string brand;
    int size;
    double weight;  
};

void Sort_tulanh(Tulanh * d, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (d[i].size > d[j].size)
                swap(d[i], d[j]);
        }
    }
}

void A(Tulanh * d, int n, int s, int & v, Tulanh * t)
{
    v = 0;
    double total = 0;
    for (int i = 0; i < n; i++)
    {
        if (total + d[i].size <= s)
        {
            total += d[i].size;
            t[v] = d[i];
            v++;
        }
    }
}

void B(Tulanh * d, int n, int s, int & p, double & q, Tulanh * a)
{
    double ** F = new double * [n + 1];
    for (int i = 0; i <= n; i++)
        F[i] = new double [s + 1]();

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            F[i][j] = F[i - 1][j];
            if (d[i - 1].size <= j)
            {
                double temp = d[i - 1].weight + F[i - 1][j - d[i - 1].size];
                if (F[i][j] < temp)
                    F[i][j] = temp;
            }
        }
    }
    
    q = F[n][s];
    int i = n, j = s;
    while (i != 0)
    {
        if (F[i][j] != F[i - 1][j])
        {
            a[p] = d[i - 1];
            p++;
            j -= d[i - 1].size;
        }
        i--;
    }

    cout << "Bang phuong an: " << endl;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
            cout << F[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
}

void A_apply(Tulanh * d, int n)
{
    int s = 15;
    int v = 0;
    Sort_tulanh(d, n);
    Tulanh * t = new Tulanh[n];
    A(d, n, s, v, t);
    if (v > 0)
    {
        cout << "So luong tu lanh nhieu nhat co the xep vao kho la: " << v << endl;
        cout << "-------------------------------------------" << endl;
        
        cout << "Danh sach tu lanh nhieu nhat co the xep vao kho la: " << endl;
        cout << left << setw(15) << "BRAND" << left << setw(15) << "SIZE" << left << setw(15) << "WEIGHT" << endl;
        for (int i = 0; i < v; i++)
            cout << left << setw(15) << t[i].brand << left << setw(15) << t[i].size << left << setw(15) << t[i].weight << endl;
    }
    else
        cout << "Khong the xep duoc chiec tu lanh nao vao kho" << endl;
}

void B_apply(Tulanh * d, int n)
{
    int s = 15;
    int p = 0;
    double q = 0;
    Tulanh * a = new Tulanh[n];
    B(d, n, s, p, q, a);

    if (p > 0)
    {
        cout << "-------------------------------------------" << endl;
        cout << "So luong tu lanh duoc xep vao kho la: " << p << endl;
        cout << "-------------------------------------------" << endl;
        
        cout << "Tong khoi luong cac tu lanh duoc xep vao kho la: " << q << endl;
        cout << "-------------------------------------------" << endl;

        cout << "Danh sach cac tu lanh duoc xep vao kho la: " << endl;
        cout << left << setw(15) << "BRAND" << left << setw(15) << "SIZE" << left << setw(15) << "WEIGHT" << endl;
        for (int i = 0; i < p; i++)
        {
            cout << left << setw(15) << a[i].brand << left << setw(15) << a[i].size << left << setw(15) << a[i].weight << endl;
        }
    }
    else
        cout << "Khong the xep duoc chiec tu lanh nao vao kho" << endl;
}
int main()
{
    int n = 6;
    Tulanh * d = new Tulanh[n] {
        {"Panasonic 1", 1, 65.7},
        {"Panasonic 2", 3, 60.7},
        {"Panasonic 3", 5, 70},
        {"Panasonic 4", 4, 62.5},
        {"Panasonic 5", 8, 50},
        {"Panasonic 6", 6, 66.5},
    };
    cout << "CAU 1: "    << endl;
    A_apply(d, n);
    cout << "\n\n\nCAU 2: " << endl;
    B_apply(d, n);
}
