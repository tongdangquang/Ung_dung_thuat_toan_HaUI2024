//Hoan vi n phan tu
#include<iostream>
#include<vector>
using namespace std;

void next_config(vector<int> &arr, int n, int i) {
	int k = n;
	while (arr[k] < arr[i])	k--;
	swap(arr[k], arr[i]);
	i++;
	int j = n;
	while (i < j) {
		swap(arr[i], arr[j]);
		i++;
		j--;
	}
}

void view_config(vector<int> arr, int n) {
	for (int i = 1; i <= n; i++) {
		cout << arr[i] << " " ;
	}
	cout << endl;
}

void list_config(int n) {
	int i;
	vector<int> arr(n + 1, 0);
	for (int i = 1; i <= n; i++)	arr[i] = i;
	int it = 1;
	do
	{
		cout << "Config: " << it << " : ";
		view_config(arr, n);
		it++;
		i = n - 1;
		while (i > 0 && arr[i] > arr[i + 1]) {
			i--;
		}
		if (i > 0) next_config(arr, n, i);
	} while (i > 0);
}

int main() {
	list_config(6);
	return 0;
}