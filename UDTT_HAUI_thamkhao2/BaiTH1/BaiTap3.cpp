#include <iostream>

using namespace std;

void next_config(int x[], int k, int i)
{
    x[i] += 1;
    i++;
    while (i <= k) 
    {
        x[i] = x[i - 1] + 1;
        i++;
    }
}

void view_config(int x[], int k)
{
    for (int i = 1; i <= k; i++)
        cout << x[i] << " ";
    cout << endl;
}

void list_configs(int k, int n)
{
    int i;
    int x[k + 1] = {0};
    for (i = 1; i <= k; i++)
        x[i] = i;
    do
    {
        view_config(x, k);
        i = k;
        while (i > 0 && x[i] == n - k + i)
            i--;
        if (i > 0)
            next_config(x, k, i);
    } while (i > 0);
}

int main()
{
    int n = 9, k = 4;
    cout << "k = " << k << " n = " << n << endl;
    list_configs(k, n);
}