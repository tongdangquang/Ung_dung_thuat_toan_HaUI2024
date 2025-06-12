#include <bits/stdc++.h>
using namespace std;

struct Quat
{
    string brand;
    string color;
    long price;
};

void Sort_asc(Quat * d, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if(d[i].price > d[j].price)
                swap(d[i], d[j]);
        }
    }
}

void G1(Quat * d, Quat * s, int n, int p, int & c)
{
    Sort_asc(d, n);
    long total = 0;
    for (int i = 0; i < n; i++)
    {
        if (total + d[i].price <= p)
        {
            s[c] = d[i];
            c++;
            total += d[i].price;
        }
        if (total == p)
            break;
    }
}

void F1(Quat * d, int n, long p)
{
    int c = 0;
    Quat * s = new Quat[n];
    G1(d, s, n, p, c);
    
    if(c > 0)
    {
        long tong = 0;
        cout << "So luong nhieu nhat cac quat co the mua duoc: " << c << endl;
        cout << "------------------------------------------------------" << endl;
        cout << "DANH SACH CAC QUAT MUA DUOC: " << endl;
        cout << left << setw(15) << "BRAND" << left << setw(15) << "PRICE" << endl;
        for (int i = 0; i < c; i++)
        {
            tong += s[i].price;
            cout << left << setw(15) << s[i].brand << left << setw(15) << s[i].price << endl;
        }
        cout << "------------------------------------------------------" << endl;
        cout << left << setw(15) << "TONG TIEN" << left << setw(15) << tong << endl;
    }
    else
        cout << "Khong the mua duoc chiec quat nao" << endl;
}

int main()
{
    int n = 6;
	Quat * d = new Quat[n] {
		{"samsung", "black", 150000},
		{"panasonic", "blue", 250000},
		{"LG", "green", 180000},
		{"tosiba", "black", 300000},
		{"samsung", "silver", 200000},
		{"LG", "blue", 100000}
	};
	long p = 1100000;

    F1(d, n, p);
}
