#include <bits/stdc++.h>
using namespace std;

# define MAX 7
char S[7] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

int n = 7, k = 6;
int x[100];

void show(int x[])
{
    for (int i = 1; i <= k; i++)
        cout << S[x[i] - 1] << " ";
    cout << endl;
}

void A4(int i)
{
    for (int j = x[i - 1] + 1; j <= n - k + i; j++)
    {
        x[i] = j;
        if(i == k)
            show(x);
        else
            A4(i + 1);
    }
}

int main()
{
    cout << "Ket qua: " << endl;
    A4(1);
}