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

    vector<int> adj[N];

    //eger yonlu ise
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[2].push_back(4);
    adj[3].push_back(4);
    adj[4].push_back(1);

    //eger yonlu degilse
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[2].push_back(4);
    adj[4].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(3);
    adj[4].push_back(1);
    adj[1].push_back(4);

    

    vector<array<int, 2>> adj2[N]; 

    adj2[1].push_back({2, 5});
    adj2[2].push_back({3, 7});
    adj2[2].push_back({4, 6});
    adj2[3].push_back({4, 5});
    adj2[4].push_back({1, 2});

    int adj[N][N];

    adj[1][2] = 5;
    adj[2][3] = 7;
    adj[2][4] = 6;
    adj[3][4] = 5;
    adj[4][1] = 2;
    


    return 0;
}