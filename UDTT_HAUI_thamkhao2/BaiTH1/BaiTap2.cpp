#include <iostream>

using namespace std;

void next_config(char x[], int n, int i)
{
    x[i] = 'b';
    i++;
    while (i <= n)
    {
        x[i] = 'a';
        i++;
    }
}

void view_config(char x[], int n)
{
    for (int i = 1; i <= n; i++)
        cout << x[i] << " ";
    cout << endl;
}

void list_configs(int n)
{
    int i;
    char x[n + 1];
    for (i = 1; i <= n; i++)
        x[i] = 'a';
    do
    {
        view_config(x, n);
        i = n;
        while (i > 0 && x[i] == 'b')
            i--;
        if (i > 0)
            next_config(x, n, i);
    } while (i > 0);
}

int main()
{
    int n = 6;
    cout << "n = " << n << endl;
    list_configs(n);
}