#include <bits/stdc++.h>
using namespace std;

#define MAX 4
char G[MAX] = {'A', 'B', 'C', 'D'};
string N[MAX] = {"Tung", "Cuc", "Truc", "Mai"};

int n = MAX;
int x[MAX + 1];
int c = 0;

bool dd[MAX + 1];
void show(int x[], int n)
{
    for (int i = 1; i <= n; i++)
        cout << G[x[i] - 1] << "-" << N[x[i] - 1] << "\t";
    cout << endl; 
}

void A1(int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (dd[i] == false)
        {
            x[k] = i;
            if (k == n)
            {
                c++;
                show(x, n);
            }
            else
            {
                dd[i] = true;
                A1(k + 1);
                dd[i] = false;
            }
        }
    }
}

int main()
{
    for (int i = 0; i < MAX + 1; i++)
    {
        x[i] = 0;
        dd[i] = false;
    }
    cout << "Cac cach sap xep: " << endl;
    A1(1);
    cout << "So cach sap xep: " << c << endl;
}