#include <bits/stdc++.h>
using namespace std;

int Greedy(double * a, int n, double C, double * x, double & M)
{
    int D = 0;
    M = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (M > C)
            break;
        else
        {
            x[D] = a[i];
            D++;
            M += a[i];
        }
    }
    return D;
}

void Greedy_apply(double * a, int n, double C)
{
    double M = 0;
    double * x = new double[n];
    
    int D = Greedy(a, n, C, x, M);
    if (D > 0)
    {
        cout << "So luong phan tu it nhat co the lay trong day a de duoc gia tri M lon hon " << C << " la: " << D << endl;
        cout << "------------------------------------------------------------------------------------" << endl;
        
        cout << "Gia tri cua M la: M = " << M << endl;
        cout << "------------------------------------------------------------------------------------" << endl;

        cout << "Danh sach cac phan tu lay duoc la: ";
        for (int i = 0; i < D; i++)
            cout << x[i] << " ";
        cout << endl;
    }
    else
        cout << "Khong the lay duoc phan tu nao" << endl;
}

int char_in_string(char c, string t)
{
    int n = t.length();
    for (int i = 0; i < n; i++)
    {
        if (c == t[i])
            return i;
    }
    return -1;
}

int * BMH(string P, string Q, int & c)
{
    int v = P.length();
    int n = Q.length();
    int i = v - 1;
    c = 0;
    int * id = new int[n];
    
    if (v > n)
        return id;
    while (i < n)
    {
        int k = v - 1;
        int j = i;
        while (k >= 0 && Q[j] == P[k])
        {
            j--;
            k--;
        }
        if (k < 0)
        {
            id[c] = j + 1;
            c++;
            i += v;
        }
        else
        {
            int x = char_in_string(Q[i], P);
            if (x < 0)
                i += v;
            else
                i += v - x - 1;
        }
    }
    return id;
}

void BMH_apply(string P, string Q)
{
    int c = 0;
    int * id = BMH(P, Q, c);

    if (c > 0)
    {
        cout << "P xuat hien trong Q tai cac vi tri: ";
        for (int i = 0; i < c; i++)
            cout << id[i] << " ";
        cout << endl;
    }
    else
        cout << "P khong xuat hien trong Q" << endl;
}

int main()
{
    int n = 8;
    double * a = new double[n] {1, 2, 3, 4, 5, 6, 7, 8};
    double C = 20;
    cout << "CAU 1: " << endl;
    Greedy_apply(a, n, C);
    cout << "------------------------------------------------------------------------------------" << endl;

    cout << "\nCAU 2: " << endl;
    string P = "chill guy"; // xâu con
    string Q = "chill guy I am a chill guy, chill guy and chill guy"; // xâu cha
    BMH_apply(P, Q);
}