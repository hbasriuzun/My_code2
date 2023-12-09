#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    int nodes, edges;
    cin >> nodes >> edges;
    vector <set<int>> v(nodes+1);

    int a,b;
    for(int i=0; i<edges; i++){
        cin >> a >> b;
        v[a].insert(b);
        v[b].insert(a);
    }

    for(int i=1; i<nodes+1; i++){
        cout << v[i].size() << " ";
    }

    return 0;
}