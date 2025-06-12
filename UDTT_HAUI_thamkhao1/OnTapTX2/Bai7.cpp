#include<iostream>
#include<vector>
using namespace std;

int T(string a, string b, int n, int m, int dp[7][8]) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[n][m];
}

void truy_vet(string a, int n, string b, int m, int dp[7][8]) {
	vector<char> p;
	int i = n, j = m;
	while (dp[i][j] != 0) {
		if (a[i - 1] == b[j - 1]) {
			p.push_back(a[i - 1]);
			i--;
			j--;
		}
		else {
			if (dp[i - 1][j] > dp[i][j - 1])	i--;
			else
			{
				j--;
			}
		}
	}
	for (int i = p.size() - 1; i >= 0; i--) {
		cout << p[i];
	}
	cout << endl;
}


int main() {
	int n = 6;
	int m = 7;
	string a = "144912";
	string b = "4898172";
	int dp[7][8] = { 0 };
	cout << T(a, b, n, m, dp) << endl;;
	truy_vet(a, n, b, m, dp);
	return 0;
}