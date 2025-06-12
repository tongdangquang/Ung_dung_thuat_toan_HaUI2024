#include <bits/stdc++.h>
using namespace std;

int LIS(int * m, int n)
{
    // nếu mảng gốc không chứa phần tử
    if(n == 0)
        return 0;

    // khởi tạo mảng mark (đánh dấu) có số lượng phần tử bằng với mảng gốc và mỗi phần tử có giá trị bằng 1
    int * mark = new int [n];
    for (int i = 0; i < n; i++)
        mark[i] = 1;
    
    // độ dài lớn nhất của dãy con tăng
    int lis_length = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(m[i] > m[j])
            {
                mark[i] = max(mark[i], mark[j] + 1);
            }
        }
        lis_length = max(lis_length, mark[i]);
    }
    return lis_length;
}

int main()
{
    int n;
    int * m = new int[n];
    cout << "Nhap n = "; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap m[" << i << "] = ";
        cin >> m[i];
    }
    cout << "\nMang goc: ";
    for (int i = 0; i < n; i++)
    {
        cout << m[i] << " ";
    }
    cout << endl;
    cout << "\nDay con tang dai nhat co chieu dai la: " << LIS(m, n) << endl;
}