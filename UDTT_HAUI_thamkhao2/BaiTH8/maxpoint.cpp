#include<bits/stdc++.h>
using namespace std;
struct TuLanh{
	string tenHang;
	int dienTich;
	float trongLuong;
};

bool A(TuLanh *d,int n,int s,int &v,TuLanh *t){
	int i=1;
	int kt=s;
	while(i<=n && s>0){
		if(s>=d[i].dienTich){
			t[v++]=d[i];
			s-=d[i].dienTich;
		}
		i++;
	}
	if(s==kt)return false;
	return true;
}

void B(TuLanh *d,int n,int s,int &p,TuLanh *q,bool &flag){
	float F[n+1][s+1];
	for(int j=0;j<=s;j++){
		F[0][j]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=s;j++){
			F[i][j]=F[i-1][j];
			if(d[i].dienTich<j){
				float tmp=d[i].trongLuong+F[i-1][j-d[i].dienTich];
				if(F[i][j]<tmp){
					F[i][j]=tmp;
				}
			}
		}
	}
	if(F[n][s]==0){
		cout<<"\nKhong co phuong an";
		flag=false;
	}
	else{
		cout<<"\nBANG PHUONG AN:\n";
		for(int i=0;i<=n;i++){
			for(int j=0;j<=s;j++){
				cout<<F[i][j]<<"\t";
			}
		cout<<endl;
		}
	
		int i=n,j=s;
		while(i>0){
			if(F[i][j]!=F[i-1][j]){
				j=j-d[i].dienTich;
				q[p++]=d[i];
			}
			i--;
		}
	}
	
}

int main(){
	int n=6;
	int s=14;
	TuLanh d[n+1];

	d[1]={"Panasonic",2,65.6};
	d[2]={"Hitachi",3,68.86};
	d[3]={"Inventer",5,45.6};
	d[4]={"Funiki",6,34.6};
	d[5]={"SamSung",8,70.1};
	d[6]={"Sharp",9,50.2};

	int v=0;
	TuLanh t[n];
	cout<<"CAU 1:\n";
	if(A(d,n,s,v,t)){
		cout<<"So tu lanh nhieu nhat co the duoc xep la:"<<v<<endl;
		cout<<"DANH SACH TU LANH DUOC XEP LA :\n";
		for(int i=0;i<v;i++){
			cout<<t[i].tenHang<<endl;
		}
	}
	else{
		cout<<"Khong co phuong an\n";
	}
	
	
	
	cout<<"CAU 2:";
	int p=0;
	TuLanh q[n];
	bool flag=true;
	B(d,n,s,p,q,flag);
	cout<<endl;
	if(flag){
		cout<<"So tu lanh xep duoc: "<<p<<endl;
		cout<<"DANH SACH TU LANH:\n";
		for(int i=0;i<p;i++){
			cout<<q[i].tenHang<<endl;
		}
	}
	return 0;
}