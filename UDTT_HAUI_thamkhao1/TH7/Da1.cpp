#include <iostream>
using namespace std;

string s = "abcdedc123";

bool A1(string s){
	int left = 0, right = s.length() - 1;
	while(left < right){
		if(s[left] != s[right])	return false;
		left ++;
		right --;
	}
	return true;
}

int A2(string s, int k) {
    int maxLength = 1;
    int left = k, right = k;

    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        maxLength = max(maxLength, right - left + 1);
        left--;
        right++;
    }
return maxLength;
}

int main(){
	cout<<A1(s)<<endl;
	int k = 4;
	cout<<A2(s, k)<<endl;
	return 0;
}


