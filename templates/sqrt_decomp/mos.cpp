//  Copyright © 2020 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 200005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
#define what_is(x) cerr << #x << " is " << x << endl;
#define pii pair <ll, ll>
#define fi first
#define se second
using namespace std;
typedef long long ll;

struct query {
    ll l, r, id;
};

ll N, M, a[MAX];
query q[MAX];
ll ans[MAX], curr;
const ll SZ = 447;

bool cmp(query a, query b) {
    if(a.l / SZ != b.l / SZ)
        return a.l / SZ < b.l / SZ;
    return a.r < b.r;
}

ll cnt[5 * MAX];
void change(ll p, ll v) {
    // Depends on problem
    curr -= cnt[a[p]] * cnt[a[p]] * a[p];
    cnt[a[p]] += v;
    curr += cnt[a[p]] * cnt[a[p]] * a[p];
}


void mos() {
    sort(q + 1, q + M + 1, cmp);
    ll l = 1, r = 0;
    for(ll i = 1; i <= M; i ++) {
        // Move right barrier
        while(r < q[i].r)
            change(++r, 1);
        while(r > q[i].r)
            change(r--, -1);
        // Move left barrier
        while(l > q[i].l)
            change(--l, 1);
        while(l < q[i].l)
            change(l++, -1);
        ans[q[i].id] = curr;
    }

    for(ll i = 1; i <= M; i ++)
        cout << ans[i] << "\n";
}
 
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    optimiza_io
    cin >> N >> M;
    for(ll i = 1; i <= N; i ++)
        cin >> a[i];
    for(ll i = 1; i <= M; i ++) {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }

    // INIT ROOT
    mos();
    return 0;
}
 
// CHECAR LIMITES 