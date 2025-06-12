#include<iostream>
#include<vector>
using namespace std;

void quick_sort(vector<string>& d, int left, int right) {
	if (left >= right) return;
	int i = left, j = right;
	int pivot = d[(left + right) / 2].length();
	while (i <= j) {
		while (d[i].length() > pivot)	i++;
		while (d[j].length() < pivot)	j--;
		if (i <= j) {
			swap(d[i], d[j]);
			i++;
			j--;
		}
	}
	quick_sort(d, left, j);
	quick_sort(d, i, right);
}

void print_list(vector<string> d) {
	for (int i = 0; i< d.size(); i++) {
		cout << d[i] << endl;
	}
	cout << endl;
}

bool G(vector<string>d, int n, int k, string &p) {
	int i = 0;
	while (k > 0 && i < n) {
		if (d[i].length() <= k) {
			p += d[i];
			k = k - d[i].length();
		}
		i++;
	}
	if (k > 0)	return false;
	else return true;
}

int char_int_string(char a, string P) {
	for (int i = 0; i < P.size(); i++) {
		if (a == P[i])	return i;
	}
	return -1;
}


bool Boyer_Moore_Horspool(string P, string T) {
	int v = P.length();
	int i = v - 1;
	while (i < T.length()) {
		int k = v - 1;
		while (k >= 0 && T[i] == P[k]) {
			k--;
			i--;
		}
		if (k < 0)	return true;
		else {
			int x = char_int_string(T[i], P);
			if (x < 0)	i = i + v;
			else	i = i + v - x - 1;
		}
	}
	return false;
}

void G2(vector<string>& z, vector<string> d, string P) {
	for (int i = 0; i < d.size(); i++) {
		if (Boyer_Moore_Horspool(P, d[i])) {
			z.push_back(d[i]);
		}
	}
}

int z_algo(string P, string T) {
	string S = P + "$" + T;
	int n = S.length();
	int* z = new int[n];
	int left = 0;
	int right = 0;
	int dem = 0;
	for (int i = 1; i < n; i++) {
		if (i > right) {
			left = right = i;
			while (right < n && S[right - left] == S[right])	right++;
			z[i] = right - left;
			if (z[i] == P.length())	dem++;
			right--;
		}
		else if (z[i - left] = right - i + 1) {
			z[i] = z[i - left];
		}
		else {
			left = i;
			while (right < n && S[right - left] == S[right])	right++;
			z[i] = right - left;
			if (z[i] == P.length())	dem++;
			right--;
		}
	}
	return dem;
}

void G3(vector<string> d) {
	for (int i = 1; i < d.size(); i++) {
		int dem = z_algo(d[0], d[i]);
		if (dem)	cout << d[i] << "\t" << dem << endl;;
	}
}


int main() {
	int n = 5;
	int k = 6;
	vector<string> d;
	d.push_back("Nguyen");
	d.push_back("Dat dep trai");
	d.push_back("Nguyen Doan Dat");
	d.push_back("Nguyen Thi H");
	d.push_back("Nguyen Van Nguyen");
	d.push_back("children is the future of human");
	d.push_back("all child in garden is my friend");

	print_list(d);
	quick_sort(d, 0, n - 1);
	string p = "";
	bool check = G(d, n, k, p);
	if (check) cout << p << endl;
	else cout << "Khong the tao chuoi thoa man" << endl;

	//vector<string> z;
	//string P = "child";
	//G2(z, d, P);
	//print_list(z);
	// G3(d);

	return 0;
}