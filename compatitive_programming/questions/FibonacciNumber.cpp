#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back 
// 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610
ll fib(ll n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fib(n-1) + fib(n-2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    auto start = std::chrono::high_resolution_clock::now();

    cout << fib(40) << endl;


    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    double seconds = duration.count();

    std::cout << "Gecen sure: " << seconds << " saniye" << std::endl;
    return 0;
}