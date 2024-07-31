#include <iostream>
#include <queue>
#include <vector>

class Graph {
public:
    Graph(int vertices); // Constructor
    void addEdge(int v, int w); // Kenar eklemek için fonksiyon
    void BFS(int startVertex); // BFS algoritması
private:
    int vertices;
    std::vector<std::vector<int>> adjacencyList; // Bağlantı listesi
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

// BFS algoritması
void Graph::BFS(int startVertex) {
    // Ziyaret edilip edilmediğini kontrol etmek için bir vektör
    std::vector<bool> visited(vertices, false);

    // BFS sırasında kullanılan kuyruk
    std::queue<int> bfsQueue;

    // Başlangıç düğümünü işaretle ve kuyruğa ekle
    visited[startVertex] = true;
    bfsQueue.push(startVertex);

    std::cout << "Breadth-First Traversal starting from vertex " << startVertex << ": ";

    while (!bfsQueue.empty()) {
        // Kuyruktan bir düğümü çıkar ve ekrana yazdır
        int currentVertex = bfsQueue.front();
        std::cout << currentVertex << " ";
        bfsQueue.pop();

        // Komşu düğümleri ziyaret et ve kuyruğa ekle
        for (int neighbor : adjacencyList[currentVertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                bfsQueue.push(neighbor);
            }
        }
    }

    std::cout << std::endl;
}

int main() {
    // Bir graf oluştur
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    // BFS çağrısını yap
    g.BFS(0);

    return 0;
}
