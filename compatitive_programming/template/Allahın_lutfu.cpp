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

using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back 
#define MOD 1000000007
#define INF 1000000000
#define MAXN 1000001
const int N = 1e5+5;


void dfs(const unordered_map<int, vector<int>>& graph, int start) {
    unordered_set<int> visited;
    stack<int> nodeStack;

    nodeStack.push(start);

    while (!nodeStack.empty()) {
        int current_node = nodeStack.top();
        nodeStack.pop();

        if (visited.find(current_node) == visited.end()) {
            cout << current_node << " ";
            visited.insert(current_node);

            const vector<int>& neighbors = graph.at(current_node);
            for (auto it = neighbors.rbegin(); it != neighbors.rend(); ++it) {
                nodeStack.push(*it);
            }
        }
    }
}

int main() {
    // Örnek bir sayı grafiği
    unordered_map<int, vector<int>> graph = {
        {1, {2, 3}},
        {2, {1, 4, 5}},
        {3, {1, 6}},
        {4, {2, 7}},
        {5, {2, 8}},
        {6, {3}},
        {7, {4}},
        {8, {5}}
    };

    // 1 sayısından başlayarak DFS uygula
    dfs(graph, 1);

    return 0;
}
