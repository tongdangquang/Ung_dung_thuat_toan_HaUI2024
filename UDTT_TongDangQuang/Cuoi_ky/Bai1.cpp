#include <bits/stdc++.h>
using namespace std;

// Đệ quy
int Find_min1(int a[], int i, int k)
{
	if(i < 0)
		return INT_MAX;
	
	if (a[i] > k)
		return (a[i] <= Find_min1(a, i - 1, k)) ? a[i] : Find_min1(a, i - 1, k);

	return Find_min1(a, i - 1, k);
}

// Chia để trị
int Find_min2(int a[], int left, int right, int k)
{
	if (left > right)
		return INT_MAX;

	if (left == right)
		return (a[left] > k) ? a[left] : INT_MAX;
	
	int mid = (left + right)/2;
	int min_left = Find_min2(a, left, mid, k);
	int min_right = Find_min2(a, mid + 1, right, k);
	return (min_left < min_right) ? min_left : min_right;
}

int main()
{
	int k = 10;
	int n = 15;
	int a[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	int x = Find_min2(a, 0, n - 1, k);
	if (x == INT_MAX)
		cout << "Khong tim duoc gia tri thoa man" << endl;
	else
		cout << "Min = " << Find_min2(a, 0, n - 1, k) << endl;
}