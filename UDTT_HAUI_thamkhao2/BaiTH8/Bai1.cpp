#include <iostream>

using namespace std;

struct Quat
{
    char hang[30];
    char mau[10];
    int gia;
};

// thuat toan sap xep
void selectSort(Quat *d, int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (d[i].gia < d[j].gia)
                swap(d[i], d[j]);
}
void swap(Quat &a, Quat &b) {
    Quat temp = a;
    a = b;
    b = temp;
}

// Tim so luong ban nhieu nhat
bool A1(Quat *d, int n, int p, int &v1, Quat *t1) {
	int i = 0;
	int kt = p;
	while (i < n && p > 0) {
		if (p >= d[i].gia) {
			t1[v1++] = d[i];
			p -= d[i].gia;
		}
		i++;
	}
	if (p == kt) return false;
	return true;
}

// Tim so luong ban it nhat
bool A2(Quat *d, int n, int p, int &v2, Quat *t2) {
	int i = n - 1;
	int kt = p;
	while (i >= 0 && p > 0) {
		if (p >= d[i].gia) {
			t2[v2++] = d[i];
			p -= d[i].gia;
		}
		i--;
	}
	if (p == kt) return false;
	return true;
}

int main() {
    int n = 7;
	int p = 2000000;
	Quat d[n];
	d[0] = {"A", "Do", 230000};
	d[1] = {"B", "Do", 340000};
	d[2] = {"C", "Do", 560000};
	d[3] = {"D", "Do", 660000};
	d[4] = {"E", "Do", 710000};
	d[5] = {"F", "Do", 930000};
	d[6] = {"G", "Do", 980000};
	
	// Cau 1
	cout << "Cau 1: Thuat toan tham lam trong 2 truong hop" << endl;
	
	// TH1
	int v1 = 0, p1 = p;
	Quat t1[n];
	cout << "Truong hop 1:" << endl;
	if (A1(d, n, p, v1, t1)) {
		cout << "So quat nhieu nhat co the ban la: " << v1 << endl;
		cout << "Danh sach quat duoc ban voi so tien p = " << p << " la: " << endl;
		for (int i = 0; i < v1; i++) {
			p1 -= t1[i].gia;
			cout << i + 1 << " | " << t1[i].hang << " | " << t1[i].gia << " | So tien con lai: " << p1 << endl;
		}
	} else {
		cout << "Khong co phuong an!" << endl;
	}
	
	// TH2
	int v2 = 0, p2 = p;
	Quat t2[n];
	cout << "Truong hop 2:" << endl;
	if (A2(d, n, p, v2, t2)) {
		cout << "So quat it nhat co the ban la: " << v2 << endl;
		cout << "Danh sach quat duoc ban voi so tien p = " << p << " la: " << endl;
		for (int i = 0; i < v2; i++) {
			p2 -= t2[i].gia;
			cout << i + 1 << " | " << t2[i].hang << " | " << t2[i].gia << " | So tien con lai: " << p2 << endl;
		}
	} else {
		cout << "Khong co phuong an!" << endl;
	}

}