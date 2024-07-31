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
#include <tuple>

using namespace std;

tuple<int, int> counter (string s, char letter, int began) {
    int times = 0, m=0, first_seen;
    for (int k=began; k<s.size(); k++) {

        if (s[k] == letter) {
            times++;
            m++;
        }

        if (m == 1) {
            first_seen = k;
            m = 0;
        }
    }
    return make_tuple(times, first_seen);
}

int factorial (int num) {
    int fact_num = 1;

    for (int i=1; i<=num; i++) {
        fact_num = i;
    }
    return fact_num;
}

int main() {

    int output[4] = {0, 0, 0, 0};
    string letters = "CSEIM";
    string s;

    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        cin >> s;

        auto timesC = get<0>(counter(s, 'C', 0));
        auto timesE = get<0>(counter(s, 'E', 0));
        auto timesI = get<0>(counter(s, 'I', 0));
        auto timesM = get<0>(counter(s, 'M', 0));

        auto beganCS = get<1>(counter(s, 'C', 0));
        auto beganIE = get<1>(counter(s, 'I', 0));
        auto beganME = get<1>(counter(s, 'M', 0));

        auto timesCS = get<0>(counter(s, 'S', beganCS));
        auto timesIE = get<0>(counter(s, 'E', beganIE));
        auto timesME = get<0>(counter(s, 'E', beganME));

        int input = timesE-3;
        int calcl = (6 * factorial(input) );

        output[0] = timesC * timesCS;
        output[1] = factorial(timesE)/calcl;
        output[2] = timesI * timesIE;
        output[3] = timesM * timesME;

        for (int m=0; m<4; m++) {
            cout << output[m] << " " ;
        }
        cout << endl;
    }

    return 0;

}