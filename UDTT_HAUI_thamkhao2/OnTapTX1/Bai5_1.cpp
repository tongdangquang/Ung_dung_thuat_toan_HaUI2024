#include <iostream>

#define MAX 6

using namespace std;

struct CongViec
{
    string maCv;
    string tgBd;
    int tgTh;
};

CongViec cv[] = {
    {"CV01", "08:00", 60},
    {"CV02", "09:00", 30},
    {"CV03", "09:30", 45},
    {"CV04", "10:15", 30},
    {"CV05", "10:45", 15},
    {"CV06", "11:00", 90},
    {"CV07", "12:30", 60},
    {"CV08", "13:30", 45},
    {"CV09", "14:15", 30},
    {"CV10", "14:45", 15},
};

void inNguoc(int i) {
    if (i == 0) return;
    cout << cv[i -  1].maCv << " " << cv[i - 1].tgBd << " " << cv[i - 1].tgTh << endl;
    inNguoc(i - 1);
}

void view_config(int x[], int k) {
    for (int i = 1; i <= k; i++) 
        cout << cv[x[i] - 1].maCv << " ";
    cout << endl; 
}

void next_config(int x[], int k, int i) {
    x[i] += 1;
    i++;
    while (i <= k) {
        x[i] = x[i - 1] + 1;
        i++;
    }
}

void list_congfigs(int k, int n) {
    int count = 1;
    int i, x[k + 1] = {0};
    for (i = 1; i <= k; i++) x[i] = i;
    do
    {
        cout << count << ". ";
        view_config(x, k);
        i = k;
        count++;
        while (i > 0 && x[i] == n - k + i) i--;
        if (i > 0) next_config(x, k, i);
    } while (i > 0);  
}

int main()
{
    inNguoc(MAX);
    list_congfigs(4, MAX);
}