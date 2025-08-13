#include <bits/stdc++.h>
using namespace std;

struct Hang
{
    int m;
    int v;
};

int Greedy(Hang * a, int n, double C, Hang * d)
{
    int D = 0;
    double T = 0;
    for (int i = 1; i <= n; i++)
    {
        if (T + a[i].v <= C)
        {
            T += a[i].v;
            d[D] = a[i];
            D++;
        }
        if (T == C)
            break;
    }

    if (T != C)
        D = 0;
    return D;
}

void Sort(Hang * a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (a[i].v > a[j].v)
                swap(a[i], a[j]);
        }
    }
}

void Greedy_apply(Hang * a, int n, double C)
{
    Sort(a, n);
    Hang * d = new Hang[n + 1];
    int D = Greedy(a, n, C, d);
    if (D > 0)
    {
        cout << "Can lay nhieu nhat " << D << " goi hang trong danh sach a de duoc mot gia tri dung bang " << C << endl;
        cout << "----------------------------------------------------------------------------------------------------" << endl;
        
        cout << "Danh sach cac goi hang lay duoc la: " << endl;
        cout << left << setw (15) << "KHOI LUONG" << left << setw(15) << "GIA TRI" << endl;
        for (int i = 0; i < D; i++)
        {
            cout << left << setw (15) << d[i].m << left << setw(15) << d[i].v << endl;
        }
    }
    else
        cout << "Khong the lay duoc goi hang nao trong danh sach a de duoc mot gia tri dung bang " << C << endl;
}

void DB(Hang * a, int n, int M, int ** d)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            d[i][j] = d[i - 1][j];
            if (a[i].m <= j)
            {
                int temp = a[i].v + d[i - 1][j - a[i].m];
                if (d[i][j] < temp)
                    d[i][j] = temp;
            }
        }
    }
}

void DB_apply(Hang * a, int n, int M)
{
    int ** d = new int * [n + 1];
    for (int i = 0; i <= n; i++)
        d[i] = new int[M + 1]();

    DB(a, n, M, d);
    cout << "Gia tri P lay duoc la: P = " << d[n][M] << endl;
    cout << "Gia tri cac goi hang da lay: ";
    int i = n, j = M;
    while (i != 0)
    {
        if (d[i][j] != d[i - 1][j])
        {
            cout << a[i].v << " ";
            j -= a[i].m;
        }
        i--;
    }
    cout << "Bang phuong an: " << endl;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= M; j++)
            cout << d[i][j] << "\t";
        cout << endl;
    }
}

int main()
{
    int n = 8;
    Hang * a = new Hang[n + 1]{{0, 0}, {1, 1}, {7, 7}, {3, 3}, {6, 5}, {4, 6}, {5, 8}, {4, 9}, {2, 8}};
    double C = 9;
    Greedy_apply(a, n, C);

    double M = 18;
    DB_apply(a, n, M);
}