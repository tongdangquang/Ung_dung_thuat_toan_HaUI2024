#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4}; // Dãy số ban đầu
    int k = 7; // Tổng k cần đạt được
    // std::sort(numbers.begin(), numbers.end(), std::greater<int>()); // Sắp xếp giảm dần

    int maxSum = 0; // Biến lưu trữ tổng lớn nhất không vượt quá k
    std::vector<int> bestCombination; // Vector lưu trữ tổ hợp tốt nhất

    // Kiểm tra tất cả các tổ hợp có thể
    for (size_t i = 0; i < numbers.size(); ++i) {
        int currentSum = 0; // Tổng hiện tại
        std::vector<int> currentCombination; // Tổ hợp hiện tại

        for (size_t j = i; j < numbers.size(); ++j) {
            if (currentSum + numbers[j] <= k) {
                currentSum += numbers[j];
                currentCombination.push_back(numbers[j]);
            }
        }

        // Cập nhật tổng lớn nhất và tổ hợp tốt nhất nếu tìm thấy tổ hợp tốt hơn
        // if (currentSum > maxSum) {
        //     maxSum = currentSum;
        //     bestCombination = currentCombination;
        // }
        bestCombination = currentCombination;
    }

    // In ra tổng lớn nhất và tổ hợp tốt nhất
    std::cout << "Tong toi da khong vuot qua k la: " << maxSum << std::endl;
    std::cout << "Cac so duoc chon la: ";
    for (int number : bestCombination) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    return 0;
}