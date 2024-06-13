//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 200005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
struct node {
    ll bst, pre, suf, full;
};
 
ll N, Q, vals[MAX];
node tree[MAX*8];
node emptynode;
 
void merge(node & x, node & l, node & r) {
    x.bst = max(l.bst, r.bst);
    x.bst = max(x.bst, l.suf + r.pre);
    x.pre = max(l.pre, l.full + r.pre);
    x.suf = max(r.suf, r.full + l.suf);
    x.full = l.full + r.full;
}
 
void initTree(ll x, ll l, ll r) {
    if(l == r) {
        tree[x].bst = vals[l];
        tree[x].pre = vals[l];
        tree[x].suf = vals[l];
        tree[x].full = vals[l];
        return;
    }
    
    ll mid = (l + r) / 2;
    initTree(2*x+1, l, mid);
    initTree(2*x+2, mid+1, r);
    merge(tree[x], tree[2*x+1], tree[2*x+2]);
}
 
void upd(ll x, ll l, ll r, ll q, ll v) {
    if(q > r or q < l)
        return;
    if(l == r) {
        vals[l] = v;
        tree[x].bst = vals[l];
        tree[x].pre = vals[l];
        tree[x].suf = vals[l];
        tree[x].full = vals[l];
        return;
    } 
 
    ll mid = (l + r) / 2;
    upd(2*x+1, l, mid, q, v);
    upd(2*x+2, mid+1, r, q, v);
    merge(tree[x], tree[2*x+1], tree[2*x+2]);
    
}
 
node qry(ll x, ll l, ll r, ll lq, ll rq) {
    if(l > rq or r < lq) 
        return emptynode;
    if(l >= lq && r <= rq)
        return tree[x];
    
    ll mid = (l + r) / 2;
    node nx, nl, nr;
    nl = qry(2*x+1, l, mid, lq, rq);
    nr = qry(2*x+2, mid+1, r, lq, rq);
    merge(nx, nl, nr);
    return nx;
    
}
 
int main()
{
    optimiza_io
    cin >> N >> Q;
    for(ll i = 1; i <= N; i ++)
        cin >> vals[i];
    
    initTree(0, 1, N);
    while(Q --) {
        ll p, v;
        cin >> p >> v;
        upd(0, 1, N, p, v);
        cout << max(0LL, qry(0, 1, N, 1, N).bst) << "\n";
    }
    
    return 0;
}