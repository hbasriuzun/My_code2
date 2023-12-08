#include <iostream>
#include <list>
#include <vector>

class Graph {
public:
    Graph(int vertices); // Constructor
    void addEdge(int v, int w); // Kenar eklemek için fonksiyon
    void DFS(int startVertex); // DFS algoritması
private:
    int vertices;
    std::vector<std::list<int>> adjacencyList; // Bağlantı listesi
    void DFSUtil(int vertex, std::vector<bool>& visited); // DFS iç yardımcı fonksiyonu
};

// Constructor
Graph::Graph(int vertices) {
    this->vertices = vertices;
    adjacencyList.resize(vertices);
}

// Kenar eklemek için fonksiyon
void Graph::addEdge(int v, int w) {
    adjacencyList[v].push_back(w);
}

// DFS iç yardımcı fonksiyonu
void Graph::DFSUtil(int vertex, std::vector<bool>& visited) {
    visited[vertex] = true;
    std::cout << vertex << " ";

    // Bağlantılı düğümleri gez
    for (auto i = adjacencyList[vertex].begin(); i != adjacencyList[vertex].end(); ++i) {
        if (!visited[*i]) {
            DFSUtil(*i, visited);
        }
    }
}

// DFS algoritması
void Graph::DFS(int startVertex) {
    // Ziyaret edilip edilmediğini kontrol etmek için bir vektör
    std::vector<bool> visited(vertices, false);

    // DFS çağrısını yap
    DFSUtil(startVertex, visited);
}

int main() {
    // Bir graf oluştur
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    std::cout << "Depth-First Traversal (starting from vertex 0): ";
    g.DFS(0);

    return 0;
}
