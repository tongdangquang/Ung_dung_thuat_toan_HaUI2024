#include <bits/stdc++.h>
using namespace std;

int T(int ** dp, string a, string b, int n, int m)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

// Hàm để truy ngược lại bảng dp và lấy xâu con chung
string truyvet(int ** dp, string a, string b, int n, int m)
{
    string result = "";
    int i = n, j = m;

    while (i > 0 && j > 0)
    {
        // Nếu ký tự tại a[i-1] và b[j-1] trùng nhau, thêm vào kết quả
        if (a[i - 1] == b[j - 1])
        {
            result += a[i - 1];
            i--;
            j--;
        }
        // Nếu giá trị của dp[i-1][j] lớn hơn hoặc bằng dp[i][j-1], đi lên trên
        else if (dp[i - 1][j] >= dp[i][j - 1])
            i--;
        // Ngược lại, đi sang trái
        else
            j--;
    }
    string result2 = "";
    for (int i = result.length() - 1; i >= 0; i--)
        result2 += result[i];
    return result2;
}

int main()
{
    string a = "02345777777", b = "1542345888888";
    int n = a.length(), m = b.length();
    int ** dp = new int * [n + 1];
    for (int i = 0; i <= n; i++)
        dp[i] = new int [m + 1]();

    int c = T(dp, a, b, n, m);
    string result = truyvet(dp, a, b, n, m);

    cout << "Do dai xau con: " << c << endl;
    cout << "Xau con chung dai nhat: " << result << endl;
}
