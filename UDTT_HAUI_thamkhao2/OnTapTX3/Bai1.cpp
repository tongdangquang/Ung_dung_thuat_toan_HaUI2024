#include <iostream>

using namespace std;

struct Fan
{
    string brand;
    string color;
    int price;
};

void greedyAlgorithm(const Fan fans[], int n, int p)
{
    int totalCost = 0;
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        if (totalCost + fans[i].price <= p)
        {
            totalCost += fans[i].price;
            ++count;
            cout << "Tên hãng: " << fans[i].brand << ", Giá bán: " << fans[i].price << endl;
        }
    }
    cout << "Số lượng quạt bàn mua được: " << count << endl;
}

int main()
{
    int p = 100;
    int n = 5;
    Fan fans[n] = {
        {"A", "Đỏ", 50},
        {"B", "Xanh", 20},
        {"C", "Cam", 30},
        {"D", "Vàng", 40},
        {"E", "Tím", 10},
    };

    greedyAlgorithm(fans, n, p);

    return 0;
}