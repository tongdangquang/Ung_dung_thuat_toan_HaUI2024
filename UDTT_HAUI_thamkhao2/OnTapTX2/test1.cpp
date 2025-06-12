#include <bits/stdc++.h>

using namespace std;

struct tulanh {
	char hang[50];
	int dientich;
	double gia;
};

void hienthi(int *kq, tulanh *a, int dem) {
	for(int i=0; i<dem; i++) {
		cout << a[kq[i]].hang <<" - " << a[kq[i]].dientich <<" - "<<a[kq[i]].gia<<endl;
	}
}

bool cmp(tulanh a,tulanh b) {
	return a.gia<b.gia;
}

bool thamlam(tulanh *a, int *kq, double p, int n, int &dem) {
    sort(a,a+n,cmp); 
	for(int i=0; i<n; i++) {
		if(p >= a[i].gia) {
			p -= a[i].gia;
			kq[dem] = i;
			dem++;
		}
	}
	if(p>= 0) return true;
	return false;
}

void algorithm_qhd(tulanh* a, int n, int kt, double bang[][100]) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= kt; j++) {
            bang[i][j] = 0;
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= kt; ++j) {
            bang[i][j] = bang[i - 1][j];
            if (a[i - 1].dientich <= j) {
                int temp = a[i - 1].gia + bang[i - 1][j - a[i - 1].dientich];
                if (bang[i][j] < temp){
                    bang[i][j] = temp;
                }
            }
        }
    }
}

void result(tulanh* a, int n, int kt, double bang[][100], int& sluong, int* kqua) {
    double max = bang[n][kt];
    int w = kt;

    for (int i = n; i > 0 && max > 0; i--) {
        if (max != bang[i - 1][w]) {
            kqua[sluong] = i - 1;
            w -= a[i - 1].dientich;
            max -= a[i - 1].gia;
            sluong++;
        }
    }
}

int main() {
	int n=7;
	tulanh *a = new tulanh[n];
	a[0] = {"Panasonic1",1,150000};
	a[1] = {"Panasonic2",5,440000};
	a[2] = {"Panasonic3",4,610000};
	a[3] = {"Panasonic4",4,550000};
	a[4] = {"Panasonic5",6,320000};
	a[5] = {"Panasonic6",8,340000};
	a[6] = {"Panasonic7",9,400000};

    // bai toan tham lam 
	int *kq = new int[n];   // mang luu ket qua 
	double p = 500000.5;
	int dem = 0;
	if(thamlam(a,kq,p,n,dem)) {
		hienthi(kq,a,dem);
		cout<<"So luong tu lanh mua duoc toi da la: "<<dem<<endl;
	} else {
		cout << "Khong tim ra ket qua bai toan";
	}

    // quy hoach dong 
    int kt = 15;  // K�ch thuoc t�i
    double bang[100][100];  // Bang quy hoach dong
    int kqua[kt];  // Mang luu chi so cua c�c dien thoai duoc chon
    int sluong = 0;
    
    algorithm_qhd(a,n,kt,bang);
    result(a,n,kt,bang,sluong,kqua);

    cout << "\nSo luong dien thoai: " << sluong << endl;
    cout << "Danh sach dien thoai:" << endl;
    hienthi(kqua,a,sluong);
	return 0;
}