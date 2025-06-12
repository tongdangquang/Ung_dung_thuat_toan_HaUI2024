#include<iostream>
#include<vector>
using namespace std;

struct Bag {
	int weight;
	int value;
};

void Q2(vector<Bag> d, int n, int m, int dp[7][13]) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j >= d[i].weight) {
				int temp = dp[i - 1][j - d[i].weight] + d[i].value;
				if (temp > dp[i][j])	dp[i][j] = temp;
			}
		}
	}
}

void truy_vet(vector<Bag>& x, vector<Bag> d, int n, int m, int dp[7][13], int& max_value) {
	max_value = dp[n][m];
	int i = n, j = m;
	while (i != 0) {
		if (dp[i][j] != dp[i - 1][j]) {
			x.push_back(d[i]);
			j -= d[i].weight;
		}
		i--;
	}
}

void printAns(vector<Bag> x) {
	cout << "weight\t" << "value" << endl;
	for (int i = 0; i < x.size(); i++) {
		if (x[i].value != 0) {
			cout << x[i].weight << "\t" << x[i].value << endl;
		}
	}
	cout << endl;
}

int main() {
	int m = 12;
	int n = 6;
	vector<Bag> d;
	d.push_back({ 0 , 0 });
	d.push_back({ 3 , 4});
	d.push_back({ 6 , 5 });
	d.push_back({ 2 , 2 });
	d.push_back({ 7 , 6 });
	d.push_back({ 1 , 1 });
	d.push_back({ 5 , 3 });

	cout << "Danh sach hang:" << endl;
	printAns(d);

	int dp[7][13] = { 0 };
	Q2(d, n, m, dp);
	vector<Bag> x;
	int max_value = 0;
	truy_vet(x, d, n, m, dp, max_value);
	
	cout << "Kich thuoc balo: " << m << endl;
	cout << "So luong hang lay duoc la: " << x.size();
	cout << " va gia tri toi da la: " << max_value << endl;
	cout << "Danh sach hang:" << endl;
	printAns(x);
	return 0;
}
