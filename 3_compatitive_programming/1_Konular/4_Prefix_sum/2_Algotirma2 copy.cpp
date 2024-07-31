#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::vector<int> prefix(arr.size());

    std::partial_sum(arr.begin(), arr.end(), prefix.begin());

    for (int num : prefix) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
