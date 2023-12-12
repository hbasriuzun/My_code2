#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <array>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <sstream>
#include <cmath>
#include <climits>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <functional>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <list>

using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back 
#define MOD 1000000007
#define INF 1000000000
#define MAXN 1000001
const int N = 1e5+5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a,b,t;
    vector <int> ans;
    cin >> a >> b;
    vector <vector<int>> adj[a+1];
    int x,y;
    for(int i=0; i<b; i++){
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    vector<bool> visited(a+1, false);
    priority_queue<int> frontier;
    set<int> check;
    for(int i=0; i<a; i++){
        check.insert(i);
    }
    frontier.push(1);

    while (!frontier.empty())
    {
        t = frontier.top();
        frontier.pop();
        if(visited[t] == true)
            continue;

        while(adj[t].size()==0){
            ans.pb(t);
            visited[t] = true;
            if (auto search = check.find(t); search != check.end())
                check.erase(search);
            t = *check.cbegin();
        }
        while(adj[t].size()==1 ){
            ans.pb(t);
            visited[t] = true;
            if (auto search = check.find(t); search != check.end())
                check.erase(search);
            adj[t][0];
            t = *check.cbegin();
        }

        
            
        ans.pb(t);
        visited[t] = true;
        if (auto search = check.find(t); search != check.end())
            check.erase(search);

        for(auto x: adj[t]){
            frontier.push(x);
        }
    }
    
    

    return 0;
}