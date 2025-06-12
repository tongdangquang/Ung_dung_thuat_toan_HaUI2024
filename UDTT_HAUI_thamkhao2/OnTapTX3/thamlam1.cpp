#include <iostream>

using namespace std;

struct QuatBan{
    string tenHangSX;
    string mauSac;
    int giaBan;
};

float G1(QuatBan d[], float c, float p){
    cout << "Danh sach nhieu nhat cac quat co the mua duoc la: " << endl;
    for(int i = 0; i < 6; i++){
        if(p >= d[i].giaBan){
            cout << d[i].tenHangSX << ", " << d[i].giaBan << endl;
            c++;
            p -= d[i].giaBan;
        }
    }
    cout << "So luong quat ban co the mua duoc: ";
    return c;
}

float G2(QuatBan d[], float u, int p){
    cout << "Danh sach it nhat cac quat can ban de duoc so tien bang " << p << endl;
    for(int i = 5; i >= 0; i--){
        if(p / d[i].giaBan > 0){
            cout << d[i].tenHangSX << ", " << d[i].giaBan << endl;
        }
        u += p / d[i].giaBan;
        p %= d[i].giaBan;
    }
    cout << "So luong: ";
    return u;
}

int main(){
    QuatBan d[6] = {
    {"Toshiba", "Den", 100000},
    {"Panasonic", "Trang", 150000},
    {"Senko", "Hong", 200000},
    {"Kangaroo", "Vang", 310000},
    {"Panasonic", "Tim", 370000},
    {"Toshiba", "Xanh", 500000},
    };
    int p = 1000000;
    int n = 6;
    float c = 0, u = 0;
    cout << G1(d, c, p) << endl;
    cout << "-----------------------------------------------" << endl;
    cout << G2(d, u, p);

    return 0;
}