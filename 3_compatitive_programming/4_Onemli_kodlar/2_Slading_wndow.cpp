//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,k,sum=0,count=0,a[100005];
    cin >> n >> k;
    deque<int> deq;
    
    for(int i=0; i<n; i++){
        cin >> a[i];
        deq.push_back(a[i]);
        sum+=a[i];
        
        while(sum > k){
            sum-=deq.back();
            deq.pop_back();
        }
        
        if(count < deq.size())
            count = deq.size();
    }
    
    cout << count;
	return 0;
}
