#include <bits/stdc++.h>
using namespace std;

struct Quat
{
	string tenhang;
	string mau;
	long gia;
};

void Show(Quat x)
{
	cout << left << setw(20) << x.tenhang << left << setw(15) << x.gia << endl;
}

void Sort(Quat * d, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if(d[i].gia < d[j].gia)
				swap(d[i], d[j]);
		}
	}
}

void G3 (Quat * d, Quat * t, int n, long p, int & q)
{
	Sort(d, n);
	long total = 0;
	for (int i = 0; i < n; i++)
	{
        t[q] = d[i];
        q++;
        total += d[i].gia;
		if(total > p)
			break;
	}
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
	long p = 500000;
	
	Quat * t = new Quat[n];
	int q = 0;
	long tong = 0;
	G3(d, t, n, p, q);
	if(q == 0)
		cout << "Khong the dat so tien lon hon " << p << " voi cac quat co san" << endl;
	else
	{
		cout << "So luong quat ban duoc it nhat de vuot qua " << p << " la: " << q << endl;
		cout << "DANH SACH QUAT BAN DUOC: " << endl;
		cout << left << setw(20) << "HANG SAN XUAT" << left << setw(15) << "GIA BAN" << endl;
		for (int i = 0; i < q; i++)
		{
			Show(t[i]);
			tong += t[i].gia;
		}
		cout << "---------------------------------------" << endl;
		cout << setw(20) << "TONG TIEN" << left << setw(15) << tong << endl;
	}
}