#include <bits/stdc++.h>
using namespace std;

struct Job
{
    string macv;
    double start;
    double time;
};

void show(Job c)
{
    cout << left << setw(20) << c.macv << left << setw(20) << c.start << left << setw(20) << c.time << endl; 
}

void A1(Job * c, int n)
{
    if(n > 0)
    {
        show(c[n - 1]);
        A1(c, n - 1);
    }
    else
        return;
}

int A2(Job * c, int left, int right)
{
    if(left > right)
        return 0;
    if(left == right)
        return (c[left].time <= 0.5) ? 1 : 0;
    
    int mid = (left + right)/2;
    int count_left = A2(c, left, mid);
    int count_right = A2(c, mid + 1, right);
    return count_left + count_right;
}

void show2(Job * c, string * L, int * x, int n)
{
    for (int i = 1; i <= n; i++)
        cout << c[x[i] - 1].macv << "-" << L[x[i] - 1] << endl;
    cout << endl;
}

void A3(Job * c, string * L, int * x, bool * dd, int n, int k, int & cnt)
{
    for (int i = 1; i <= n; i++)
    {
        if(dd[i] == false)
        {
            x[k] = i;
            if(k == n)
            {
                cnt++;
                show2(c, L, x, n);
            }
            else
            {
                dd[i] = true;
                A3(c, L, x, dd, n, k + 1, cnt);
                dd[i] = false;
            }
        }
    }
}

// áp dụng quick sort (sắp xếp phân đoạn) để sắp xếp danh sách công việc theo thứ tự tăng dần
void A4(Job * c, int left, int right)
{
    Job v_mid = c[(left + right)/2];
    int i = left, j = right;

    while(i <= j)
    {
        while(c[i].start > v_mid.start)
            i++;
        while(c[j].start < v_mid.start)
            j--;
        if(i <= j)
        {
            swap(c[i], c[j]);
            i++;
            j--;
        }
    }
    if(j > left)
        A4(c, left, j);
    if(i < right)
        A4(c, i, right);
}


int main()
{
    int n = 6;
    Job * c = new Job [n] {
        {"CV001", 2, 0.5},
        {"CV002", 4, 1},
        {"CV003", 6, 3.5},
        {"CV004", 9, 2.5},
        {"CV005", 10, 0.3},
        {"CV006", 12, 0.2}
    };
    string * L = new string[n]{"Quang", "Hung", "Khanh", "Yen", "Hai", "Ha"};

    cout << "Danh sach cong viec in theo thu tu nguoc lai: " << endl;
    cout << left << setw(20) << "MA CV" << left << setw(20) << "BAT DAU" << left << setw(20) << "THOI GIAN" << endl; 
    A1(c, n);
    cout << "----------------------------------------------" << endl;
    
    int result = A2(c, 0, n - 1);
    cout << "So cong viec co thoi gian thuc hien khong qua 0.5 gio la: " << result << endl;
    if (result > 0)
    {
        cout << left << setw(20) << "MA CV" << left << setw(20) << "BAT DAU" << left << setw(20) << "THOI GIAN" << endl; 
        for (int i = 0; i < n; i++)
        {
            if(c[i].time <= 0.5)
                show(c[i]);
        }
    }
    cout << "----------------------------------------------" << endl;

    int * x = new int[n + 1];
    bool * dd = new bool[n + 1];
    for (int i = 0; i <= n; i++)
    {
        x[i] = 0;
        dd[i] = false;
    }
    int cnt = 0;
    cout << "Danh sach phuong an: " << endl;
    A3(c, L, x, dd, n, 1, cnt);
    cout << "Tong so phuong an: " << cnt << endl;
    cout << "----------------------------------------------" << endl;

    A4(c, 0, n - 1);
    cout << "Danh sach cong viec sap xep theo thoi gian bat dau giam dan: " << endl;
    cout << left << setw(20) << "MA CV" << left << setw(20) << "BAT DAU" << left << setw(20) << "THOI GIAN" << endl; 
    for (int i = 0; i < n; i++)
        show(c[i]);

}