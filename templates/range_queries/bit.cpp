//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 200005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
ll N, Q, vals[MAX];
ll bit[MAX];
 
void upd(ll p, ll v) {
    for(ll i = p; i <= N; i += i & -i)
        bit[i] += v;
}
 
ll qry(ll p) {
    ll ans = 0;
    for(ll i = p; i > 0; i -= i & - i)
        ans += bit[i];
    return ans;
}
 
int main() {
    optimiza_io
    cin >> N >> Q;
    for(ll i = 1; i <= N; i ++) {
        cin >> vals[i];
        upd(i, vals[i]);
    }
    
    while(Q --) {
        ll t, a, b;
        cin >> t >> a >> b;
        if(t == 1) {
            upd(a, - vals[a]);
            vals[a] = b;
            upd(a, vals[a]);
        }
        else
            cout << qry(b) - qry(a - 1) << "\n";
    }
    return 0;
}