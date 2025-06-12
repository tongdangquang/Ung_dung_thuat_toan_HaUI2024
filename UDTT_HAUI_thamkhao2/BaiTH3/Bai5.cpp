#include <iostream>

using namespace std;

#define MAX 20
double ds[MAX] = {60, 57, 95, 10, 55, -90, 9, 24, 13, 57, 37, -80, 58, 50, 70, -55, 99, 66, 54, -68};

void merge(double ds[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    long L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = ds[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = ds[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            ds[k] = L[i];
            i++;
        }
        else
        {
            ds[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        if (L[i] > 0)
        {
            ds[k] = L[i];
            i++;
            k++;
        } else {
        }
    }

    while (j < n2)
    {
        if (R[j] > 0)
        {
            ds[k] = R[j];
            j++;
            k++;
        } else {
            n2--;
        }
    }
}

void mergeSort(double ds[], int l, int r)
{
    if (r > l)
    {
        int m = l + (r - l) / 2;
        mergeSort(ds, l, m);
        mergeSort(ds, m + 1, r);
        merge(ds, l, m, r);
    }
}

void display(double ds[]) {
    for (int i = 0; i < MAX; i++)
    {
        cout << ds[i] << " ";
    }
    
}

int main()
{
    mergeSort(ds, 0, MAX - 1);
    display(ds);
}