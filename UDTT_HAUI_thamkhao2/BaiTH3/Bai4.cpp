#include <iostream>

using namespace std;

double tinh(int n, float a) {
	if (n == 1) return a;
	double mid = tinh(n / 2, a);
	
	if (n % 2 == 0) return mid * mid;
	else return mid * mid * a;
}

int main() {
	int n;
	float a;
	cout << "Nhap a: "; cin >> a;
	cout << "Nhap n: "; cin >> n;
	cout << tinh(n, a);
}