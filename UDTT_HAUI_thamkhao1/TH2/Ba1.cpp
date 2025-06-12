#include<iostream>
using namespace std;

int UCLN(int n, int m) {
	if (n % m == 0)	return m;
	return UCLN(m, n % m);
}
int main() {
	cout << UCLN(64, 3) << endl;
	return 0;
}