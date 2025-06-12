#include <iostream>

using namespace std;

struct TuLanh {
	string hang;
	int dientich;
	float trongluong;
};

void Q(TuLanh *d, int n, int s) {
	float F[n][s];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < s; j++) {
			F[i][j] = 0.0;
		}
	}
	int w = s;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= s; j++) {
			F[i][j] = F[i - 1][j];
			if (d[i].dientich <= j) {
				float temp = d[i].trongluong + F[i - 1][j - d[i].dientich];
				if (F[i][j] < temp) F[i][j] = temp;
			}
		}
	}
	
	cout << endl << "BANG PHUONG AN" << endl << endl;
	cout << " \t";
	for (int i = 0; i < s; i++) cout << i << "\t";
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << i + 1 << "\t";
		for (int j = 0; j < s; j++) cout << F[i][j] << "\t";
		cout << endl;
	}
}

int main() {
	int n = 5, s = 14;
	TuLanh d[n];
	d[0] = {"A", 2, 7.8};
	d[1] = {"B", 3, 8.2};
	d[2] = {"C", 5, 9.5};
	d[3] = {"D", 6, 6.0};
	d[4] = {"E", 8, 7.0};
//	d[5] = {"F", 9, 7.8};
//	d[6] = {"G", 12, 7.8};

	Q(d, n, s);
}