#include <iostream>

using namespace std;

struct DienThoai{
    string nhanHieu;
    int kichThuoc;
    int giaBan;
};

void qhd(DienThoai ds[], int n, int s){
    int w[n + 1], v[n + 1];
    for(int i = 1; i <= n; i++){
        w[i] = ds[i - 1].kichThuoc;
    }
    for(int i = 1; i <= n; i++){
        v[i] = ds[i - 1].giaBan;
    }
	int dp[n+1][s+1];
	for(int i = 0; i<= n; i++){
		for(int j = 0; j <= s; j++){
			dp[i][j] = 0;
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= s; j++){
			dp[i][j] = dp[i-1][j];
			if(j >= w[i]){
				dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]]+v[i]);
			}
		}
	}
	cout <<"Gia tri toi da: "<< dp[n][s] << endl;
	cout <<"Lay cac do vat thu: " << endl;
	int i = n - 1, j = s;
	while(i != 0){
		if(dp[i][j] != dp[i-1][j]){
			cout << ds[i].nhanHieu << ", " << ds[i].giaBan << endl;
			j = j - w[i];
		}
		i--;
	}
}

int main(){
    int n = 5;
    int s = 23;
    DienThoai ds[n] = {
        {"Samsung", 5, 4000000},
        {"Oppo", 5, 5000000},
        {"Xiaomi", 6, 6000000},
        {"Huawei", 6, 7000000},
        {"Apple", 6, 8000000},
    };
    qhd(ds, n, s);

    return 0;
}