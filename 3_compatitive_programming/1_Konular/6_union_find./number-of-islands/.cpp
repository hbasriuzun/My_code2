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

class Solution {
public:
    array<int,4> x = {1,0,-1,0};
    array<int,4> y = {0,1,0,-1};
    void dsf(vector<vector<char>>& grid, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0'){
            return;
        }
        grid[i][j] = '0';
        for(int k=0;k<4;k++){
            dsf(grid,i+x[k],j+y[k]);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m=grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dsf(grid,i,j);
                }
            }
        }
        return ans;

    }
};