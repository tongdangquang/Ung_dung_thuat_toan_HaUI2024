#include <iostream>

using namespace std;

int *c, *s;

bool cash_algo(int *c, int m, long n, int *&s) {
	s = new int[m];
	for (int i = 0; i < m; i++) s[i] = 0;
	int i = 0;
	while (n > 0 && i < m) {
		s[i] = n / c[i];
		n %= c[i];
		i++;
	}
	if (n > 0) return false;
	else return true;
}

int main() {
	int n = 16, m = 4, sum = 0;
	cout << "so menh gia: 10, 5, 2, 1" << endl; 
	c = new int[m];
	c[0] = {10};
	c[1] = {5};
	c[2] = {2};
	c[3] = {1};
	/* for (int i = 0; i < m; i++)
		cin >> c[i]; */
	cout << "cho so tien la: " << n << endl;
	if (!cash_algo(c, m, n, s)) cout << "No solution";
	else {
		cash_algo(c, m, n, s);
		cout << "so luong tung menh gia la: " << endl;
		for (int j = 0; j < m; j++) {
			cout << c[j] << ":" << s[j] << endl;
			sum += s[j];
		}
		cout << "so luong dong xu it nhat can lay la " << sum << " dong" << endl;
	}
}