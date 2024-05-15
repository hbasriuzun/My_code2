#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <stack>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Graph {
    int numNodes;
    vector<vector<pair<int, int>>> adjList;

    Graph(int n) : numNodes(n), adjList(n) {}

    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
    }
};

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
            int node = end;
            while (node != -1) {
                path.push_back(node);
                node = parent[node];
            }
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

    stack<int> pathStack;
    for (int node : path) {
        pathStack.push(node);
    }

    vector<int> reversedPath;
    while (!pathStack.empty()) {
        reversedPath.push_back(pathStack.top());
        pathStack.pop();
    }

    return reversedPath;
}

int main() {
    int n,m,k,ans=0;
    cin >> n >> m >> k;
    Graph graph(n+1);
    vector<int> a(k);
    for(int i=0; i<k; i++){
        cin >> a[i];
    }

    for(int i=0; i<m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }

    int start = 1;
    int end = n;

    vector<int> path = shortestPath(graph, start, end);

    for(int i = 0; i < path.size(); i++){
        cout << path[i] << " ";
    }
    cout << endl;
    for(int i=0; i<a.size(); i++){
        cout << a[i] << " ";
    }
    // a * weight
    for(int i = path.size() - 1; i >= 0;){
        for(int j = 0; j < k; ++j) {
            ans+=a[j]*;
            i--;
            if(i < 0) break;
        }
    }
    cout << ans << endl;

    return 0;
}
