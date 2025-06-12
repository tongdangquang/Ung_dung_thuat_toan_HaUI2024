#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int>arr;
void show(vector<int> arr) {
	for (int i = 1; i <= n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void Try(int k) {
	for (int i = 0; i <= 1; i++) {
		arr[k] = i;
		if (k == n)	show(arr);
		else {
			Try(k + 1);
		}
	}
}

int main() {
	n = 4;
	arr.resize(n + 1, 0);
	Try(1);
	return 0;
}