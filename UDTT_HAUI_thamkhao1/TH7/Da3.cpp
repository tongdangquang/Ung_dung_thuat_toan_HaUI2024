#include <iostream>
using namespace std;

string s = "Que kem co gia 1000, cuc tay cung co gai 1000, but co gia 2000";
string p = "1000";

int char_in_string(string ch, string p) {
    for (int i = 0; i < p.length(); i++) {
        if (p[i] == ch[0]) {
            return i;
        }
    }
    return -1;
}


int Boyer_morse_hospool(string s, string p) {
    int v = p.length(), i = v - 1;
    while (i < s.length()) {
        int k = v - 1;
        while (k > -1 && p[k] == s[i]) {
            i--;
            k--;
        }
        if (k < 0) {
            return i + 1;
        } else {
            int x = char_in_string(string(1, s[i]), p);
            if (x < 0) {
                i = i + v;
            } else {
                i = i + v - x - 1;
            }
        }
    }
    return -1;
}

int main(){
	cout<<Boyer_morse_hospool(s, p)<<endl; 
	return 0;
}
