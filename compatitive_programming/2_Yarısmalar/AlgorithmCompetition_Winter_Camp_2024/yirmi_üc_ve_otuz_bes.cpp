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

void solution(vector< vector<int> > arr,int n,int m){
    vector< vector<int> > arr2;
    arr2=arr;
    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(arr[i][j] == 23 && (arr[i-1][j-1] != 23 && arr[i-1][j] != 23 && arr[i-1][j+1] != 23 && arr[i][j-1] != 23 && arr[i][j+1] != 23 && arr[i+1][j-1] != 23 && arr[i+1][j] != 23 && arr[i+1][j+1] != 23)){
                arr2[i][j] = 35;
            }else if(arr[i][j] == 35 && (arr[i-1][j-1] != 35 && arr[i-1][j] != 35 && arr[i-1][j+1] != 35 && arr[i][j-1] != 35 && arr[i][j+1] != 35 && arr[i+1][j-1] != 35 && arr[i+1][j] != 35 && arr[i+1][j+1] != 35)){
                arr2[i][j] = 23;
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }

}

int main() {
    int n,m;
    cin >> n >> m;
    vector < vector<int> > arr(n+2,vector<int>(m+2,0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }

    solution(arr,n,m);

    return 0;
}
