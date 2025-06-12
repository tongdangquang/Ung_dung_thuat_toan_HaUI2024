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

bool G2 (Quat * d, Quat * v, int n, long p, int & u)
{
	Sort(d, n);
	long total = 0;
	for (int i = 0; i < n; i++)
	{
		if(total + d[i].gia <= p)
		{
			total += d[i].gia;
			v[u] = d[i];
			u++;
		}
		if(total == p)
			break;
	}
	return (total == p) ? true : false;
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
	
	Quat * v = new Quat[n];
	int u = 0;
	long tong = 0;
	bool check = G2(d, v, n, p, u);
	if (check == false)
		cout << "Khong the dat so tien " << p << " voi cac quat co san" << endl;
	else
	{
		cout << "So luong quat ban duoc it nhat la: " << u << endl;
		cout << "DANH SACH QUAT BAN DUOC: " << endl;
		cout << left << setw(20) << "HANG SAN XUAT" << left << setw(15) << "GIA BAN" << endl;
		for (int i = 0; i < u; i++)
		{
			Show(v[i]);
			tong += v[i].gia;
		}
		cout << "---------------------------------------" << endl;
		cout << setw(20) << "TONG TIEN" << left << setw(15) << tong << endl;
	}
}