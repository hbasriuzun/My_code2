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
    int x=4, y=-8;
    /* 00...00100 pozitif
       11...11000 negatif
      ^__________
       11...11100 negatif -4
       
    */
    cout << x << " bit değeri  " << bitset<32>(x) << endl;
    cout << y << " bit değeri " << bitset<32>(y) << endl;

    int a=x^y;
    if(a<0)
        cout <<"karşıtlar \n";
    else    
        cout << "karşıt değiller  \n";
    
    cout << a << " bit değeri " << bitset<32>(a) << endl;

    return 0;
}
