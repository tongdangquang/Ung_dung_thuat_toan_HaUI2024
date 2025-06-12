#include<iostream>
using namespace std;

float pow(float a, int n) {
	if (n == 1)	return a;
	float z = pow(a, n / 2);
	if (n % 2)	return z * z * a;
	else return z * z;
}

int main() {
	float a = 4.5;
	int n = 2;
	cout << pow(a, n) << endl;
	return 0;
}
