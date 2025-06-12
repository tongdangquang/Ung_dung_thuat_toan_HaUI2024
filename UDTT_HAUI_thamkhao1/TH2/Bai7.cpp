#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> BanCo;
vector<vector<bool>> mark;
int dx[] = { -2, -1, 1 , 2, 2, 1, -1, -2 };
int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

bool isvalid(int x, int y) {
    return (x >= 0 && y >= 0 && y < n && x < n && mark[x][y] == 0);
}

void show(vector<vector<int>> arr2d) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr2d[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "------------" << endl;
}

void Try(int i, int j, int k) {
    BanCo[i][j] = k;
    if (k == n * n - 1) {
        show(BanCo);
        exit(0);
    }
    mark[i][j] = 1;
    for (int idx = 0; idx < 8; idx++) {
        int next_i = i + dx[idx];
        int next_j = j + dy[idx];
        if (isvalid(next_i, next_j)) {
            Try(next_i, next_j, k + 1);
        }
    }
    mark[i][j] = 0;
}

int main() {
    n = 5;
    BanCo.resize(n, vector<int>(n, 0));
    mark.resize(n, vector<bool>(n, 0));
    Try(0, 0, 1);
    return 0;
}
