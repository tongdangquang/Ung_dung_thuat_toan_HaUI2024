#include <iostream>

#define MAX 20

using namespace std;

long ds[MAX] = {60, 57, 95, 10, 55, 90, 9, 24, 13, 57, 37, 80, 58, 50, 70, 55, 99, 66, 54, 68};

void merge(long ds[], int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;
	
	long L[n1], R[n2];
	
	for (int i = 0; i < n1; i++) L[i] = ds[l + i];
	for (int j = 0; j < n2; j++) R[j] = ds[m + 1 + j];
	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			ds[k] = L[i];
			i++;
		} else {
			ds[k] = R[j];
			j++;
		}
		k++;
	}
	
	while (i < n1) {
		ds[k] = L[i];
		i++;
		k++;
	}
	
	while (j < n2) {
		ds[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(long ds[], int l, int r) {
	if (r > l) {
		int  m = l + (r - l) / 2;
		mergeSort(ds, l, m);
		mergeSort(ds, m + 1, r);
		merge(ds, l, m, r);	
	}
}

bool isPositive(int n) {
    if (n % 2 == 0)
        return true;
    return false;
}

int main() 
{
    mergeSort(ds, 0, MAX - 1);
	cout << "Gia tri lon nhat trong day da cho la: " << ds[MAX - 1];
}