//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 200005
#define INF 1e9
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
// CHECK INF
 
int N, Q, vals[MAX];
int tree[MAX*8];
 
void initTree(int x, int l, int r) {
    if(l == r) {
        tree[x] = vals[l];
        return;
    }
    
    int mid = (l + r) / 2;
    initTree(2*x+1, l, mid);
    initTree(2*x+2, mid+1, r);
    tree[x] = min(tree[2*x+1], tree[2*x+2]);
}
 
void upd(int x, int l, int r, int q, int v) {
    if(l > q or r < q)
        return;
    if(l == r) {
        tree[x] = v;
        return;
    }
    
    int mid = (l + r) / 2;
    upd(2*x+1, l, mid, q, v);
    upd(2*x+2, mid+1, r, q, v);
    tree[x] = min(tree[2*x+1], tree[2*x+2]);
}
 
int qry(int x, int l, int r, int lq, int rq) {
    if(l > rq or r < lq)
        return INF;
    if(l >= lq && r <= rq)
        return tree[x];
    int mid = (l + r) / 2;
    return min(qry(2*x+1, l, mid, lq, rq), qry(2*x+2, mid+1, r, lq, rq));
}
 
int main() {
    optimiza_io
    cin >> N >> Q;
    for(int i = 1; i <= N; i ++)
        cin >> vals[i];
    
    initTree(0, 1, N);
    
    while(Q --) {
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1) 
            upd(0, 1, N, a, b);
        else
            cout << qry(0, 1, N, a, b) << "\n";
    }
    return 0;
}