#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Sonsuz değer
const int INF = numeric_limits<int>::max();

// Graf yapısı
struct Graph {
    int numNodes;
    vector<vector<pair<int, int>>> adjList;

    Graph(int n) : numNodes(n), adjList(n) {}

    // Kenar ekleme
    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
    }
};

// En kısa yolu bulma
vector<int> shortestPath(const Graph& graph, int start, int end) {
    vector<int> distance(graph.numNodes, INF);
    vector<int> parent(graph.numNodes, -1);
    vector<bool> visited(graph.numNodes, false);
    vector<int> path;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distance[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (u == end) {
            // Bitiş noktasına ulaşıldı, yol oluştur
            int node = end;
            while (node != -1) {
                path.push_back(node);
                node = parent[node];
            }
            reverse(path.begin(), path.end());
            break;
        }

        if (visited[u]) {
            continue;
        }

        visited[u] = true;

        for (auto& neighbor : graph.adjList[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                parent[v] = u;
                pq.push({distance[v], v});
            }
        }
    }

    return path;
}

int main() {
    int numNodes, numEdges, u, v, weight;
    cin >> numNodes >> numEdges;

    Graph graph(numNodes);
    
    for (int i = 0; i < numEdges; ++i) {
        cin >> u >> v >> weight;
        graph.addEdge(u, v, weight);
    }

    int start = 0;
    int end = numNodes - 1;

    vector<int> path = shortestPath(graph, start, end);

    if (path.empty()) {
        cout << "Başlangıç ve bitiş noktaları arasında yol bulunamadı." << endl;
    } else {
        cout << "En kısa yol: ";
        for (int i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i < path.size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
    }

    cout << "Bu yol üzerinde geçilen düğümler: ";
    for (int i = 0; i < path.size(); ++i) {
        cout << path[i] << " ";
    }
    cout << endl;

    return 0;
}
