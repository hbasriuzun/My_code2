#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back 
// 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610
// 1 2 3 4 5  6  7  8  9  10 11  12  13  14
ll fib(ll n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fib(n-1) + fib(n-2);
}

ll fib2(ll n) {
    ll a = 0, b = 1, c;
    if(n == 0) return a;
    for(int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

ll fib3(ll n) {
    ll f[n+2];
    f[0] = 0;
    f[1] = 1;
    for(int i = 2; i <= n; i++) {
        f[i] = f[i-1] + f[i-2];
    }
    return f[n];
}


void multiply(ll F[2][2], ll M[2][2]) {
    ll x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
    ll y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
    ll z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
    ll w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];
 
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

ll power(ll F[2][2], ll n) {
    if(n == 0 || n == 1) return 0;
    ll M[2][2] = {{1, 1}, {1, 0}};
    power(F, n/2);
    multiply(F, F);
    if(n % 2 != 0) multiply(F, M);
    return 0;
}

ll fib_matrix(ll n) {
    ll F[2][2] = {{1, 1}, {1, 0}};
    if(n == 0) return 0;
    power(F, n-1);
    return F[0][0];
}

ll fib4(ll n) {
    double phi = (1 + sqrt(5)) / 2;
    return round(pow(phi, n) / sqrt(5));
}

ll fib5_memorization(ll n, ll *memo) {
    if(memo[n] != -1) return memo[n];
    if(n <= 1) return n;
    memo[n] = fib5_memorization(n-1, memo) + fib5_memorization(n-2, memo);
    return memo[n];
}

int main()  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    auto start = std::chrono::high_resolution_clock::now();

    cout << fib_matrix(999999999999999999) << endl;


    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    double seconds = duration.count();

    std::cout << "Gecen sure: " << seconds << " saniye" << std::endl;
    int a;
    cin >> a;
    a = 5+5;
    return 0;
}