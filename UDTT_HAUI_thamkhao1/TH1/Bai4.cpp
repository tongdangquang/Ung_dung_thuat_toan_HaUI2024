#include<iostream>
#include<vector>
using namespace std;


void next_config(vector<int> &arr, int k, int i) {
	arr[i] += 1;
	i += 1;
	while (i <= k) {
		arr[i] = arr[i - 1] + 1;
		i++;
	}
}
void view_config(vector<int> arr,vector<string> input, int k) {
	for (int i = 1; i <= k; i++) {
		switch (arr[i])
		{
		case 1:	cout << input[arr[i]] <<"\t "; break;
		case 2:	cout << input[arr[i]] <<"\t "; break;
		case 3:	cout << input[arr[i]] <<"\t "; break;
		case 4:	cout << input[arr[i]] <<"\t "; break;
		case 5:	cout << input[arr[i]] <<"\t "; break;
		case 6:	cout << input[arr[i]] <<"\t "; break;
		}
	}
	cout << endl;
}

void list_config(vector<string> input, int k, int n) {
	int i;
	vector<int> arr(k + 1, 0);
	for (int i = 1; i <= k; i++) arr[i] = i;
	int it = 1;
	do {
		cout << "Config " << it << " :\t";
		view_config(arr, input, k);
		it += 1;
		i = k;
		while (i > 0 && arr[i] == n - k + i)	i--;
		if (i > 0)	next_config(arr, k, i);
	} while (i > 0);
}

int main() {
	vector<string> input = { "", "Trang", "Cong", "Trung", "Binh", "Hoa", "Mai" };
	int n = input.size() - 1;
	int k = 4;
	list_config(input, k, n);
	return 0;
}