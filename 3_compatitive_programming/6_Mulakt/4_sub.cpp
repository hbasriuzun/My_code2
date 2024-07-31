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


// 3 4 9 14 15 19 28 37 47 50 54 56 59 61 70 73 78 81 92 95 97 99

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int s,count=0;
    cin >> s;
    vector <int> v1(s);
    vector<vector<int>> mtrx(s);
    for(int i=0; i<s; i++)
        cin >> v1[i];
    set<int> mys(v1.begin(),v1.end());

    mtrx[0].pb(v1[0]);
    for(int i=1; i<s; i++){
        mtrx[i].pb(v1[i]);
        for(int j=0; j<i; j++){
            for(int k=0; k<mtrx[j].size(); k++){
                
                if(mtrx[j][k] + mtrx[i][0]>v1[v1.size()-1])
                    break;
                mtrx[i].pb(mtrx[j][k] + mtrx[i][0]);
            }
        }
    }
    for(auto x:mtrx){
        for(int i=1; i<x.size(); i++){
            if(mys.find(x[i]) != mys.end())
                count++;
        }
    }
    cout << count << endl;
    return 0;
}
