#include<iostream>
using namespace std;



int z_algo(string P, string T) {
	string s = P + "$" + T;
	int n = s.length(); 
	int* z;
	z = new int[n];
	int left = 0;
	int right = 0;
	for (int i = 1; i < n; i++) {
		if (i > right) {
			left = right = i;
			while (right < n && s[right - left] == s[right])	right++;
			z[i] = right - left;
			if (z[i] == P.length())	return i - P.length() - 1;
			right--;
		}
		else if (z[i - left] < right - i + 1) {
			z[i] = z[i - left];
		}
		else 
		{
			left = i;
			while (right < n && s[right - left] == s[right])	right++;
			z[i] = right - left;
			if (z[i] == P.length())	return i - P.length() - 1;
			right--;
		}
	}
	return -1;
}


int main() {
	string T = "mothaibabonnamsaubay";
	string P = "y";



	cout << z_algo(P, T) << endl;

	cout << endl;
	return 0;
}