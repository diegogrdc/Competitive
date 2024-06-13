//  Copyright © 2022 Diego Garcia Rodriguez del Campo. All rights reserved.
#include <bits/stdc++.h>
#define MAX 3000005
#define optimiza_io \
    cin.tie(0);     \
    ios_base::sync_with_stdio(0);
#define what_is(x) cerr << #x << " is " << x << endl;
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long ll;

struct Line
{
    ll m, b;
    Line(ll _m, ll _b)
    {
        m = _m;
        b = _b;
    }

    ll eval(ll x)
    {
        return m * x + b;
    }
};

struct LCT
{
    vector<Line> t;
    int N;

    LCT(int _N) : N(_N)
    {
        t.resize(4 * N, Line(1e9, 1e9));
    }

    void add_line(int idx, int l, int r, Line nw)
    {
        int m = (l + r) / 2;
        bool lf = nw.eval(l) < t[idx].eval(l);
        bool md = nw.eval(m) < t[idx].eval(m);
        // t[idx] should keep lower in one side where not intersection
        if (md)
            swap(t[idx], nw);
        if (l == r)
            return;
        else if (lf != md)
            add_line(2 * idx + 1, l, m, nw);
        else
            add_line(2 * idx + 2, m + 1, r, nw);
    }

    ll get(int idx, int l, int r, int x)
    {
        int m = (l + r) / 2;
        if (l == r)
            return t[idx].eval(x);
        else if (x < m)
            return min(t[idx].eval(x), get(2 * idx + 1, l, m, x));
        else
            return min(t[idx].eval(x), get(2 * idx + 2, m + 1, r, x));
    }
};

int N;
pii a[MAX];

void cleanData()
{
    vector<pii> ok;
    ok.push_back(a[1]);
    for (int i = 2; i <= N; i++)
    {
        while (!ok.empty() && ok.back().se <= a[i].se)
            ok.pop_back();
        ok.push_back(a[i]);
    }
    N = ok.size();
    for (int i = 1; i <= N; i++)
        a[i] = ok[i - 1];
}

ll dp[MAX];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    optimiza_io
            cin >>
        N;
    for (int i = 1; i <= N; i++)
        cin >> a[i].fi >> a[i].se;
    sort(a + 1, a + N + 1);
    cleanData();

    // Do LCT Stuff
    int sz = 1e6 + 1;
    LCT lct(sz);
    for (int i = 1; i <= N; i++)
    {
        lct.add_line(0, 1, sz, Line(a[i].se, dp[i - 1]));
        dp[i] = lct.get(0, 1, sz, a[i].fi);
    }
    cout << dp[N] << "\n";
    return 0;
}

// CHECAR LIMITES
// g++ --std=c++11 LCT.cpp -o LCT