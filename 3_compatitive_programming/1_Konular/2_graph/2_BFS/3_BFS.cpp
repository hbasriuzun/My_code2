#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>

using namespace std;

void bfs(const unordered_map<int, vector<int>>& graph, int start) {
    unordered_set<int> visited;
    queue<int> nodeQueue;

    nodeQueue.push(start);

    while (!nodeQueue.empty()) {
        int current_node = nodeQueue.front();
        nodeQueue.pop();

        if (visited.find(current_node) == visited.end()) {
            cout << current_node << " ";
            visited.insert(current_node);

            const vector<int>& neighbors = graph.at(current_node);
            for (const int& neighbor : neighbors) {
                if (visited.find(neighbor) == visited.end()) {
                    nodeQueue.push(neighbor);
                }
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

    // 1 sayısından başlayarak BFS uygula
    bfs(graph, 1);

    return 0;
}
