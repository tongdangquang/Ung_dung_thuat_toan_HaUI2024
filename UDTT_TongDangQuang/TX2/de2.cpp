#include <bits/stdc++.h>
using namespace std;

struct PC
{
    string brand;
    string config;
    long price;
};

void Sort (PC * d, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (d[i].price < d[j].price)
                swap(d[i], d[j]);
        }
    }
}

void C(PC * d, int n, long p, long & m, int & u, PC * x)
{
    u = 0;
    for (int i = 0; i < n; i++)
    {
        m += d[i].price;
        x[u] = d[i];
        u++;
        if (m > p)
            break;
    }
}

int char_in_string(char c, string p)
{
    int n = p.length();
    for (int i = 0; i < n; i++)
    {
        if(c == p[i])
            return i;
    }
    return -1;
}

int BMH(string t, string p)
{
    int v = p.length();
    int n = t.length();
    int i = v - 1;

    if(v > n)
        return -1;

    while(i < n)
    {
        int k = v - 1;
        while(k >= 0 && t[i] == p[k])
        {
            i--;
            k--;
        }
        if (k < 0) 
            return i + 1;
        else
        {
            int x = char_in_string(t[i], p);
            if(x < 0)
                i += v;
            else
                i += v - x - 1;
        }
    }
    return -1;
}

void C_apply(PC * d, int n)
{
    long p = 50000000;
    long m = 0;
    int u = 0;
    PC * x = new PC[n];
    Sort(d, n);
    C(d, n, p, m, u, x);

    if (u > 0)
    {
        cout << "So luong may tinh it nhat can ban de duoc so tien m lon hon " << p << " la: " << u << endl;
        cout << "-------------------------------------------------------------------" << endl;

        cout << "Tong so tien thu duoc la: " << m << endl;
        cout << "-------------------------------------------------------------------" << endl;

        cout << "Danh sach may tinh it nhat can ban la: " << endl;
        cout << left << setw(10) << "BRAND" << left << setw(50) << "CONFIGURATION" << left << setw(15) << "PRICE" << endl;
        for (int i = 0; i < u; i++)
            cout << left << setw(10) << x[i].brand << left << setw(50) << x[i].config << left << setw(15) << x[i].price << endl;
    }
    else
        cout << "Khong the ban duoc chiec may tinh nao" << endl;
}

void BMH_apply(PC * d, int n)
{
    string t = "HDD 256";
    PC * a = new PC [n];
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        if (BMH(d[i].config, t) >= 0)
        {
            a[x] = d[i];
            x++;
        }
    }

    if (x > 0)
    {
        cout << "So may tinh co thong tin ve o cung la " << t << " la: " << x << endl;
        cout << "-------------------------------------------------------------------" << endl;

        cout << "Danh sach may tinh co thong tin ve o cung " << t << " la: " << endl;
        cout << left << setw(10) << "BRAND" << left << setw(50) << "CONFIGURATION" << left << setw(15) << "PRICE" << endl;
        for (int i = 0; i < x; i++)
            cout << left << setw(10) << a[i].brand << left << setw(50) << a[i].config << left << setw(15) << a[i].price << endl;
    }
    else
        cout << "Khong co may tinh nao co thong tin o cung la " << t << " trong danh sach" << endl;
}

int main()
{
    int n = 5;
    PC * d = new PC [n]{
		{"HP", "CPU 2.5GHz upto 3.5GHz-RAM 16GB-SSD 512GB", 15000000},
		{"LG", "CPU 2.5GHz upto 3.5GHz-RAM 8GB-HDD 1TB", 20000000},
		{"DELL", "CPU 2.5GHz upto 3.5GHz-RAM 24GB-HDD 256GB", 18000000},
		{"ASUS", "CPU 2.5GHz upto 3.5GHz-RAM 32GB-HDD 256GB", 25000000},
		{"ACER", "CPU 2.5GHz upto 3.5GHz-RAM 16GB-SSD 2TB", 16000000},
	};

    cout << "CAU 1: " << endl;
    C_apply(d, n);

    cout << "\n\n\nCAU 2: " << endl;
    BMH_apply(d, n);
}