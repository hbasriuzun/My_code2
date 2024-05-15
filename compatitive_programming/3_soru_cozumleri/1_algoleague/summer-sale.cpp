#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <array>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <sstream>
#include <cmath>
#include <climits>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <functional>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <list>
#include <tuple>

using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back 
#define MOD 1000000007
#define INF 1000000000
#define MAXN 1000001
const int N = 1e5+5;


int findMaxIndex(const std::vector<int>& sortedArray, int target) {
    int left = 0;
    int right = sortedArray.size() - 1;
    int result = -1; // Sonuç, verilen sayının olabileceği en büyük indexin bir eksiği
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (sortedArray[mid] <= target) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m;
    vector<int> a(n), b;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b.pb(abs(x-m));
    }
    b.pb(INF);
    sort(b.begin(), b.end());

    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << findMaxIndex(b,x)+1 << endl;
    }
    return 0;
}
