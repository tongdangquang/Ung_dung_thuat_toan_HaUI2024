#include <bits/stdc++.h>
using namespace std;

struct Hoithao
{
    string chude;
    double batdau;
    double ketthuc;
};

// sắp xếp thời gian kết thúc của các cuộc hội thảo tăng dần
void Sort_time(Hoithao * d, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (d[i].ketthuc > d[j].ketthuc)
                swap(d[i], d[j]);
        }
    }
}

void T1(Hoithao * d, int n, Hoithao * s, int & k)
{
    Sort_time(d, n);
    double last_finish = 0;
    for (int i = 0; i < n; i++)
    {
        if (d[i].batdau >= last_finish)
        {
            last_finish = d[i].ketthuc;
            s[k] = d[i];
            k++;
        }
    }
}

int main()
{
    int n = 6;
    Hoithao * d = new Hoithao[n]{
        {"Tim kiem viec lam", 7, 10},
        {"Phat trien ky nang mem", 8, 10},
        {"Lam viec cung AI", 8, 9},
        {"Kiem thu phan mem", 9, 14},
        {"An toan va bao mat", 15, 17},
        {"Bao ve moi truong", 11, 15}
    };
    int k = 0;
    Hoithao * s = new Hoithao[n];

    T1(d, n, s, k);
    cout << "--------------------------------------------------------" << endl;
    cout << "So cuoc hoi thao nhieu nhat mot nguoi co the tham gia la: " << k << endl;

    cout << "--------------------------------------------------------" << endl;
    cout << "DANH SACH CAC CUOC HOI THAO CO THE THAM GIA: " << endl;
    cout << left << setw(50) << "CHU DE HOI THAO" << left << setw(15) << "BAT DAU" << left << setw(15) << "KET THUC" << endl; 
    for (int i = 0; i < k; i++)
        cout << left << setw(50) << s[i].chude << left << setw(15) << s[i].batdau << left << setw(15) << s[i].ketthuc << endl; 
}