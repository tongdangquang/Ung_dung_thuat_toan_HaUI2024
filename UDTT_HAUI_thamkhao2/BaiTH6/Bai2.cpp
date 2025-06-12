#include <iostream>

using namespace std;

void swap(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

void A2(int *a, int n, int m, int s) {
	a = new int[m];
	cout << "Nhap " << m << " chai nuoc:";
	for (int i = 0; i < m; i++) cin >> a[i];
	for (int i = 0; i < m - 1; i++) 
		for (int j = i + 1; j < m; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);
	int i = 0;
	if (n < a[i] || m < 1) cout << "khong co chai nao de rot" << endl;
	else {
		do {
			n -= a[i];
			i++;
			s++;
		} while (n >= a[i] && m > i);
		cout << "So chai nuoc toi da: " << s << endl;
	}
}

int main() {
	int n, m, *a, s = 0;
	cout << "Nhap n va m: ";
	cin >> n >> m;
	A2(a, n, m, s);
}