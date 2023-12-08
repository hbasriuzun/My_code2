#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

vector<vector<int> > take_graph(int V, vector<pair<int,int> > edges){
    vector<vector<int> > v(V);
    for(int i=0; i<edges.size(); i++){
        int x = edges[i].first;
        int y = edges[i].second;
        v[x].push_back(y);
        v[y].push_back(x);
    }

}
