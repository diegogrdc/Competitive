//  Copyright © 2024 Diego Garcia Rodriguez del Campo. All rights reserved.
#include <bits/stdc++.h>
#define MAX 200005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
#define what_is(x) cerr << #x << " is " << x << endl;
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long ll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

int N;

int solve() {
    vector<int> a(N);
    vector<int> v(N, false);
    for(auto & x : a) {
        cin >> x;
        x--;
    }
    int ans = 0;
    for(int i = 0; i < N; i ++)
        if(!v[i]) {
            int sz = 0;
            int in = i;
            while(!v[in]) {
                v[in] = true;
                sz++;
                in = a[in];
            }
            ans += sz - 1;
        }
    return ans;
}

int main() {
    optimiza_io
    cin >> N;

    cout << solve() + solve() << '\n'; 
    return 0;
}
