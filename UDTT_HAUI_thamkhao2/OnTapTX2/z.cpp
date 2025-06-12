#include <iostream>
#include <string.h>

using namespace std;

void zalgo(char s[], int *z, int size) {
    int n = size, l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if(i > r){
            l = r = i;
            while (r < n && s[r - l] == s[r]){
                r++;
            }
            z[i] = r - l;
            r--;
        }else if(z[i - l] < r - i + 1){
            z[i] = z[i - l];
        }else {
            l = i;
            while(r < n && s[r - l] == s[r]){
                r++;
            }
            z[i] = r - l;
            r--;
        }
    }

}

int dem(int z[], char p[], int size){
    int count = 0;
    int p_size = strlen(p);
    for(int i = p_size + 1; i < size; i++){
        if(z[i] == p_size){
            count++;
        }
    }
    return count;
}

int main() {
    char t[50] = "Ban Viet o Viet Nam";
    char p[10] = "Viet";
    char s[50];
    int size = strlen(s);
    int z[size] = {0};
    zalgo(s, z, size);
    if (dem(z, p, size)) {
        cout << "Chuoi p co xuat hien trong chuoi t!" << endl;
    }
    cout << "So lan xuat hien cua chuoi con la: " << dem(z, p, size);
}