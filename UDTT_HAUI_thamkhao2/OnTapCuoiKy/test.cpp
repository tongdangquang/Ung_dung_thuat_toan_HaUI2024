#include <iostream>

using namespace std;

struct Package {
    int weight;
    int value;
};

// Thuật toán tham lam để tính D
pair<int, int> GreedyMaxValue(const Package packages[], int n, int C) {
    int totalWeight = 0;
    int totalValue = 0;

    for (int i = 0; i < n; ++i) {
        if (totalWeight + packages[i].weight <= C) {
            totalWeight += packages[i].weight;
            totalValue += packages[i].value;
        }
    }

    return {totalValue, totalWeight};
}

// Thuật toán qui hoạch động để tính P
int DynamicMaxValue(const Package packages[], int n, int M) {
    int dp[256] = {0};

    for (int i = 0; i < n; ++i) {
        for (int j = M; j >= packages[i].weight; --j) {
            dp[j] = max(dp[j], dp[j - packages[i].weight] + packages[i].value);
        }
    }

    return dp[M];
}

int main() {
    int n = 8;

    Package packages[256];
    cout << "Nhập khối lượng và giá trị của từng gói hàng:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> packages[i].weight >> packages[i].value;
    }

    int C, M;
    cout << "Nhập số thực C và số nguyên M: ";
    cin >> C >> M;

    auto greedyResult = GreedyMaxValue(packages, n, C);
    auto dynamicResult = DynamicMaxValue(packages, n, M);

    cout << "Số lượng gói hàng nhiều nhất có thể lấy (D): " << greedyResult.first << endl;
    cout << "Tổng khối lượng các gói hàng đã lấy: " << greedyResult.second << endl;

    cout << "Giá trị lớn nhất có thể đạt được (P): " << dynamicResult << endl;

    return 0;
}