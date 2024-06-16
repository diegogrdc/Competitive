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
int Q;

long double solve() {
    long double l, r;
    cin >> l >> r;
    return 0;
}

int main() {
    optimiza_io
    cin >> Q;
    while(Q --) {
        cout << fixed << setprecision(8) << solve() << "\n";
    }
    return 0;
}
