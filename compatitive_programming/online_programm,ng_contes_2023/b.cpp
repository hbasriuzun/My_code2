#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <cstdlib>


using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n,b,count,i;
        char a;
        string s;
        cin >> s;
        
        for(i = 0; i < s.size(); i++){
            b = stoi(s.substr(i, 1));
            if(b<0){
                count++;
            }else{
                break;
            }
        }
        b = s[i] - '0';        
        b++;
        s[i-1] = static_cast<char>('0'+b);
        for(int j = i; j < s.size(); j++){
            s[j] = '0';
        }
        for(int j = i-1; j >= 0; j--){
            if(s[j] == '5'){
                s[j] = '0';
                b = s[i] - '0';
                b++;
                s[j-1] = static_cast<char>('0'+b);
            }else{
                break;
            }
        }
        cout << s << endl;
    }
    

}