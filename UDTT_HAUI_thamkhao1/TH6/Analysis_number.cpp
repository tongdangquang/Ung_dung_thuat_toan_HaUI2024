#include<iostream>
#include<vector>
using namespace std;

int Q1(int m, int n) {
    vector<int> f(n + 1, 0);
    f[0] = 1;

    for (int i = 1; i <= m; ++i) {
        for (int j = i; j <= n; ++j) {
            f[j] += f[j - i];
        }
    }

    return f[n];
}


int main() {
	int n = 5;
	cout<<Q1(n, n);
	return 0;
}
