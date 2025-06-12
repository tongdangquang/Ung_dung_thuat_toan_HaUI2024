//sinh tap con k phan tu cua tap S co n phan tu
#include<iostream>
#include<vector>
using namespace std;

void next_config(vector<int>& arr, int k, int i) {
	arr[i] += 1;
	i++;
	while (i <= k) {
		arr[i] = arr[i - 1] + 1;
		i++;
	}
}

void view_config(vector<int> arr, int k) {
	for (int i = 1; i <= k; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void list_config(int k, int n) {
	int i;
	vector<int> arr(k + 1, 0);
	for (int i = 1; i <= k; i++)	arr[i] = i;
	do {
		view_config(arr, k);
		i = k;
		while (i > 0 && arr[i] == n - k + i)	i--;
		if (i > 0)	next_config(arr, k, i);
	} while (i > 0);
}

int main() {
	list_config(4, 6);
	return 0;
}