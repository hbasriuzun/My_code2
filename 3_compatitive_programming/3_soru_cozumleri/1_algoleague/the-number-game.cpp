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
#include <tuple>

using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back 
#define MOD 1000000007
#define INF 1000000000
#define MAXN 1000001
const int N = 1e5+5;

bool getScore(int num) {
    int steps = 0;
    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = num * 3 + 1;
        }
        steps++;
    }
    //cout << steps << endl;
    if (steps % 2 == 1) {
        return 1;
    } else {
        return 0;
    }
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,kekik=0,haydarberk=0,num;
    cin >> n;
    bool flag =1;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if(flag){
            kekik += getScore(num);
            flag = 0;
        }else{
            haydarberk += getScore(num);
            flag = 1;
        }
    }
 
    if (kekik > haydarberk) {
        cout << "HAYDARBERK" << endl;
    } else if (kekik < haydarberk) {
        cout << "KEKIK" << endl;
    } else {
        cout << "DRAW" << endl;
    }
    //cout << kekik << " " << haydarberk << endl;
    return 0;
}
