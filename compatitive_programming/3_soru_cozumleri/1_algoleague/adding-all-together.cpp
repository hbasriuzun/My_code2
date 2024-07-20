#include <iostream>
#include <vector>
#include <cmath>

long long sumOfAllSubsets(std::vector<long long> nums) {
    long long n = nums.size();
    long long totalSum = 0;

    // Her alt küme için
    for (long long i = 0; i < n; i++) {
        long long now=0;
        
        for (long long j = i; j < n; j++) {
            now+=nums[j];

            totalSum+=now;
        }

    }

    return totalSum;
}

int main() {
    long long n;
    std::cin >> n;
    std::vector<long long> nums(n);
    for (long long i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    std::cout << sumOfAllSubsets(nums) << std::endl;
    return 0;
}