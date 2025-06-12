#include <iostream>

#define MAX 15

using namespace std;

double ds[MAX] = {3.5, 2.5, 1.5, 6.6, 3.4, 5.6, 2.7, 4.8, 3.4, 8.6, 4.9, 3.6, 2.9, 5.3, 7.5};

void merge(double ds[], int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;
	
	double L[n1], R[n2];
	
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

void mergeSort(double ds[], int l, int r) {
	if (r > l) {
		int  m = l + (r - l) / 2;
		mergeSort(ds, l, m);
		mergeSort(ds, m + 1, r);
		merge(ds, l, m, r);	
	}
}

void hienThi(double ds[], int n)
{
	for (int i = 0; i < n; i++)
		cout << ds[i] << " ";
}

int main() {
	cout << "Day khoi tao la: \n";
	hienThi(ds, MAX);
	
	mergeSort(ds, 0, MAX - 1);
	cout << "\nDay sau khi duoc sap xep la: \n";
	hienThi(ds, MAX);
}