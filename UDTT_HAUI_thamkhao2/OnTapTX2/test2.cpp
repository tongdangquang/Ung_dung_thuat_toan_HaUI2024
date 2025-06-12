#include <iostream>
#include <string.h>

using namespace std;

struct manhinh {
	char hangsx[50];
	double gia;
	double size;
};

// H�m tim ki tu trong chuoi 
int char_in_string(char a, char *P) {
    for (int i = 0; i < strlen(P); i++) {
        if (a == P[i]) return i;
    }
    return -1;
}

// H�m Boyer-Moore-Horspool �? �?m s? l?n xu?t hi?n c?a chu?i P trong chu?i T
bool BMH(char *P, char *T) {
int v = strlen(P);
	int i = v-1;
	while(i < strlen(T)) {
		int k = v-1;
		while(T[i] == P[k] && k >= 0) {
			i--;
			k--;
		}
		if(k<0) return true;
		else {
			int x = char_in_string(T[i],P);
			if(x<0) {
				i += v;
			} else {
				i += (v-x-1);
			}
		}
	}
	return false;
}


int main() {
	int n=7;
	manhinh *a = new manhinh[n];
	a[0] = {"Asus to 15 Asus", 960.5, 12.4};
	a[1] = {"LG to 17 Asus", 970.5, 13.1};
	a[2] = {"HP to 15 Asus", 981.5, 14.2};
	a[3] = {"SamSung to 13 Asus", 989, 15.3};
	a[4] = {"Lenovo to 12 Asus", 992.4, 16.4};
	a[5] = {"Macbook to 15 Asus", 999.9, 17.5};
	a[6] = {"Dell to 16 Asus", 1000.5, 18.6};
    
    // dem so lan xuat hien chuoi b trong a
    char b[40] = "12 Asus";
    int count_BMH = 0;
    for (int i = 0; i < n; i++) {
        count_BMH += BMH(b, a[i].hangsx);
    }
    cout << "So lan xuat hien cua chuoi b trong chuoi a (BMH): " << count_BMH << endl;

    return 0;
}