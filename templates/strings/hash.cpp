//  Copyright © 2020 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
#define what_is(x) cerr << #x << " is " << x << endl;
#define pii pair < ll , ll >
#define fi first
#define se second
using namespace std;
typedef long long ll;
 
const ll LIM = 1e6;
const ll P[2] = {193, 769};
const ll MOD[2] = {1000000007, 1000000009};
ll pot[2][LIM + 5];
 
void generateHash(string& w, vector<pii>& h) {
    for(ll i = 0; i < w.size(); i ++) {
        if(!i) {
            h[i].fi = (w[i] - 'a' + 1);
            h[i].se = (w[i] - 'a' + 1);
        }
        else  {
            h[i].fi = (h[i - 1].fi * P[0] + (w[i] - 'a' + 1)) % MOD[0];
            h[i].se = (h[i - 1].se * P[1] + (w[i] - 'a' + 1)) % MOD[1];
        }
    }
}

pii getHash(vector<pii> & h, int l, int r) {
    pii ans = {h[r].fi, h[r].se};
    ll sz = r - l + 1;
    if(l > 0) {
        ans.fi = (ans.fi - (h[l - 1].fi * pot[0][sz])) % MOD[0];
        ans.se = (ans.se - (h[l - 1].se * pot[1][sz])) % MOD[1];
        ans.fi += MOD[0];
        ans.se += MOD[1];
        ans.fi %= MOD[0];
        ans.se %= MOD[1];
    }
    return ans;
}
 
void initPots() {
    pot[0][0] = pot[1][0] = 1;
    for(ll i = 1; i <= LIM; i ++) {
        pot[0][i] = (pot[0][i - 1] * P[0]) % MOD[0];
        pot[1][i] = (pot[1][i - 1] * P[1]) % MOD[1];
    } 
}
 
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    optimiza_io
    initPots();
    return 0;
}
 
// CHECAR LIMITES 