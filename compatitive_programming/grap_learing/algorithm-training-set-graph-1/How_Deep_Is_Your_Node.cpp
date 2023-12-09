#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <array>

using namespace std;

int main(){
    int a,b;
    cin >> a;
    vector<int> v(a+1);
    for(int i=1; i<a; i++){
        cin >> b;
        v[i] = b;
    }
    cin >> b;
    int t,count = 0;
    t=b;

    while(t!=1){
        count++;
        t = v[t-1];
    }
    cout << count;
    return 0;
}