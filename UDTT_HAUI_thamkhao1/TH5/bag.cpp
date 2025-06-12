#include<iostream>
#include<vector>
using namespace std;

struct Hang {
	float klg;
	float sz;
};

bool A3(vector<Hang>& x, vector<Hang> d, int n, float k, float& ans) {
	int i = 1;
	ans = 0;
	while (k > 0 && i < n) {
		if (k >= d[i].sz) {
			x.push_back(d[i]);
			ans += d[i].klg;
			k = k - d[i].sz;
		}
	}
	if (x.size() == 0)	return false;
	return true;
}

int main() {
	int n = 5;
	vector<Hang> d;
	d.push_back({4,4});
	d.push_back({3.5, 1});
	d.push_back({3, 2});
	d.push_back({2.5, 3});
	d.push_back({2, 2});
}
