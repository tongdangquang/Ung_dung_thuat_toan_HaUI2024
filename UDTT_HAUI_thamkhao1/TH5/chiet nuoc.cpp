#include<iostream>
using namespace std;

void qsort(int x[], int left, int right) {
	if (left >= right)	return;
	int i = left, j = right;
	int pivot = x[(left + right) / 2];
	while (i <= j) {
		while (x[i] < pivot) i++;
		while (x[j] > pivot)	j--;
		if (i <= j) {
			swap(x[i], x[j]);
			i++;
			j--;
		}
	}
	qsort(x, left, j);
	qsort(x, i, right);
}

int B2(int x[], int n, int d) {
	int i = 0;
	int ans = 0;
	int m = d;
	while (m > 0 && i < n) {
		if (m >= x[i]) {
			ans++;
			m -= x[i];
		}
		i++;
	}
	if (m == d)	return -1;
	return ans;
}

void prt_arr(int x[], int n) {
	for (int i = 0; i < n; i++) {
		cout << x[i] << ' ';
	}
	cout << endl;
}

int main() {
	int n = 5;
	int d = 1;
	int v[] = {4, 5, 10, 2, 3};

	qsort(v, 0, n - 1);

	int ans = B2(v, n, d);
	if (ans == -1)	cout << "Khong co chai nao" << endl;
	else {
		cout << "So luong chai toi da duoc do day la: " << ans << endl;
		cout << "Dung tich cac chai lan luot la: ";
		prt_arr(v, ans);
	}
	return 0;
}
