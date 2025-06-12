#include <bits/stdc++.h>
using namespace std;

// sắp xếp dung tích chai tăng dần
void sort(int * m, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if(m[i] > m[j])
                swap(m[i], m[j]);
        }
    }
}

int chiet_nuoc(int * m, int n, int c)
{
    int chai_duoc_do = 0;
    sort(m, n);
    for (int i = 0; i < n; i++)
    {
        // nếu dung tích các chai nhỏ hơn lượng nước còn lại thì đổ vào chai đó, ngược lại sẽ thoát chương trình
        if(c > m[i])
        {
            c -= m[i];
            chai_duoc_do++;
        }
        else
            break;
    }
    return chai_duoc_do;
}

int main()
{
    int n, c;
    cout << "Nhap n = "; cin >> n;
    int * m = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Nhap m[" << i << "] = "; 
        cin >> m[i];
    }
    cout << "Nhap so luong nuoc: "; cin >> c;

    cout << "So chai duoc do day: " << chiet_nuoc(m, n, c) << endl;
}