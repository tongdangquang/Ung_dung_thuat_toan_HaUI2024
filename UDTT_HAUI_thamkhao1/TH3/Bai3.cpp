#include<iostream>
using namespace std;

float soMax(float arr[], int left, int right) {
	if (left == right) {
		return arr[left];
	}
	int m = (left + right) / 2;
	float left_e = soMax(arr, left, m);
	float right_e = soMax(arr, m+1, right);
	if (left_e > right_e)	return left_e;
	else return right_e;
}

int main() {
	int n = 20;
	float arr[] = { -1.1, 9, 8, 7, -5.5, -7.7, 4, 3 , -2.2, -9.9, -15.5, 6, -14.4, -14.9, -15.5, -5.5, 5, 10, 2, 1 };
	cout << soMax(arr, 0, 19) << endl;
	return 0;
}
