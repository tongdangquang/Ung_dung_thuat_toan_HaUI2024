#include <bits/stdc++.h>
using namespace std;

// B1: Chọn pivot: Lựa chọn một phần tử gốc (pivot) từ dãy số cần sắp xếp.
// B2: Phân hoạch dãy số thành hai phần con: một phần chứa các phần tử nhỏ hơn hoặc bằng pivot và phần còn lại chứa các phần tử lớn hơn pivot.
// B3: Áp dụng đệ quy: Sử dụng thuật toán Quick Sort đệ quy trên cả hai phần con. 
//     Tiếp tục lựa chọn pivot cho từng phần con và phân hoạch lại cho đến khi mỗi phần con chỉ còn một hoặc không có phần tử nào.
//     Kết hợp các phần con: Kết hợp các phần con đã sắp xếp lại với nhau để tạo thành dãy số đã sắp xếp. Dãy số này là kết quả cuối cùng.

// hàm nhập mảng
void nhap (int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap [" << i << "] = ";
		cin >> a[i];
	}
}

// hàm xuất mảng
void xuat(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

// thuật toán quick sort
void quicksort(int * m, int left, int right)
{
    if (left < right)
    {
        // đặt giá trị pivot(trục), có thể lấy ngẫy nhiên nhưng lấy ở giữa cho dễ hiểu
    int v_mid = m[(left + right)/2];
    // int v_mid = m[left]; có thể thay đổi pivot như thế này

    // lấy 2 biến i và j thay thế left và right để left và right không bị thay đổi giá trị
    int i = left, j = right;

    // tiến hành chia mảng thành 2 mảng con
    while(i <= j)
    {
        while(m[i] > v_mid)
            i++;
        while(m[j] < v_mid)
            j--;
        // đổi chỗ để sắp xếp
        if (i <= j)
        {
            swap(m[i], m[j]);
            i++;
            j--;
        }
    }
     // gọi đệ quy để tiếp tục sắp xếp (sắp xếp từ trái qua phải để tránh tràn ngăn xếp)
    quicksort(m, left, j);
    quicksort(m, i, right);
    }
}

int main ()
{
    int n; 
    cout << "Nhap n = ";
    cin >> n;
    int * m = new int [n];

    cout << "Nhap mang: " << endl;
    nhap(m, n);

    quicksort(m, 0, n - 1);
    cout << "Mang da sap xep: ";
    xuat(m, n);

    delete [] m;
}