#include <iostream>
#include <vector>

void generateSubsetSums(const std::vector<int>& arr, std::vector<int>& subsetSums) {
    int n = arr.size();

    for (int i = 0; i < (1 << n); i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                sum += arr[j];
            }
        }
        subsetSums.push_back(sum);
    }
}

int main() {
    std::vector<int> arr = {1, 2, 3};
    std::vector<int> subsetSums;

    generateSubsetSums(arr, subsetSums);

    // Elde edilen alt küme toplamlarını yazdır
    for (int sum : subsetSums) {
        std::cout << sum << " ";
    }

    return 0;
}
