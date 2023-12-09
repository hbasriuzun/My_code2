#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <set>
using namespace std;

int main(){
    int nodes, edges;
    cin >> nodes >> edges;

    vector<set<int> > v(nodes+1);
    vector<vector<int>> v2(nodes+1,vector<int>(nodes+1,0));
        int a,b;

    for(int i=0; i<edges; i++){
        cin >> a >> b;
        v[a].insert(b);
        v[b].insert(a);
    }
    for(int i=1; i<nodes+1; i++){
        for(auto l : v[i]){
            v2[i][l] = 1;
        }
    }

    //print v1
    for(int i=1; i<nodes+1; i++){
        for(auto a : v[i]){
            cout << a << " ";
        }
        cout << endl;
    }


    //print v2
    for(int i=1; i<nodes+1; i++){
        for(int j=1; j<nodes+1; j++){
            cout << v2[i][j] << " ";
        }
        cout << endl;
    }

    
}