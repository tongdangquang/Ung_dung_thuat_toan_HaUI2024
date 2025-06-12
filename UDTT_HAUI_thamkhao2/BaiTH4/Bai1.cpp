#include <iostream>

#define MAX 4

using namespace std;

int n = MAX;
int x[MAX];

string N[] = {"TUNG", "CUC", "TRUC", "MAI"};
char G[] = {'A', 'B', 'C', 'D'};

int c1 = 0, c2 = 0;
int dd[1];

// thuat toan A1: pp sinh

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void view_config(int x[], int n) {
	for (int i = 1; i <= n; i++)
		cout << N[x[i] - 1] << " " << G[i - 1] << ", ";
	cout << endl;
}

void next_config(int x[], int n, int i) {
	int k = n;
	while (x[i] > x[k]) 
		k--;
	swap(x[i], x[k]);
	int j = n;
	i++;
	while (i < j) {
		swap(x[i], x[j]);
		i++;
		j--;
	}
}

void list_configs(int n) {
	int i, x[n + 1] = {0};
	for (i = 1; i <= n; i++) x[i] = i;
	do {
		view_config(x, n);
		i = n - 1;
		while(i > 0 && x[i] > x[i + 1]) i--;
		if (i > 0) next_config(x, n, i);
		c1++;
	} while (i > 0);
}

// thuat toan A2: quay lui

void show(int x[]) {
	for (int i = 1; i <= n; i++)
		cout << N[x[i] - 1] << " " << G[i - 1] << ", ";
	cout << endl;
}

void Try(int k) {
	for (int i = 1; i <= n; i++) {
		if (dd[i] == 0) {
			x[k] = i;
			if (k == n) {
				c2++;
				show(x);
			} else {
				dd[i] = 1;
				Try(k + 1);
				dd[i] = 0;
			}
		}
	}
}

int main() {
	cout << "Phuong phap sinh" << endl;
	// list_configs(MAX);
	cout << "So cach sap xep la: " << c1 << "\n\n";
	
	cout << "Phuong phap quay lui" << endl;
	Try(1);
	cout << "So cach sap xep la: " << c2 << endl;
}