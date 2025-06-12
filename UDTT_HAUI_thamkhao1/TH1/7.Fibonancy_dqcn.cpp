#include<iostream>
#include<vector>
using namespace std;

vector<int> d;
int fibonancy(int n) {
	if (d[n] != 0)	return d[n];
	if (n == 1 || n == 2)	d[n] = 1;
	else d[n] = fibonancy(n - 1) + fibonancy(n - 2);
	return d[n];
}

int main() {
	int n = 7;
	d.resize(n + 1, 0);
	cout << fibonancy(n);
	return 0;
}