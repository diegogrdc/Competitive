//  Copyright © 2020 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 2005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
#define what_is(x) cerr << #x << " is " << x << endl;
#define pii pair <int, int>
#define fi first
#define se second
using namespace std;
typedef long long ll;

struct rn {
    int l, r;
    ll v;
    int id;
};


const ll INF = 1e18;
int N, Q, a[MAX], idx;
ll ans[200005];
vector<rn> r;
vector<rn> q;
int ptr;

// 2D MAX SEGTREE
ll tree[4*MAX][4*MAX];

ll qryy(int x, int l, int r, int qyl, int qyh, int tx) {
    if(l > qyh or r < qyl)
        return -INF;
    if(l >= qyl && r <= qyh)
        return tree[tx][x];
    int m = (l + r) / 2;
    return max(qryy(2*x+1, l, m, qyl, qyh, tx), qryy(2*x+2, m+1, r, qyl, qyh, tx));
}

ll qryx(int x, int l, int r, int qxl, int qxh, int qyl, int qyh) {
    if(l > qxh or r < qxl)
        return -INF;
    if(l >= qxl && r <= qxh)
        return qryy(0, 1, N, qyl, qyh, x);
    
    int m = (l + r) / 2;
    return max(qryx(2*x+1, l, m, qxl, qxh, qyl, qyh), qryx(2*x+2, m+1, r, qxl, qxh, qyl, qyh)); 
}

void updy(int x, int l, int r, int qy, ll qv, int tx) {
    if(l > qy or r < qy)
        return;
    if(l == r) {
        tree[tx][x] = qv;
        return;
    }
    int m = (l + r) / 2;
    updy(2*x+1, l, m, qy, qv, tx);
    updy(2*x+2, m+1, r, qy, qv, tx);
    tree[tx][x] = max(tree[tx][2*x+1], tree[tx][2*x+2]);
}

void updx(int x, int l, int r, int qx, int qy, ll qv) {
    if(l > qx or r < qx)
        return;
    
    updy(0, 1, N, qy, qv, x); 
    if(l == r)
        return;
    int m = (l + r) / 2;
    updx(2*x+1, l, m, qx, qy, qv);
    updx(2*x+2, m+1, r, qx, qy, qv);
}

void buildy(int x, int l, int r, int tx) {
    if(l == r) {
        tree[tx][x] = -INF;
        return;
    }
    int m = (l + r) / 2;
    buildy(2*x+1, l, m, tx);
    buildy(2*x+2, m+1, r, tx);
    tree[tx][x] = max(tree[tx][2*x+1], tree[tx][2*x+2]);
}

void buildx(int x, int l, int r) {
    buildy(0, 1, N, x);
    if(l == r) 
        return;
    int m = (l + r) / 2;
    buildx(2*x+1, l, m);
    buildx(2*x+2, m+1, r);
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    optimiza_io

    cin >> N >> Q;
    for(int i = 1; i <= N; i ++)
        cin >> a[i];
    
    for(int i = 1; i <= N; i ++) {
        int sum = 0;
        for(int j = i; j <= N; j ++) {
            sum += a[j];
            r.push_back({i, j, sum, 0});
        }
    }

    q.resize(Q);
    for(auto& v : q) {
        cin >> v.l >> v.r >> v.v;
        v.id = ++idx;
    }

    sort(r.begin(), r.end(), [](rn a, rn b){return a.v < b.v; });
    sort(q.begin(), q.end(), [](rn a, rn b){return a.v < b.v; });

    // INIT TREE
    buildx(0, 1, N);

    for(auto& v : q) {
        // Update all posible
        while(ptr < r.size() && r[ptr].v <= v.v) {
            // Add 
            updx(0, 1, N, r[ptr].l, r[ptr].r, r[ptr].v);
            ptr++;
        }
        ans[v.id] = qryx(0, 1, N, v.l, v.r, v.l, v.r);
    }
    for(int i = 1; i <= Q; i ++) {
        if(ans[i] == -INF)
            cout << "NONE\n";
        else 
            cout << ans[i] << "\n";
    }
    return 0;
}
 
// CHECAR LIMITES 