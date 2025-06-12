#include<iostream>
#include<vector>
using namespace std;

struct Quat{
	string tenhang;
	string mausac;
	int giaban;
};

void qsort(vector<Quat>& arr, int left, int right){
	if(left >= right)	return;
	int i = left, j = right;
	int pivot = arr[(left+right)/2].giaban;
	while(i <=  j){
		while(arr[i].giaban > pivot) i++;
		while(arr[j].giaban < pivot) j--;
		if(i<=j){
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	qsort(arr, left, j);
	qsort(arr, i, right);
}

void F1(vector<Quat>& newarr, vector<Quat> arr, int n, int p){
	int i = 0;
	int tongtien = 0;
	while(i < n){
		if(tongtien + arr[i].giaban < p){
			newarr.push_back(arr[i]);
			tongtien +=	arr[i].giaban;
		}
		else{
			break;
		}
		i++;	
	}
	for(int j = n - 1; j >= i; j--){
		if(tongtien + arr[j].giaban > p){
			newarr.push_back(arr[j]);
			break;
		}
	}
}

void print_arr(vector<Quat> arr){
	cout<<"Danh sach quat: "<<endl;
	cout<<"TenHang"<<"\t"<<"MauSac"<<"\t"<<"GiaBan"<<"\t"<<endl;
	for(int i =0; i<arr.size();i++){
		cout<<arr[i].tenhang<<"\t"<<arr[i].mausac<<"\t"<<arr[i].giaban<<endl;
	}
	cout<<endl;
}

int main(){
	int n = 6;
	int p = 600000;
	vector <Quat> arr;
	arr.push_back({"Hang1", "Do", 300000});
	arr.push_back({"Hang2", "Do", 250000});
	arr.push_back({"Hang3", "Xanh", 200000});
	arr.push_back({"Hang4", "Hong", 400000});
	arr.push_back({"Hang2", "Den", 350000});
	arr.push_back({"Hang1", "Trang", 300000});
	
	qsort(arr, 0, n-1);
	print_arr(arr);
	
	vector<Quat> c;
	F1(c, arr, n, p);
	int u = c.size();
	
	cout<<"SoTienco: "<<p<<endl;

	cout<<"So Luong quat it nhat de co so tien lon hon p la : "<<u<<endl;
	print_arr(c);

	return 0;
}