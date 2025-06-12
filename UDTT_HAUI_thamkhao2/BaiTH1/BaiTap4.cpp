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
    {
        switch (x[i])
        {
        case 1: cout << "Trang ";
            break;
        case 2: cout << "Cong ";
            break;
        case 3: cout << "Trung ";
            break;
        case 4: cout << "Binh ";
            break;
        case 5: cout << "Hoan ";
            break;
        case 6: cout << "Mai ";
            break;
        }
    }
    cout << endl;
}

void list_config(int k, int n)
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
    int k = 4, n = 6;
    cout << "k = " << k << " n = " << n << endl;
    list_config(k, n);
}