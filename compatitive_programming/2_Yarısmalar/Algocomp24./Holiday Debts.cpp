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
    int n, m, sum=0, pay,person_num;
    cin >> n >> m;
    vector<int> person(n+1);
    for (int i = 0; i < m; i++) {
        cin >> person_num >> pay;
        person[person_num] += pay;
    }
    sum=accumulate(person.begin(), person.end(), 0);
    pay=sum/n;
    for (int i = 1; i < n+1; i++) {
        if(person[i]-pay==0)
            cout << i << " " << abs(person[i]-pay) << endl;
        else if(person[i]-pay>0)
            cout << i << " " << abs(person[i]-pay) << " payee" << endl;
        else
            cout << i << " " << abs(person[i]-pay) << " debtor" << endl;
    }

    return 0;
}
