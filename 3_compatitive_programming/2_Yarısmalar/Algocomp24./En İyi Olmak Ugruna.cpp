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
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,p=0,my;
    cin >> n;
    vector<int> a(n);
    cin >> my;
    a[0]=my;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int ans = 0;
    if(a[0] == my){
        cout << 0 << endl;
        return 0;
    }

    for (size_t i = 1; i < n; i++)
    {
        if(a[i] )
    }
    
    

    return 0;
}
