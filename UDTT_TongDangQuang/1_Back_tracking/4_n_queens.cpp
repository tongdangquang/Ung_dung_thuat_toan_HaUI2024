#include <bits/stdc++.h>
using namespace std;

int n, x[100], cot[100], cheo_xuong[100], cheo_len[100];
int a[100][100];

void xuat()
{
    memset(a, 0, sizeof(a)); // dùng menset để gán tất cả các phần tử của a[] bằng 0
    for (int i = 1; i <= n; i++)
        a[i][x[i]] = 1;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Try(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if(cot[j] == 1 && cheo_xuong[i - j + n] == 1 && cheo_len[i + j - 1] == 1)
        {
            x[i] = j;
            cot[j] = cheo_xuong[i - j + n] = cheo_len[i + j - 1] = 0;
            if(i == n)
                xuat();
            else
                Try(i + 1);

            // backtrack
            cot[j] = cheo_xuong[i - j + n] = cheo_len[i + j - 1] = 1;
        }
    }
}

int main()
{
    cout << "Nhap n = "; cin >> n;
    for (int i = 1; i <= 100; i++)
    {
        cot[i] = cheo_xuong[i] = cheo_len[i] = 1;
    }
    Try(1);
}
