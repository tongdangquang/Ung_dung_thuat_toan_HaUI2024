#include <bits/stdc++.h>
using namespace std;

struct Phone
{
	string brand;
	int size;
	double price;
};

void Q1(double ** F, Phone * d, int n, int s)
{
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= s; j++)
			F[i][j] = 0;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= s; j++)
		{
			F[i][j] = F[i - 1][j];
			if(d[i].size <= j)
			{
				double temp = d[i].price + F[i - 1][j - d[i].size];
				if(F[i][j] < temp)
					F[i][j] = temp;
			}
		}
	}
}

double Q1_apply(Phone * d, int n, int s, Phone * a, int & x)
{
	double ** F = new double*[n + 1];
	for (int i = 0; i <= n; i++)
		F[i] = new double[s + 1];
	
	Q1(F, d, n, s);
	int i = n, j = s;
	x = 0;
	while(i != 0)
	{
		if(F[i][j] != F[i - 1][j])
		{
			a[x] = d[i];
			x++;
			j -= d[i].size;
		}
		i--;
	}

	cout << "Bang phuong an: " << endl;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= s; j++)
			cout << left << setw(10) << F[i][j];
		cout << endl;
	}

	return F[n][s];
}

int main()
{
	int n = 6;
	Phone * d = new Phone[n + 1]{
		{"", 0, 0},
		{"Apple", 2, 1500}, 
		{"Samsung", 3, 2000}, 
		{"Xiaomi", 1, 1200}, 
		{"Oppo", 2, 1800},
		{"Vivo", 1, 1000},
		{"OnePlus", 3, 2200}
	};
	int s = 7;
	int x = 0;
	Phone * a = new Phone[n];
	
	double result = Q1_apply(d, n, s, a, x);

	cout << "Gia tri toi da co the lay duoc la: " << result << endl;

	cout << "---------------------------------------" << endl;
	cout << "So luong dien thoai lay duoc la: " << x << " chiec" << endl;

	cout << "---------------------------------------" << endl;
	cout << "DANH SACH DIEN THOAI LAY DUOC: " << endl;
	cout << left << setw(15) << "BRAND" << left << setw(15) << "SIZE" << left << setw(15) << "PRICE" << endl;
	for (int i = 0; i < x; i++)
		cout << left << setw(15) << a[i].brand << left << setw(15) << a[i].size << left << setw(15) << a[i].price << endl;
}
