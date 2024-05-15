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
    int count=1,count2=0,mx=1,i,j,k;
    string a,b;
    cin >> a;
    for( i=0; i<a.size(); i++){
        count=1;
        count2=0;
        for( j=1; j<=i && j+i<a.size(); j++){
            if(a[i-j] == a[i+j]){
                count+=2;
            }else{
                break;
            }
        }
        j--;

        for( k=0; k<=i && k+i<a.size(); k++){
            if(a[i-k] == a[i+k+1]){
                count2+=2;
            }else{
                break;
            }
        }
    
        if(mx<count2){
            mx=count2;
            b=a.substr(i-k+1,k*2);
        }
        if(mx<count){
            mx=count;
            b=a.substr(i-j,j*2+1);
        }
    }
    cout <<  b << endl;;
    return 0;
}
