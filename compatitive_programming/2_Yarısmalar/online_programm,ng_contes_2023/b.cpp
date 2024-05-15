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
        int n,b,count=0,i;
        char a,ch;
        string s;
        cin >> s;
        if(s.size()==1){
            if(s[0] == '0'){
                cout << "0" << endl;
                continue;
            }else{
                b = s[0] - '0';        
                if(b<5)
                    cout << s[0] << endl;
                else{
                    cout << "10" << endl;
                }
            }

            continue;
        }
        
        for(i = 0; i < s.size(); i++){
            b = s[i] - '0';
            if(b<0){
                count++;
            }else{
                break;
            }
        }
        
        if(i==0){
            s.push_back('0');
            s[0] = '1';
            cout << s << endl;
            continue;
        }
        if(count==s.size()){
            cout << s << endl;
            continue;
        }
        b = s[i] - '0';        
        b++;
        ch = static_cast<char>('0'+b);
        s[i-1] = ch; 
        for(int j = i; j < s.size(); j++){
            s[j] = '0';
        }
        
        for(int j = i-1; j >= 0; j--){
            if(s[j] == '5'){
                s[j] = '0';
                b = s[i] - '0';
                b++;
                ch = static_cast<char>('0'+b);
                s[j-1] = ch; 
            }else{
                break;
            }
            
        }
        cout << s << endl;
    }
    

}