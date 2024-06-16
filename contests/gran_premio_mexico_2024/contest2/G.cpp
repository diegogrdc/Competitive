//  Copyright © 2024 Diego Garcia Rodriguez del Campo. All rights reserved.
#include <bits/stdc++.h>
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
#define what_is(x) cerr << #x << " is " << x << endl;
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long ll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

const int MAX = 1e6 + 5;

ll ans, times;
int N;
vector<int>ady[MAX];
ll sz[MAX];

void dfs(int x, int p) {
    sz[x] = 1;
    for(auto v : ady[x])
        if(v != p) {
            dfs(v, x);
            sz[x] += sz[v];
        }
    ll tmp = sz[x] * (N - sz[x]);
    if(tmp > ans) {
        ans = tmp;
        times = 1;
    } else if(tmp == ans)
        times++;
}

int main() {
    optimiza_io
    cin >> N;

    for(int i = 1; i < N; i ++) {
        int u, v;
        cin >> u >> v;
        ady[u].push_back(v);
        ady[v].push_back(u);
    }

    dfs(1, 0);
    cout << ans << ' ' << times << '\n';
    return 0;
}
