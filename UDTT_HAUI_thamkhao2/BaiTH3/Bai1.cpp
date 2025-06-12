#include <iostream>

#define MAX 6

using namespace std;

struct HOCSINH {
	string ten;
	string tenDem;
	int namSinh;
	string diaChi;	
};

void merge(HOCSINH hs[], int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;
	
	HOCSINH L[n1], R[n2];
	
	for (int i = 0; i < n1; i++)
		L[i] = hs[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = hs[m + 1 + j];
	int i = 0;
	int j = 0;
	int k = l;
	while (i < n1 && j < n2) {
		if (L[i].ten <= R[j].ten) {
			hs[k] = L[i];
			i++;
		} else {
			hs[k] = R[j];
			j++;
		}
		k++;
	}
	
	while (i < n1) {
		hs[k] = L[i];
		i++;
		k++;
	}
	
	while (j < n2) {
		hs[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(HOCSINH hs[], int l, int r) {
	if (r > l) {
		int  m = l + (r - l) / 2;
		mergeSort(hs, l, m);
		mergeSort(hs, m + 1, r);
		merge(hs, l, m, r);	
	}
}

int timKiem(HOCSINH hs[], int l, int r, string &ten) {
	if (r >= l) {
		int mid = l + (r - l) / 2;
		if (hs[mid].ten == ten) {
			return mid;
		}
		if (hs[mid].ten < ten) {
			return timKiem(hs, mid + 1, r, ten);
		}
		return timKiem(hs, l, mid - 1, ten);
	}
	return -1;
}

void hienThi(HOCSINH hs[], int n)
{
	for (int i = 0; i < n; i++)
		cout << hs[i].tenDem << " " << hs[i].ten << " " << hs[i].namSinh << " " << hs[i].diaChi << " \n";
}

int main() 
{
	HOCSINH hs[MAX] = {
		{"anh", "nguyen van", 2000, "c"},
		{"an", "le phuong", 2000, "c"},
		{"bang", "nguyen dinh", 2000, "c"},
		{"binh", "tran nguyen", 2000, "c"},
		{"hieu", "le trung", 2000, "c"},
		{"tam", "nguyen thi", 2000, "c"}
	};
	cout << "Danh sach khoi tao: \n";
	hienThi(hs, MAX);
	mergeSort(hs, 0, MAX - 1);
	cout << "Danh sach sau khi duoc sap xep: \n";
	hienThi(hs, MAX);
	string ten = "asda";
	int viTri = timKiem(hs, 0, MAX - 1, ten);
	if (viTri != -1) {
		cout << "vi tri: " << viTri << endl;
		cout << hs[viTri].tenDem << " " << hs[viTri].ten << " " << hs[viTri].namSinh << " " << hs[viTri].diaChi << " \n";
	} else {
		cout << "Khong tim thay ten can tim" << endl;
	}
}