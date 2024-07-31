#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <array>

using namespace std;

int main(){
    int nodes, edges;
    cin >> nodes >> edges;
    vector <set<int>> v(nodes+1);
    set <array<int,2>> s;
    int a,b;
    for(int i=0; i<edges; i++){
        cin >> a >> b;
        v[a].insert(b);
    }

    for(int i=1; i<nodes+1; i++){
        for(auto l : v[i]){
            if(v[l].find(i) != v[l].end()){
                if(i < l)
                s.insert({i,l});
            }
        }
    }


    for_each(s.cbegin(),s.cend(),[](array<int,2> a){
        cout << a[0] << " " << a[1] << endl;
    });
    return 0;
}