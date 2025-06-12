#include<iostream>
#include<vector>
using namespace std;

struct Meeting {
	string chuDe;
	float timeStart;
	float timeEnd;
};

void quickSort(vector<Meeting>& d, int left, int right) {
	if (left >= right)	return;
	int i = left, j = right;
	float pivot = d[(left + right) / 2].timeEnd;
	while (i <= j) {
		while (d[i].timeEnd < pivot)	i++;;
		while (d[j].timeEnd > pivot)	j--;
		if (i <= j) {
			swap(d[i], d[j]);
			i++;
			j--;
		}
	}
	quickSort(d, left, j);
	quickSort(d, i, right);
}

void T1(vector<Meeting> &s, vector<Meeting> d, int n) {
	float lastfinal = 0;
	for (int i = 0; i < n; i++) {
		if (d[i].timeStart >= lastfinal) {
			s.push_back(d[i]);
			lastfinal = d[i].timeEnd;
		}
	}
}

void print_list(vector<Meeting> d) {
	cout << "chuDe\t\t\t" << "timeStart\t" << "timeEnd" << endl;
	for (int i = 0; i < d.size(); i++) {
		cout << d[i].chuDe<<"\t\t" << d[i].timeStart<<"\t" << d[i].timeEnd << endl;
	}
	cout << endl;
}

int main() {
	int n = 5;
	vector<Meeting> d;
	d.push_back({ "find job", 8, 8.5 });
	d.push_back({ "impprove skill", 9, 11 });
	d.push_back({ "how to study better", 10, 11.5 });
	d.push_back({ "IoT", 12, 13 });
	d.push_back({ "make mind set", 11, 11.5 });

	print_list(d);
	quickSort(d, 0, n - 1);

	vector<Meeting> s;
	T1(s, d, n);
	print_list(s);
	return 0;
}