//Sinh day nhi phan 2 ky tu: 'a', 'b'.
#include<iostream>
#include<vector>
using namespace std;
void next_config(vector<bool>& arr, int n, int i) {
	arr[i] = 1;
	i++;
	while (i <= n) {
		arr[i] = 0;
		i++;
	}
}

void view_config(vector<bool> arr, int n) {
	for (int i = 1; i <= n; i++) {
		switch (arr[i]) {
		case 0: cout << "a "; break;
		case 1: cout << "b "; break;
		}
	}
	cout << endl;
}

void list_config(int n) {
	int i;
	vector<bool> arr(n + 1, 0);
	do {
		view_config(arr, n);
		i = n;
		while (i > 0 && arr[i] == 1)	i--;
		if (i > 0)	next_config(arr, n, i);
	} while (i > 0);
}
int main() {
	list_config(4);
	return 0;
}