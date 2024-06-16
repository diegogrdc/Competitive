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

int N, M;
set<pii> edges;
set<pii> ans;

void solve(int l, int r) {
    for(int i = l; i < r; i ++)
        for(int j = i + 1; j <= r; j ++) {
            if(edges.find({i, j}) == edges.end())
                ans.insert({i, j});
        }
}

int main() {
    optimiza_io
    cin >> N >> M;
    if(N == 1) {
        cout << "NO\n";
        return 0;
    }

    while(M --) {
        pii e;
        cin >> e.fi >> e.se;
        if(e.fi > e.se)
            swap(e.fi, e.se);
        edges.insert(e);
    }

    solve(1, N/2);
    solve(N/2+1, N);

    cout << "YES\n";
    cout << ans.size() << '\n';
    for(auto &x : ans)
        cout << x.fi << " " << x.se << "\n";
    return 0;
}
