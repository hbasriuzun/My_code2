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

#define ll long long
#define endl '\n'
#define pb push_back 
#define MOD 1000000007
#define INF 1000000000
#define MAXN 1000001
const int N = 1e5+5;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

std::string removeDuplicates(const std::string& str) {
    std::string result;
    char prevChar = '\0'; // Initialize with null character
    
    for (char c : str) {
        if(!isVowel(c)){
            result += c;
            prevChar = c;
        }
        else if (c != prevChar) { // Check if current character is a vowel and different from previous character
            result += c;
            prevChar = c; // Update previous character
        }
    }
    
    return result;
}

bool containsWord(const string& s, const string& t) {
    // Iterate through each character in the first string
    for (int i = 0; i <= s.length() - t.length(); i++) {
        bool found = true;
        
        // Check if the current substring matches the second string
        for (int j = 0; j < t.length(); j++) {
            if (s[i + j] != t[j]) {
                found = false;
                break;
            }
        }
        
        // If the substring matches, return true
        if (found) {
            return true;
        }
    }
    
    // If no match is found, return false
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s,t;
    cin >> s >> t;
    t = removeDuplicates(t);
    s = removeDuplicates(s);
    
    if (containsWord(s, t)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    
    return 0;
}
