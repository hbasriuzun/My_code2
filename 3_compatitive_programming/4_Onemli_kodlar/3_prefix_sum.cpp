//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,k,sum=0,count=0;
    
    cin >> n >> k;
    vector<int> v1(100005,0);
    map<int,int> mp;
    mp[0]++;
    for(int i=1; i<=n; i++){
        cin >> v1[i];
        v1[i]+=v1[i-1];
        sum+=mp[v1[i]-k];
        mp[v1[i]]++;
    }
    
    cout << sum;
	return 0;
}
