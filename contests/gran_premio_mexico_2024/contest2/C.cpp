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

ll Q, N, T; 

int main() {
    optimiza_io
    cin >> Q;
    while(Q --) {
        cin >> N >> T;
        T--;
        if(T == 0) {
            cout << N << '\n';
            continue;
        }
        set<ll> s;
        for(ll i = 1; i * i <= T; i ++) {
            if(T % i == 0) {
                if(i <= N)
                    s.insert(i);
                if(T / i <= N)
                    s.insert(T / i);
            }
        }
        cout << s.size() << '\n';
    }
    return 0;
}
