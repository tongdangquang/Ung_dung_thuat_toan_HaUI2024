#include <bits/stdc++.h>
using namespace std;

struct Time
{
    double start, finish;
};

// sắp xếp thời gian kết thúc của các công việc tăng dần
void sort(Time * m, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if(m[i].finish > m[j].finish)
                swap(m[i], m[j]);
        }
    }
}

int schedule(Time * m, int n)
{
    int dem = 0;
    double last_finish = 0;
    sort(m, n);

    for (int i = 0; i < n; i++)
    {
        // nếu thời gian bắt đầu của công việc (i) lớn hơn thời gian kết thúc của công việc (i - 1) thì thỏa mãn điều kiện và dem++
        if (m[i].start >= last_finish)
        {
            last_finish = m[i].finish; // thay đổi thời gian kết thúc của công việc gần nhất
            dem++;
        }
    }
    return dem;
}
int main()
{
    int n;
    cout << "Nhap so luong cong viec: "; cin >> n;
    Time * m = new Time[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thoi gian bat dau va ket thuc cua job[" << i << "] = ";
        cin >> m[i].start >> m[i].finish;
    }
    cout << "So cong viec lam duoc nhieu nhat: " << schedule(m, n) << endl;
}
