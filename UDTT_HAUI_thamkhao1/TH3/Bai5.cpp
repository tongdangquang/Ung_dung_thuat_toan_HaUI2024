#include<iostream>
using namespace std;

float tinhtongduong(float arr[], int left, int right) {
	if (left == right) {
		if (arr[left] > 0)	return arr[left];
		return 0;
	}
	int m = (left + right) / 2;
	float left_sum = tinhtongduong(arr, left, m);
	float right_sum = tinhtongduong(arr, m+1, right);
	return left_sum + right_sum;
}

int main() {
	int n = 20;
	float arr[] = { -1.1, 9, 8, 7, -5.5, -7.7, 4, 3 , -2.2, -9.9, -15.5, 6, -14.4, -14.9, -15.5, -5.5, 5, 10, 2, 1 };
	cout << tinhtongduong(arr, 0, 19) << endl;
	return 0;
}
