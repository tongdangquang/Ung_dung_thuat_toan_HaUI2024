#include<iostream>
#include<vector>
using namespace std;

void next_config(vector<int>& arr, int n, int i) {
	int k = n;
	while (arr[k] < arr[i]) {
		k--;
	}
	swap(arr[k], arr[i]);
	i++;
	int j = n;
	while (i < j) {
		swap(arr[i], arr[j]);
		i++;
		j--;
	}
}
void view_config(vector<int> arr, vector<string> input, int n) {
	for (int i = 1; i <= n; i++) {
		cout << i << ".";
		switch (arr[i])
		{
		case 1: cout << input[arr[i]]<<" "; break;
		case 2: cout << input[arr[i]]<< " "; break;
		case 3: cout << input[arr[i]]<< " "; break;
		case 4: cout << input[arr[i]]<< " "; break;
		case 5: cout << input[arr[i]]<< " "; break;
		case 6: cout << input[arr[i]]<< " "; break;
		}
	}
	cout << endl;
}
void list_config(vector<string> input, int n) {
	int i;
	vector<int> arr(n + 1, 0);
	for (int i = 1; i <= n; i++)	arr[i] = i;
	int it = 1;
	do {
		cout << "Config " << it << " : ";
		view_config(arr, input, n);
		it++;
		i = n - 1;
		while (i > 0 && arr[i] > arr[i + 1])	i--;
		if (i > 0)	next_config(arr, n, i);

	} while (i > 0);
}

int main() {
	vector<string> input = { "","Trang","Cong", "Trung", "Binh", "Hoan", "Mai"};
	int n = input.size() - 1;
	list_config(input, n);
	return 0;
}