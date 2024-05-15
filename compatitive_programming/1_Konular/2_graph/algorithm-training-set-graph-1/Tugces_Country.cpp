#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <array>
#include <stack>

using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a,b;
    cin >> a >> b;
    vector<set<int>> v(a+1);
    for(int i=0; i<b; i++){
        int x,y;
        cin >> x >> y;
        v[y].insert(x);
        v[x].insert(y);
    }

    int count = 0;
    vector<bool> visited(a+1, false);
    for(int i=1; i<=a; i++){
        if(!visited[i]){
            count++;
            stack<int> s;
            s.push(i);
            while(!s.empty()){
                int t = s.top();
                s.pop();
                visited[t] = true;
                for(auto it = v[t].begin(); it != v[t].end(); it++){
                    if(!visited[*it]){
                        s.push(*it);
                    }
                }
            }
        }
    }
    cout << count;
    return 0;
}