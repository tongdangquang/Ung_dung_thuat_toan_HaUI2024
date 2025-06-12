// Sàng ký tự là một mảng một chiều sang[], kiểu nguyên, có kích thước là 256 
// tương ứng với 256 ký tự trong bảng mã ASCII, với ý nghĩa chỉ số của phần tử 
// mảng là mã ASCII của ký tự và giá trị phần tử mảng là số lần xuất hiện của ký 
// tự trong xâu s. Ví dụ sang[97] = 3 với ý nghĩa 97 là ký tự ‘a’ và 3 là số lần xuất 
// hiện của ký tự ‘a’ trong xâu s.


#include <bits/stdc++.h>
using namespace std;

void sang_ky_tu(char * s, int * sang)
{
    int n = strlen(s);
    for (int i = 0; i < n; i++)
        sang[s[i]]++;
}

int main()
{
    char s[] = "abccabdad1231";
    int * sang = new int[256]();
    sang_ky_tu(s, sang);
    int c = 0;
    cout << "Danh sach cac ky tu: " << endl;
    cout << left << setw(10) <<  "KY TU" << left << setw(20) << "SO LAN XUAT HIEN" << endl;
    for (int i = 0; i < 256; i++)
    {
        if(sang[i] != 0)
        {
            c++;
            cout << left << setw(10) << (char) i << left << setw(20) << sang[i] << endl;
        }
    }
    cout << "----------------------------------------" << endl;

    cout << "So loai ky tu co trong xau s la: " << c << endl;
}