#include <iostream>
#include <vector>

std::vector<int> prefixSum(const std::vector<int>& arr) {
    std::vector<int> prefix;
    int sum = 0;
    for (int num : arr) {
        sum += num;
        prefix.push_back(sum);
    }
    return prefix;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::vector<int> prefix = prefixSum(arr);

    for (int num : prefix) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
