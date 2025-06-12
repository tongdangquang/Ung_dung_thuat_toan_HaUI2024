#include<iostream>
using namespace std;

void qsort(int x[], int left, int right) {
	if (left >= right)	return;
	int i = left, j = right;
	int pivot = x[(left + right) / 2];
	while (i <= j) {
		while (x[i] > pivot)	i--;
		while (x[j] < pivot)	j--;
		if (i <= j) {
			swap(x[i], x[j]);
			i++;
			j--;
		}
	}
	qsort(x, left, j);
	qsort(x, i, right);
}


int A1(int x[], int n, int m, int s[]) {
	int i = 0;
	int ans = 0;
	while (m > 0 && i < n) {
		s[i] = m / x[i];
		ans += s[i];
		m = m % x[i];
		i++;
	}
	if (m > 0)	return -1;
	return ans;
}

void print_arr(int s[],int x[], int n) {
	for (int i = 0; i < n; i++) {
		if (s[i] != 0) {
			cout << s[i] << " dong xu tri gia " << x[i] << endl;
		}
	}
	cout << endl;
}

int main() {
	int n = 3;
	int x[] = { 3, 7, 10 };
	int m = 12;
	int s[3] = { 0 };
	qsort(x, 0, n - 1);
	int ans = A1(x, n, m, s);
	if (ans != -1) {
		cout << "can toi thieu " << ans << " dong xu" << endl;
		print_arr(s, x, n);
	}
	else cout << "Khong tim duoc dap an" << endl;
}
