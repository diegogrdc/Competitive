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

const int MAX = 800 + 5;
const int MOD = 1e9 + 7;
int Q, N;
ll memo[MAX][MAX * 9 * 2];
const int OFFSET = 800 * 9;
const int NUM_OFFSET = 10;

ll tc[25];

ll dp(int n, int diff) {
    if(n == 0)
        return diff == 0;
    if(abs(diff) > n * 9)
        return 0;
    if(memo[n][diff + OFFSET] != -1)
        return memo[n][diff + OFFSET];
    
    ll ans = 0;
    for(int num_diff = -9; num_diff <= 9; num_diff ++)
        if(num_diff != 0)
            ans = (ans + tc[num_diff + NUM_OFFSET] * dp(n - 1, diff + num_diff)) % MOD;
    return memo[n][diff + OFFSET] = ans;
}

ll solve(int n) {
    int ans = 0;
    // Fix first digits to be different to 0
    for(int i = 1; i <= 9; i ++)
        for(int j = 1; j <= 9; j ++)
            if(i != j)
                ans = (ans + dp(n - 1, i - j)) % MOD;

    return ans;
}

int main() {
    optimiza_io
    // Precalc transition cost
    for(int i = 0; i <= 9; i ++)
        for(int j = 0; j <= 9; j ++) 
            if(i != j)
                tc[i - j + NUM_OFFSET]++;

    memset(memo, -1, sizeof(memo));
    cin >> Q;
    while(Q--) {
        cin >> N;
        cout << solve(N) << '\n';
    }
    return 0;
}
