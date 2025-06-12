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

bool F1(vector<Quat>& newarr, vector<Quat> arr, int n, int p){ //1, 2 , 5 , 10
	int i = 0;
	while(p > 0 && i < n){
		if(p >= arr[i].giaban){
			newarr.push_back(arr[i]);
			p = p - arr[i].giaban;
		}
		i++;
	}
	return i >0;
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
	int p = 700000;
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
	bool check = F1(c, arr, n, p);
	int u = c.size();
	
	cout<<"SoTienco: "<<p<<endl;
	if(check){
		cout<<"So Luong quat it nhat de vua su so tien p la : "<<u<<endl;
		print_arr(c);
	}
	else{
		cout<<"Khong du tien de mua quat"<<endl;
	}
	return 0;
}