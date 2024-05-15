#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

int binarySearch(const vector<array<int, 2>>& castle, int target) {
    int left = 0;
    int right = castle.size() - 1;
    int result = -1; // Initialize result to -1 (not found)

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (castle[mid][0] == target) {
            result = mid;
            break;
        } else if (castle[mid][0] < target) {
            left = mid + 1;
        } else {
            result = mid - 1;
            right = mid - 1;
        }
    }

    return result;
}
int main() {
    int a, b;
    cin >> a >> b;

    vector<array<int, 2>> castle(a);

    for (int i = 0; i < a; i++) {
        cin >> castle[i][0];
    }

    for (int i = 0; i < a; i++) {
        cin >> castle[i][1];
    }
    int sum = 0;
    sort(castle.begin(), castle.end());
    for(int i=0; i<b; i++){
        int target;
        cin >> target;
        int index = binarySearch(castle, target);
        sum += castle[index][1];
    }



    cout << sum << endl;
    return 0;
}
