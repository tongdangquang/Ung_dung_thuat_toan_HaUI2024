#include<iostream>
using namespace std;

//void sort()


bool A1(float t[], int n, float m, float x[], int &z) {
	int i = 0;
	z = 0;
	while (m > 0 && i < n) {
		if (m >= t[i]) {
			x[z] = t[i];
			m = m - t[i];
			i++;
			z++;
		}
		else
		{
			break;
		}
	}
	for (int j = n - 1; j >= i; j--) {
		if (m <= t[j]) {
			x[z] = t[j];
			m = m - t[j];
			z++;
			break;
		}
	}
	if (m > 0)	return false;
	return true;
}

void print_arr(float x[], int z) {
	cout << "Danh sach xe lan luot la: ";
	for (int i = 0; i < z; i++) {
		cout << x[i] <<" ";
	}
	cout << endl;
}

int main() {
	float m = 70;
	int n = 6;
	float t[] = { 10, 9, 7, 5.5, 5, 4 };
	float x[6] = { 0 };
	int z = 0;
	bool a = A1(t, n, m, x, z);
	if (a) {
		cout << "So xe tai la: " << z << endl;
		print_arr(x, z);
	}
	else cout << "Khong the cho het trong 1 luot" << endl;
	return 0;
}
