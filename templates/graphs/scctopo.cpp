//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 200005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
ll N, M, cmpid, ans;
vector < ll > ady[MAX], rady[MAX];
bool vis[MAX];
stack < ll > s;
ll cmp[MAX];
vector < ll > inCmp[MAX];
vector < ll > adycmp[MAX];
ll in[MAX], bst[MAX];
ll vlcmp[MAX], vl[MAX];
 
void rdfs(ll x) {
    cmp[x] = cmpid;
    inCmp[cmpid].push_back(x);
    vlcmp[cmpid] += vl[x];
    for(auto v : rady[x])
        if(! cmp[v])
            rdfs(v);
}
 
void dfs(ll x) {
    vis[x] = 1;
    for(auto v : ady[x])
        if(! vis[v])
            dfs(v);
    s.push(x);
}
 
void toposort() {
    N = cmpid;
    queue < ll > q;
    for(ll i = 1; i <= N; i ++)
        if(! in[i]) {
            q.push(i);
            bst[i] = vlcmp[i]; 
        }
        
    while(! q.empty()) {
        ll x = q.front();
        q.pop();
        ans = max(ans, bst[x]);
        for(auto v : adycmp[x]) {
            in[v]--;
            bst[v] = max(bst[v], bst[x] + vlcmp[v]);
            if(! in[v]) 
                q.push(v);
        }
    }
}
 
 
int main()
{
    optimiza_io
    cin >> N >> M;
    
    for(ll i = 1; i <= N; i ++)
        cin >> vl[i];    
        
    while(M --) {
        ll u, v;
        cin >> u >> v;
        ady[u].push_back(v);
        rady[v].push_back(u);
    }
    
    for(ll i = 1; i <= N; i ++)
        if(! vis[i])
            dfs(i);
        
    while(! s.empty()) {
        ll x = s.top();
        s.pop();
        if(cmp[x])
            continue;
        cmpid++;
        rdfs(x);
    }
    
    for(ll i = 1; i <= N; i ++)
        for(auto v : ady[i])
            if(cmp[i] != cmp[v]) {
                adycmp[cmp[i]].push_back(cmp[v]);
                in[cmp[v]]++;
            }
    
    // TOPOSORT
    toposort();
    
    cout << ans;
    return 0;
}