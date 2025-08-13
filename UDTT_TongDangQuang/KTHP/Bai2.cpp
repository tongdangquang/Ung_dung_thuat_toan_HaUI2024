#include <bits/stdc++.h>
using namespace std;

struct Lophoc
{
    string malop;
    int so_hs;
    int so_nu;
};

// Cần lấy ít nhất bao nhiêu lớp trong danh sách d để được số học sinh lớn hơn n
int Greedy(Lophoc * d, int m, int n, Lophoc * x)
{
    int c = 0;
    int total = 0;
    for (int i = 0; i < m; i++)
    {
        total += d[i].so_hs;
        x[c] = d[i];
        c++;
        if (total > n)
            break;
    }
    return c;
}

void Apply_Greedy(Lophoc * d, int m, int n)
{
    Lophoc * x = new Lophoc [m];
    int c = Greedy(d, m, n, x);
    if (c > 0)
    {
        cout << "Can lay it nhat " << c << " lop hoc trong danh sach de duoc so HS lon hon " << n << endl;
        cout << "Danh sach cac lop lay duoc la: " << endl;
        cout << left << setw (15) << "MA LOP" << left << setw (15) << "SO HOC SINH" << left << setw (15) << "SO NU" << endl;  
        for (int i = 0; i < c; i++)
            cout << left << setw (15) << x[i].malop << left << setw (15) << x[i].so_hs << left << setw (15) << x[i].so_nu << endl;  
    }
    else
        cout << "Khong the lay duoc lop hoc nao tu danh sach" << endl;
}


int main()
{
    int m = 8;
    Lophoc * d = new Lophoc [m]{
        {"LP01", 55, 25},
        {"IT02", 52, 10},
        {"PL03", 51, 20},
        {"FL04", 48, 28},
        {"CC05", 45, 24},
        {"IT06", 43, 32},
        {"IT07", 40, 30},
        {"HH08", 35, 23},
    };

    // int n = 200;
    // Apply_Greedy(d, m, n);

    int k = 200;
}