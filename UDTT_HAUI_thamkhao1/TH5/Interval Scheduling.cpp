#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//sap xep theo chieu tang dan cua final
void quickSort(vector<float> &s, vector<float> &f, int left, int right){
	if(left >= right)	return;
	int i = left, j = right;
	float pivot = f[(left + right) / 2];
	while(i<=j){
		while(f[i] < pivot)	i++;
		while(f[j] > pivot)	j--;
		if(i<=j){
			swap(s[i], s[j]);
			swap(f[i], f[j]);
			i++;
			j--;
		}
	}
	quickSort(s,f,left, j);
	quickSort(s,f,i, right);
}

int A3(vector<float> start, vector<float> final,int n, queue<int> &ans){
	float last_final = 0;
	int dem = 0;
	for(int i = 0; i< n;i++){
		if (start[i] >= last_final)	{
			ans.push(i);
			last_final = final[i];
			dem ++;
		}
		
	}
	return dem;
}

void printAns(queue<int> ans, vector<float> start, vector<float> final, int a) {
	int i = 1;
	cout<<"So cong viec tuong hop max la: "<<a<<endl;
    while (!ans.empty()) {
        cout << "Cong viec "<<i<<" bat dau tu: "<<start[ans.front()]<<"h ket thuc luc: "<<final[ans.front()]<<"h"<<endl;
        ans.pop();
        i++;
    }
    cout << endl;
}
int main(){
	int n = 5;
	vector<float> start = { 8 , 9,  10,   12,11,   };
	vector<float> final = {8.5, 11, 11.5, 14, 11.5};
	
	quickSort(start, final, 0, n-1);
	queue<int> ans ;
	int a = A3(start, final, n, ans);
	printAns(ans, start, final, a);
	return 0;
}
