#include <bits/stdc++.h>
using namespace std;

void knapsackGreedy(double * v, double * w, int n, double capacity, double & totalv, double & totalw, bool * r)
{
    double *c = new double[n]; // khởi tạo mảng chứa tỉ lệ giá trị/trọng lượng
    int * pos = new int [n]; // khởi tạo mảng chứa vị trí đồ vật

    for (int i = 0; i < n; i++)
    {
        pos[i] = i;
        r[i] = false;
    }

    for (int i = 0; i < n; i++)
        c[i] = v[i] / w[i];

    // sắp xếp nổi bọt để sắp xếp tỉ lệ giá trị/trọng lượng (mảng c) và vị trí tương ứng giảm dần
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if(c[i] < c[j])
            {
                swap(c[i], c[j]);
                swap(pos[i], pos[j]);
            }
        }
    }

    totalv = 0.0;
    totalw = 0;

    // thuật toán tham lam (greedy)
    for (int i = 0; i < n; i++)
    {
        if(totalw + w[pos[i]] <= capacity)
        {
            totalv += v[pos[i]];
            totalw += w[pos[i]];
            r[pos[i]] = true;
        }
        else
            break;
    }
}

int main()
{
    int n;
    cout << "Nhap n = "; cin >> n;
    double * v = new double [n]; // mảng chứa giá trị đồ vật
    double * w = new double [n]; // mảng chứa trọng lượng đồ vật
    bool * r = new bool[n]; // mảng đánh dấu những đồ vật nào được đưa vào balo
    double capacity = 15; // tải trọng tối đa của túi
    double totalv, totalw;

    cout << "Nhap gia tri va trong luong: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap v[" << i << "] = "; cin >> v[i];
        cout << "Nhap w[" << i << "] = "; cin >> w[i];
    }

    knapsackGreedy(v, w, n, capacity, totalv, totalw, r);

    cout << "Tong trong luong = " << totalw << endl;
    cout << "Ton gia tri = " << totalv << endl;
    cout << "Cac do vat lay duoc: ";
    for (int i = 0; i < n; i++)
        cout << r[i] << " ";
    cout << endl;
}