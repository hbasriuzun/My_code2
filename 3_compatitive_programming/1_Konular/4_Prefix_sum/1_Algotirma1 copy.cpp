#include <iostream>
#include <vector>

std::vector<int> prefixSum(const std::vector<int>& arr) {
    int n = arr.size();
    std::vector<int> prefix(n);

    prefix[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        prefix[i] = prefix[i - 1] + arr[i];
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
