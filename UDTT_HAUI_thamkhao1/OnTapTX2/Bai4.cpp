#include <iostream>
#include <vector>
using namespace std;

struct Phone {
    string nhanHieu;
    int kichThuoc; //donvi: mm
    int giaBan;
};

void QuyHoachDong(vector<Phone> d, int n, int s, int dp[6][1001]) 
{
    for (int j = 0; j <= s; j++) 
        dp[0][j] = 0;
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 0; j <= s; j++) 
        {
            dp[i][j] = dp[i - 1][j];
            if (d[i].kichThuoc <= j) 
            {
                int temp = dp[i - 1][j - d[i].kichThuoc] + d[i].giaBan;
                if (dp[i][j] < temp)
                    dp[i][j] = temp;
            }
        }
    }
}

void truy_vet(vector <Phone> &a, vector<Phone> d, int dp[6][1001], int n, int s, int& max_value) 
{
    max_value = dp[n][s];
    int i = n;
    int j = s;
    while (i > 0) 
    {
        if (dp[i][j] != dp[i - 1][j]) 
        {
            a.push_back(d[i]);
            j = j - d[i].kichThuoc;
        }
        i--;
    }
}

void result(vector<Phone> a)
{
    cout << "NhanHieu"<<'\t' << "KichThuoc(mm)" << '\t' << "GiaBan(dong)" << endl;
    for (int i = 0; i < a.size(); i++) 
    {
        if(a[i].kichThuoc != 0)
        cout << a[i].nhanHieu << "\t\t" << a[i].kichThuoc << "\t\t" << a[i].giaBan << endl;
    }
    cout << endl;
}

int main() {
    int s = 700;
    int n = 5;
    vector<Phone> d;
    d.push_back({ "", 0, 0 });
    d.push_back({ "Samsung", 400, 5000000 });
    d.push_back({ "apple", 400, 4500000 });
    d.push_back({ "vivo", 450, 4000000 });
    d.push_back({ "xiaomi", 350, 3500000 });
    d.push_back({ "bphone", 300, 3000000 });
    cout << "Danh sach dien thoai: " << endl;
    result(d);

    int max_value = 0;
    int dp[6][1001] = { 0 };  // Initialize dp array with zeros

    vector<Phone> a;

    QuyHoachDong(d, n, s, dp);
    truy_vet(a, d, dp, n, s, max_value);
    int x = a.size();
    cout << "Kich thuoc tui la: " << s << endl;
    cout << "So Luong dien thoai can lay la: " << x << endl;
    cout << "Danh Sach: " << endl;
    result(a);
    cout << "Max value = " << max_value << endl;
    
    return 0;
}
