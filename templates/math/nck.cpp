//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 1000005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
const ll MOD = 1e9 + 7;
const ll LIM = 1e6;
ll fact[LIM + 5];
ll finv[LIM + 5];
 
ll fastpow(ll b, ll e) {
    ll ans = 1;
    while(e > 0) {
        if(e & 1)
            ans = (ans * b) % MOD;
        
        b = (b * b) % MOD;
        e >>= 1;
    }
    return ans;
}
 
ll nCk(ll n, ll k) {
    return (fact[n] * ((finv[k] * finv[n - k]) % MOD)) % MOD;
}
 
int main() {
    optimiza_io
    fact[0] = finv[0] = 1;
    for(ll i = 1; i <= LIM; i ++)
        fact[i] = (fact[i - 1] * i) % MOD;
    
    finv[LIM] = fastpow(fact[LIM], MOD - 2);
    
    for(ll i = LIM - 1; i >= 1; i --)
        finv[i] = (finv[i + 1] * (i + 1)) % MOD;
    
    ll T;
    cin >> T;
    while(T --) {
        ll n, k;
        cin >> n >> k;
        cout << nCk(n, k) << "\n";
    }
    return 0;
}
 
// CHECAR LIMITES 