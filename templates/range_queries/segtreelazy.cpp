//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 200005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
ll N, Q, vals[MAX];
ll tree[MAX*8];
ll lazy[MAX*8];
 
void updLazy(ll x, ll l, ll r) {
    if(! lazy[x])
        return;
    tree[x] += lazy[x] * (r - l + 1);
    lazy[2*x+1] += lazy[x];
    lazy[2*x+2] += lazy[x];
    lazy[x] = 0;
}
 
void initTree(ll x, ll l, ll r) {
    if(l == r) {
        tree[x] = vals[l];
        return;
    }
    
    ll mid = (l + r) / 2;
    initTree(2*x+1, l, mid);
    initTree(2*x+2, mid+1, r);
    tree[x] = tree[2*x+1] + tree[2*x+2];
}
 
void upd(ll x, ll l, ll r, ll lq, ll rq, ll v) {
    updLazy(x, l, r);
    if(l > rq or r < lq)
        return;
    if(l >= lq && r <= rq) {
        lazy[x] += v;
        updLazy(x, l, r);
        return;
    }
    
    ll mid = (l + r) / 2;
    upd(2*x+1, l, mid, lq, rq, v);
    upd(2*x+2, mid+1, r, lq, rq, v);
    tree[x] = tree[2*x+1] + tree[2*x+2];
}
 
ll qry(ll x, ll l, ll r, ll lq, ll rq) {
    updLazy(x, l, r);
    if(l > rq or r < lq)
        return 0;
    if(l >= lq && r <= rq)
        return tree[x];
    
    ll mid = (l + r) / 2;
    return qry(2*x+1, l, mid, lq, rq) + qry(2*x+2, mid+1, r, lq, rq);
}
 
int main() {
    optimiza_io
    cin >> N >> Q;
    for(ll i = 1; i <= N; i ++)
        cin >> vals[i];
    
    initTree(0, 1, N);
    while(Q --) {
        ll t, l, r, k;
        cin >> t;
        if(t == 1) {
            cin >> l >> r >> k;
            upd(0, 1, N, l, r, k);
        }
        else {
            cin >> k;
            cout << qry(0, 1, N, k, k) << "\n";
        }
    }
    return 0;
}