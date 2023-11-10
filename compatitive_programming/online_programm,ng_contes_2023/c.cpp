#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int a,b,count=0;
    cin >> a;

    string s,t;
    cin >> s;
    cin >> b;
    cin >> t;
    if(s[0] != t[0]){
        cout << "NO" << endl;
        return 0;
    }
    for(int i=0; i<b; i++){
        if(s[i] != t[i]){
            count++;
        }
    }
    for(int i=count-1; i<b; i++){
        if(t[i] == 'H' && t[i+1] == 'H'){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}