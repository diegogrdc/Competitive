//  Copyright © 2022 Diego Garcia Rodriguez del Campo. All rights reserved.
#include <bits/stdc++.h>
#define MAX 200005
#define optimiza_io \
    cin.tie(0);     \
    ios_base::sync_with_stdio(0);
#define what_is(x) cerr << #x << " is " << x << endl;
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long ll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    optimiza_io

        return 0;
}

// CHECAR LIMITES
// g++ --std=c++11 x.cpp -o x