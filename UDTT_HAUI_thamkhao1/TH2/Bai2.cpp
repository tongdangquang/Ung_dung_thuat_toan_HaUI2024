#include<iostream>
using namespace std;

int UNCL(int m, int n) {
	while (n != 0) {
		int tg = m;
		m = n;
		n = tg % n;
	}
	return m;
}
int main() {
	cout<<UNCL(9,6);
	return 0;
}