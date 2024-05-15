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


bool has_path(vector<vector<int>> grap,int sr,int ds){
    if(sr == ds) return true;
    
    for(auto x : grap[sr])
        if(has_path(grap,x,ds)==true)
            return  true;

    return false;
}

int main() {
    vector< vector <int> > grap;
    grap.pb({1,2});
    grap.pb({2,3});
    grap.pb({3});
    grap.pb({5,6,9});   
    grap.pb({7,8});
    grap.pb({9,1,3,7});
    grap.pb({1,2,3,4,9});
    grap.pb({1,2,3,4,5,6,7,8,9});
    grap.pb({1,2,3,4,5});
    grap.pb({1,3,4,9});





    cout << "sonuc" << has_path(grap,0,8) << endl;

    return 0;
}
