#include <bits/stdc++.h>
using namespace std;

void Sort_array(int x[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (x[i] > x[j])
				swap(x[i], x[j]);
		}
	}
}

int Binary_search(int x[], int left, int right, int m)
{
	if (left > right)
		return -1;

	int mid = (left + right)/2;
	if (x[mid] == m)
		return mid;
	else if (x[mid] > m)
		return Binary_search(x, left, mid - 1, m);
	else
		return Binary_search(x, mid + 1, right, m);
	
	return -1;
}

int main()
{
	int n = 10;
	int x[10] = {1, 9, 3, 4, 6, 5, 6, 7, 8, 10};
	int m = 9;
	Sort_array(x, n);
	int v = Binary_search(x, 0, n - 1, m);
	if (v < 0)
		cout << m << " khong nam trong x" << endl;
	else
		cout << m << " nam trong x" << endl;
}