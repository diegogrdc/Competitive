//  Copyright © 2022 Diego Garcia Rodriguez del Campo. All rights reserved.
#include <bits/stdc++.h>
#define MAX 300005
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

const int SZ = 1e6;
struct node
{
    Line ln;
    node *l;
    node *r;
    node() : l(nullptr), r(nullptr), ln(Line(1e9, 1e9)){};
};

const ll INF = 1e18;
typedef node *pnode;
node memo[MAX * 10];
int disp;
int N;
pii a[MAX];
pnode root;

pnode newpnode(Line x)
{
    pnode nw = &memo[disp++];
    nw->ln = x;
    return nw;
}

void add_line(pnode nd, int l, int r, Line nw)
{
    int m = (l + r) / 2;
    bool lf = nw.eval(l) < nd->ln.eval(l);
    bool md = nw.eval(m) < nd->ln.eval(m);
    // t[idx] should keep lower in one side where not intersection
    if (md)
        swap(nd->ln, nw);
    if (l == r)
        return;

    if (nd->l == nullptr)
        nd->l = newpnode(nd->ln);
    if (nd->r == nullptr)
        nd->r = newpnode(nd->ln);

    if (lf != md)
        add_line(nd->l, l, m, nw);
    else
        add_line(nd->r, m + 1, r, nw);
}

ll get(pnode nd, int l, int r, int x)
{
    if (nd == nullptr)
        return INF;
    int m = (l + r) / 2;
    if (l == r)
        return nd->ln.eval(x);
    else if (x < m)
        return min(nd->ln.eval(x), get(nd->l, l, m, x));
    else
        return min(nd->ln.eval(x), get(nd->r, m + 1, r, x));
}

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
    root = newpnode(Line(1e9, 1e9));
    for (int i = 1; i <= N; i++)
    {
        add_line(root, 1, SZ, Line(a[i].se, dp[i - 1]));
        dp[i] = get(root, 1, SZ, a[i].fi);
    }
    cout << dp[N] << "\n";
    return 0;
}

// CHECAR LIMITES
// g++ --std=c++11 CHT.cpp -o CHT