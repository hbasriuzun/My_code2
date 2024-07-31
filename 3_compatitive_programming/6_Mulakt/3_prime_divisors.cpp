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
    cin.tie(0);
    map<int,bool> ch;
    int a=INF,sum=0,b;
    cin >> a;
    b=a;
    while(a%2==0){
        ch[2]=1;
        a/=2;
    }
    for(int i=3; i*i<=b;i+=2){
        while(a%i==0){
            ch[i]=1;
            a/=i;
        }
    }
    for(auto x: ch)
        if(x.second==1)
            sum += x.first;
    cout << sum+1 << endl;
    return 0;
}
