#include <bits/stdc++.h>
using namespace std;

void subsetSum(int * m, int n, int s)
{
    // tạo mảng lưu trữ dp
    bool ** dp = new bool * [n + 1];
    for (int i = 0; i <= n; i++)
        dp[i] = new bool [s + 1];

    // khởi tạo mảng lưu trữ dp
    for (int i = 0; i <= n; i++)
        dp[i][0] = true; // nếu tổng là 0 thì luôn có thể đạt được với mọi tập con rỗng
    
    for (int j = 0; j <= s; j++)
        dp[0][j] = false; // nếu không có phần tử nào trong tập thì không thể nào có tổng > 0

    // điền bảng dp
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            if (m[i - 1] > j)
                dp[i][j] = dp[i - 1][j]; // không chọn phần tử m[i - 1]
            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - m[i - 1]];
        }
    }

    // Truy vết ngược để tìm tập con đã chọn
    if (dp[n][s])
    {
        cout << "Ton tai tap con co tong bang " << s << ": ";
        int i = n, j = s;
        while(i > 0 && j > 0)
        {
            if(dp[i][j] != dp[i - 1][j])
            {
                cout << m[i - 1] << " ";
                j -= m[i - 1];
            }
            i--;
        }
        cout << endl;
    }
    else
        cout << "Khong ton tai tap con nao co tong bang " << s << endl;
}


int main()
{
    int n;
    cout << "Nhap n = "; cin >> n;
    int * m = new int [n];
    cout << "Nhap day so: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap m[" << i << "] = ";
        cin >> m[i];
    }
    int s;
    cout << "Nhap tong can tim: "; cin >> s;
    
    subsetSum(m, n, s);
}