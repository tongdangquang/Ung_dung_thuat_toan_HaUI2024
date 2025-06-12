#include <iostream>

#define MAX 6

using namespace std;

string S[MAX] = {"TRANG", "CONG", "TRUNG", "BINH", "HOAN", "MAI"};

void view_config(int x[], int k) {
    for (int i = 1; i <= k; i++)
        cout << S[x[i] - 1] << " ";
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

void list_configs(int k, int n) {
    int i, x[k + 1] = {0};
    for (i = 1; i <= k; i++)
        x[i] = i;
    do {
        view_config(x, k);
        i = k;
        while (i > 0 && x[i] == n - k + i) i--;
        if (i > 0) next_config(x, k, i);
    } while (i > 0);
}

int x[MAX], k = 4, n = MAX;

void show(int x[]) {
    for (int i = 1; i <= k; i++)
        cout << S[x[i] - 1] << " ";
    cout << endl;
}

void Try(int i) {
    for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
        x[i] = j;
        if (i == k) {
            show(x);
        } else {
            Try(i + 1);
        }
    }
}

int main() {
    // list_configs(4, MAX);
    Try(1);
}