//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 200005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
const ll MOD = 1e9 + 7;
ll T;
 
ll fastpow(ll b, ll e) {
    ll ans = 1;
    while(e > 0)
    {
        if(e & 1)
            ans = (ans * b) % MOD;
        
        b = (b * b) % MOD;
        e >>= 1;
    }
    return ans;
}
 
int main()
{
    optimiza_io
    cin >> T;
    while(T --) {
        ll a, b;
        cin >> a >> b;
        cout << fastpow(a, b) << "\n";
    }
    return 0;  
}