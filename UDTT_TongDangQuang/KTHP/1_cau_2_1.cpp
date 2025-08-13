#include <bits/stdc++.h>
using namespace std;

int Greedy(double * a, int n, double C, double & M, double * x)
{
    int D = 0;
    M = 0;
    for (int i = 0; i < n; i++)
    {
        if (M + a[i] <= C)
        {
            M += a[i];
            x[D] = a[i];
            D++;
        }
    }
    return D;
}

void Greedy_apply(double * a, int n, double C)
{
    double * x = new double[n];
    double M = 0;
    int D = Greedy(a, n, C, M, x);
    
    if (D > 0)
    {
        cout << "So luong phan tu nhieu nhat co the lay trong day a de duoc mot gia tri M khong vuot qua " << C << " la: " << D << endl;
        cout << "--------------------------------------------------------------------------------------------" << endl;
        cout << "Gia tri cua M la: M = " << M << endl;
        cout << "--------------------------------------------------------------------------------------------" << endl;
        cout << "Danh sach cac phan tu lay duoc la: ";
        for (int i = 0; i < D; i++)
            cout << x[i] << " ";
        cout << endl;
    }
    else
        cout << "Khong the lay duoc phan tu nao trong day a de duoc mot gia tri M vuot qua " << C << endl;
}


int char_in_string(char c, string s)
{
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (c == s[i])
            return i;
    }
    return -1;
}

bool BMH(string Q, string P)
{
    int Q_len = Q.length(); // xâu con
    int P_len = P.length(); // xâu cha
    int i = Q_len - 1;

    if (Q_len > P_len)
        return false;
    
    while(i < P_len)
    {
        int k = Q_len - 1;
        while (k >= 0 && P[i] == Q[k])
        {
            i--;
            k--;
        }
        if (k < 0)
            return true;
        else
        {
            int x = char_in_string(P[i], Q);
            if (x < 0)
                i += Q_len;
            else
                i += Q_len - x - 1;
        }
    }
    return false;
}

void BMH_apply(string Q, string P)
{
    if (BMH(Q, P))
        cout << "Q la chuoi con cua P" << endl;
    else
        cout << "Q khong la chuoi con cua P" << endl;
}

int main()
{
    int n = 8;
    double * a = new double[n] {1, 2, 3, 4, 5, 6, 7, 8};
    double C = 20;
    string P = "I am a chill guy";
    string Q = "guy";

    Greedy_apply(a, n, C);
    cout << "--------------------------------------------------------------------------------------------" << endl;
    BMH_apply(Q, P);
}
