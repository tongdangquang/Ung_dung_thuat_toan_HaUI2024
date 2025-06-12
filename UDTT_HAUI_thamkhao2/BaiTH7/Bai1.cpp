#include <iostream>

using namespace std;

void A1(char *S) {
	int n = strlen(S);
	int count = 0;
	for (int i = 0; i < n / 2; i++) {
		if (S[i] == S[n - 1 - i]) {
			count++;
			cout << count;
		}
	}
	if (count == n / 2) {
		cout << "Xau doi xung";
	} else {
		cout << "Xau ko doi xung";
	}
}

void A2(char *S) {
	
}

int main() {
	char S[] = "memoomem";
	A1(S);
}