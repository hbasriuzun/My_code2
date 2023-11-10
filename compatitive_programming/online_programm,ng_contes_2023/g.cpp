#include <iostream>
#include <vector>
#include <string>

/* Melih loves playing hopscotch, but he has a unique twist to it. He enjoys playing hopscotch only on the nodes of a graph. Starting from any node, he hops to adjacent nodes by changing his foot and continues this pattern. The game ends when Melih returns to the node he started from. If, upon returning, he stepped on that node with a different foot than the one he started with and hasn't crossed the same edge twice along the way, Melih is happy.

Kerim, who loves writing research papers about graphs, decides to investigate this strange game. He labels nodes as Hopscotchable Nodes if there is at least one path from that node where Melih can end the game happily.

Help Kerim to count the number of Hopscotchable Nodes in a given undirected graph.
*/
using namespace std;
int main() {
    //I will take graph
    int a,b;
    std::cin >> a >> b;
    std::vector<std::vector<int>> v(a);
    for(int i=0; i<b; i++){
        int x,y;
        std::cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    //I will take the starting node
    int start;
    std::cin >> start;
    

    return 0;
}
