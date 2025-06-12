#include <bits/stdc++.h>
using namespace std;

void knapsack(int ** F, int * w, int * v, int n, int m)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
            F[i][j] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            F[i][j] = F[i - 1][j];
            if(w[i] <= j)
            {
                int temp = v[i] + F[i - 1][j - w[i]];
                if(F[i][j] < temp)
                    F[i][j] = temp;
            }
        }
    }
}  
void knapsack_apply(int * w, int * v, int n, int m)
{
    int ** F = new int *[n + 1];
    for (int i = 0; i <= n; i++)
        F[i] = new int [m + 1];

    knapsack(F, w, v, n, m);

    cout << "Gia tri toi da co the lay duoc la: " << F[n][m] << endl;
    cout << "----------------------------------" << endl;

    cout << "Cac do vat lay duoc co gia tri lan luot la: ";
    int i = n, j = m;
    while(i != 0)
    {
        if (F[i][j] != F[i - 1][j])
        {
            cout << v[i] << " ";
            j -= w[i];
        }
        i--;
    }
    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Bang ket qua: " << endl;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
            cout << F[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int n = 5; // số lượng đồ vật
    int m = 10; // sức chứa tối đa của túi
    int * w = new int [n + 1] {0, 2, 1, 3, 5, 4}; // mảng chứa trọng lượng của các đồ vật
    int * v = new int [n + 1] {0, 3, 5, 2, 4, 1}; // mảng chứa giá trị của các đồ vật 
    knapsack_apply(w, v, n, m);
}