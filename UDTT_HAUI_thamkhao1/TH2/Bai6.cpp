#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> arr;
vector<bool> mark;



void show(vector<int> arr) {
	for (int i = 1; i <= n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void Try(int k) {
	for (int i = 1; i <= n; i++) {
		if (mark[i] == 0) {
			arr[k] = i;
			if (k == n)	show(arr);
			else {
				mark[i] = 1;
				Try(k + 1);
				mark[i] = 0;
			}
		}
	}
	
}

int main() {
	n = 4;
	arr.resize(n + 1, 0);
	mark.resize(n + 1, 0);
	Try(1);
	return 0;
}