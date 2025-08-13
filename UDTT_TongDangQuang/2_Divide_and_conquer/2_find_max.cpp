#include <bits/stdc++.h>
using namespace std;

double Find_max(double * m, int left, int right)
{
    // nếu mảng chỉ có duy nhất 1 phần tử
    if(left == right)
        return m[left];
    
    // chia mảng
    int mid = (left + right)/2;

    // tìm giá trị lớn nhất ở hai nửa
    double max_left = Find_max(m, left, mid);
    double max_right = Find_max(m, mid + 1, right);

    // so sánh và trả về giá trị lớn nhất của 2 mảng
    return (max_left >= max_right) ? max_left : max_right;
}

int main()
{
    int n;
    double * m = new double [n];
    cout << "Nhap so phan tu cua mang: "; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap m[" << i << "] = ";
        cin >> m[i];
    }
    cout << "Phan tu lon nhat trong mang: " << Find_max(m, 0, n - 1) << endl;
}