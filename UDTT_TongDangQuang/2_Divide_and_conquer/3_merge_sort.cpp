#include <bits/stdc++.h>
using namespace std;

void entry(int * m, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap m[" << i << "] = ";
        cin >> m[i];
    }
}

void show(int * m, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << m[i] << " ";
    }
    cout << endl;
}

void merge(int * m, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int * a1 = new int [n1];
    int * a2 = new int [n2];

    for (int i = 0; i < n1; i++)
        a1[i] = m[left + i];
    for (int i = 0; i < n2; i++)
        a2[i] = m[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2)
    {
        if(a1[i] < a2[j])
        {
            m[k] = a1[i];
            i++;
        }
        else
        {
            m[k] = a2[j];
            j++;
        }
        k++;
    }
    while(i < n1)
    {
        m[k] = a1[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        m[k] = a2[j];
        j++;
        k++;
    }
}

void merge_sort(int * m, int left, int right)
{
    if(left < right)
    {
        int mid = (left + right)/2;
        merge_sort(m, left, mid);
        merge_sort(m, mid + 1, right);
        merge(m, left, mid, right);
    }
}

int main()
{
    int n;
    int * m = new int[n];
    cout << "Nhap n = "; cin >> n;
    cout << "Nhap mang: " << endl;
    entry(m, n);
    cout << "\nMang goc: ";
    show(m, n);
    cout << "\nMang sap xep: ";
    merge_sort(m, 0, n - 1);
    show(m, n);
}