#include <bits/stdc++.h>
using namespace std;

void show(int * x, int k)
{
	for (int i = 1; i <= k; i++)
		cout << x[i] << " ";
	cout << endl;
}

// i_đầu = x[a - 1] + 1: x[a - 1] là phần tử cuối cùng đã được chọn trước đó. Do đó, phần tử tiếp theo mà bạn có thể chọn là x[i - 1] + 1. Điều này đảm bảo rằng tổ hợp được tạo ra là duy nhất và không có phần tử nào bị lặp lại.
void Try(int a, int * x, int n, int k, bool * d)
{
	for (int i = x[a - 1] + 1; i <= n; i++)
	{
		if (d[i] == false)
		{
			x[a] = i;
			if (a == k)
				show(x, k);
			else
			{
				d[i] = true;
				Try(a + 1, x, n, k, d);
				d[i] = false;
			}
		}
	}
}

int main()
{
	int n, k;
	cout << "Chon k phan tu tu n phan tu (n > k): " << endl;
	cout << "Nhap n = "; cin >> n;
	cout << "Nhap k = "; cin >> k;
	int * x = new int [n + 1];
	bool * d = new bool [n + 1];
	for (int i = 1; i <= n; i++)
		d[i] = false;
	Try(1, x, n, k, d);
}