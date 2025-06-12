#include<iostream>
using namespace std;

float soChanMax(int arr[], int left, int right) {
	if (left == right) {
		if (arr[left] % 2)	return 0;
		return arr[left];
	}
	int m = (left + right) / 2;
	float left_e = soChanMax(arr, left, m);
	float right_e = soChanMax(arr, m+1, right);
	return max(left_e, right_e);
}

int main() {
	int n = 20;
	int arr[] = { 15, 9, 8, 7, 17, 18, 4, 3 , 19, 21, 11, 6, 16, 17, 20, 25, 5, 10, 2, 1 };
	cout << soChanMax(arr, 0, 19) << endl;
	return 0;
}
