#include <iostream>
#include <vector>
using namespace std;

struct HS {
	string ten;
	string hoDem;
	int namSing;
	string diaChi;
};

void sort_HS(vector<HS>& d, int left, int right) {
	if (left >= right)	return;
	int i = left, j = right;
	string pivot = d[(i + j) / 2].ten;
	while (i <= j) {
		while (d[i].ten < pivot)	i++;
		while (d[j].ten > pivot)	j--;
		if (i <= j) {
			swap(d[i], d[j]);
			i++;
			j--;
		}
	}
	sort_HS(d, left, j);
	sort_HS(d, i, right);
}

int search(vector<HS>d, string P, int left, int right) {
	if (left > right) return -1;
	int m = (left + right) / 2;
	if (d[m].ten == P) return m;
	else if (d[m].ten < P) return search(d, P, m + 1, right);
	else return search(d, P, left, m - 1);
}


void print_arr(vector<HS> d) {
	for (int i = 0; i < d.size(); i++) {
		cout << d[i].ten << "\t" << d[i].hoDem << "\t" << d[i].namSing << "\t" << d[i].diaChi << endl;
	}
	cout << endl;
}

int main() {
	int n = 6;
	vector<HS> d;
	d.push_back({ "Dat", "Nguyen", 2004, "HaNoi" });
	d.push_back({ "Oliver", "RoBen", 2000, "HCM" });
	d.push_back({ "Joseph", "Jostar", 1999, "HaNoi" });
	d.push_back({ "Dio", "Brando", 1998, "HCM" });
	d.push_back({ "David", "Beckham", 1997, "HaNoi" });
	d.push_back({ "Cris", "Ronaldo", 1996, "HCM" });

	sort_HS(d, 0, 5);
	print_arr(d);

	string P = "Dataa";
	int ans = search(d, P, 0, 5);
	if (ans != -1) {
		cout << "Vi tri cua hoc sinh trong danh sach la: " << ans << endl;
		cout << "Thong tin:" << endl;
		cout << d[ans].ten << "\t" << d[ans].hoDem << "\t" << d[ans].namSing << "\t" << d[ans].diaChi << endl;
	}
	else cout << "Khong tim thay" << endl;
	return 0;
}
