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

map<ll, bool> primeDP;

bool isprime(ll sayi) {
    if (sayi < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(sayi); i++) {
        if (sayi % i == 0) {
            return false;
        }
    }
    return true;
}


void solution(vector<ll> arr,ll n,ll m){
    ll sura,berat=0,ch,check=0;
    sura = n;
    for(ll i=0; i<n; i++){

        for(ll j=0; j<=m; j++){
            if(isprime(arr[i]+j)){
                berat++;
                sura--;
                break;
            }
        }
    }
    if(sura >= berat){
        cout << "Sura" << endl;
        cout << sura << endl;
    }else{
        cout << "Berat" << endl;
        cout << berat << endl;
    }
}

int main() {
    ll n,m;
    cin >> n >> m;
    vector <ll> arr(n,0);
    for(ll i=0; i<n; i++){
        cin >> arr[i];
    }
    solution(arr,n,m);

    return 0;
}
