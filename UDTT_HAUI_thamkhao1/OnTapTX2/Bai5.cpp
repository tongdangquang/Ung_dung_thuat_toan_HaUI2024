#include <iostream>
#include <vector>
using namespace std;

struct LapTop {
    string tenHangSX;
    string cauHinh;
    int giaBan;
};

int char_in_string(char a, string P) {
    for (int i = 0; i < P.length(); i++) {
        if (a == P[i]) return i;
    }
    return -1;
}

int F1(string boNho, string cauHinh) {
    int v = boNho.length();
    int i = v - 1;
    while (i < cauHinh.length()) {
        int k = v - 1;
        while (k >= 0 && cauHinh[i] == boNho[k]) {
            i--;
            k--;
        }
        if (k < 0) return i + 1;
        else {
            int x = char_in_string(cauHinh[i], boNho);
            if (x < 0) i = i + v;
            else i = i + v - x - 1;
        }
    }
    return -1;
}

int F3(vector<LapTop> d) {
    int count = 0;
    for (int i = 0; i < d.size(); i++) {
        if (F1("RAM 16GB", d[i].cauHinh) != -1)  count++;
    }
    return count;
}

int main() {
    int n = 4;
    vector<LapTop> d;
    d.push_back({ "HP", "CPU 2.5GHz upto 3.5GHz - RAM 16GB - SSD 512GB", 15000000 });
    d.push_back({ "ACER", "CPU 2.5GHz upto 3.5GHz - RAM 8GB - HDD 2TB", 12000000 });
    d.push_back({ "TFUF", "CPU 2.5GHz upto 3.5GHz - RAM 16GB - HDD 2TB", 12000000 });
    d.push_back({ "ViVo", "CPU 2.5GHz upto 3.5GHz - RAM 8GB - SDD 512GB", 12000000 });

    int r = F3(d);
    cout << r << endl;
    return 0;
}
