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
const int N = 2e5+5;

vector <int> adj[N];
stack <int> frontier;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a,b,ans=0,t;
    cin >> a;
    int x;
    for(int i=0; i<a-1; i++){
        cin >> x;
        adj[x].pb(i+2);
    }
     
    cin >> b;
    frontier.push(b);
    while(!frontier.empty()){
        t = frontier.top();
        frontier.pop();
        for(auto i : adj[t]){
            frontier.push(i);
        }
        ans++;
    }
    cout << ans;

    return 0;
}