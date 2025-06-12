// BÀI TOÁN: Phân loại ký tự 
// Cho một xâu ký tự s gồm các chữ cái, chữ số và dấu cách. Hãy cho biết số loại ký tự có 
// trong xâu s và số lần xuất hiện của mỗi loại ký tự trong xâu s.

// PHƯƠNG PHÁP VÉT CẠN: 
// - Sử dụng hai mảng đầu ra là t[] kiểu ký tự và c[] kiểu nguyên để lưu trữ loại ký tự 
// xuất hiện trong xâu s và số lần xuất hiện tương ứng của nó. 
// - Duyệt xâu s, mỗi ký tự s[i] kiểm tra xem s[i] có trong mảng t hay chưa:
// + Nếu s[i] đã có trong t[], giả sử tại vị trí t[m], tăng c[m] lên 1 đơn vị. 
// + Ngược lại, thêm s[i] vào cuối mảng t[]: t[m] = s[i], c[m] = 1; tăng m lên 1 đơn vị.


#include <bits/stdc++.h>
using namespace std;

// hàm kiểm tra ký tự có trong mảng t hay không
int index_of (char * t, char k, int m)
{
    for (int i = 0; i < m; i++)
    {
        if(t[i] == k)
            return i;
    }
    return -1;
}

// hàm phân loại ký tự, kết quả trả về trong t[] và c[]
void solve (char * s, char * t, int * c, int & m)
{
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        int index = index_of(t, s[i], m);
        if(index == - 1)
        {
            t[m] = s[i];
            c[m] = 1;
            m++;
        }
        else
            c[index]++;
    }
}

int main()
{
    char s[] = "abccabdad1231";
    char t[] = "";
    int * c = new int[256];
    int m = 0;

    solve(s, t, c, m);
    cout << "So loai ky tu co trong xau s la: " << m << endl;
    cout << "----------------------------------------" << endl;

    cout << "Danh sach cac ky tu: " << endl;
    cout << left << setw(10) <<  "KY TU" << left << setw(20) << "SO LAN XUAT HIEN" << endl;
    for (int i = 0; i < m; i++)
    {
        cout << left << setw(10) << t[i];
        cout << left << setw(20) << c[i] << endl;
    }
}