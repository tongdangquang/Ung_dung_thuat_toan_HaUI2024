#include<iostream>
using namespace std;

#define INF 1e9

#define N 9
int n = N;
//day a: 1,8,3,4,9,10,5,11,7
float a[N+2] = {0,1,8,3,4,9,10,5,11,7,0};
int L[N+2]; // do dai day con don dieu tang dai nhat bat dau tu a[i]
		// co so: L[n+1] = 1;
int T[N+1]; // luu phuong an
void Q3(){
	a[0] = - INF;
	a[n+1] = INF;
	L[n+1] = 1;
	for(int i = n; i>=0; i--){
		int jmax = n+1;
		for(int j = i+1; j<=n+1;j++){
			if(a[j] > a[i] && L[j] > L[jmax])	jmax = j;
		}
		L[i] = L[jmax]+1;
		T[i] = jmax;
	}
}

void result(int &u, float *b){
	u = 0;
	int k = T[0];
	while(k != n+1){
		b[u] = a[k];
		k = T[k];
		u++;
	}
}

int main(){
	Q3();
	
	int u = 0;
	float * b = new float[n];
	result(u,b);
	cout<<"day con: "<<endl;
	for (int i = 0; i<u;i++ ){
		cout<< b[i] <<" ";
	}
	return 0;
}
