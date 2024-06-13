//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 300005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
ll N, idx;
bool in[MAX], vis[MAX];
bool inCyc[MAX];
vector < ll > ady[MAX];
ll nxt[MAX], pos[MAX], cyc[MAX];
ll tam[MAX];
 
void dfs(ll x, ll p, ll n) {
    pos[x] = n;
    vis[x] = 1;
    cyc[x] = idx;
    for(auto v : ady[x])
        if(v != p)
            dfs(v, x, n + 1);
}
 
void dfs(ll x) {
    vector < ll > s;
    while(! vis[x]) {
        s.push_back(x);
        vis[x] = 1;
        x = nxt[x];
    }
    
    bool chain = 1;
    idx++;
    ll cnt = 0;
    
    for(auto n : s) {
        if(n == x)
            chain = 0;
        
        if(! chain) {
            tam[idx]++;
            cyc[n] = idx;
            inCyc[n] = 1;
            pos[n] = cnt++;
        }
    }
    
    chain = 1;    
    
    for(auto n : s) {
        if(n == x)
            chain = 0;
        
        if(! chain) {
            for(auto v : ady[n])
                if(! inCyc[v]) 
                    dfs(v, x, 1);
        }
    }
    
}
 
int main()
{
    optimiza_io
    cin >> N;
    for(ll i = 1; i <= N; i ++) { 
        cin >> nxt[i];
        in[nxt[i]] = 1;
        ady[nxt[i]].push_back(i);
    }
    
    // DO CHAINS + CYCLES
    for(ll i = 1; i <= N; i ++)
        if(! in[i])
            dfs(i);
    
    // DO ALONE CYCLES
    for(ll i = 1; i <= N; i ++)
        if(! vis[i])
            dfs(i);
    
    for(int i = 1; i <= N; i ++) {
        if(inCyc[i])
            cout << tam[cyc[i]] << " ";
        else 
            cout << pos[i] + tam[cyc[i]] << " ";
    }
    return 0;
}