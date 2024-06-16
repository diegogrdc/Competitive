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

const int MAX = 1e5 + 5;

int N;
pii a[MAX];
set<pii> ans; 

int main() {
    optimiza_io
    cin >> N;
    for(int i = 1; i <= N; i ++) {
        cin >> a[i].fi;
        a[i].se = i;
    }

    sort(a + 1, a + N + 1);
    
    for(int i = 1; i <= N; i ++) {
        if(a[i].fi > i) {
            cout << -1 << "\n";
            return 0;
        }
        for(int j = 1; j <= a[i].fi - 1; j ++)
            ans.insert({a[i].se, a[j].se});
    }

    cout << ans.size() << "\n";
    for(auto &x : ans)
        cout << x.fi << " " << x.se << "\n";
    return 0;
}
