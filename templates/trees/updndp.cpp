//  Copyright © 2020 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 200005
#define pii pair < ll , ll >
#define fi first
#define se second
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
ll N, dn[MAX], sz[MAX];
ll ans[MAX];
vector < ll > ady[MAX];
 
void dfs(ll x , ll p) {
    sz[x] = 1;
    for(auto v : ady[x])
        if(v != p) {
            dfs(v , x);
            sz[x] += sz[v];
            dn[x] += dn[v] + sz[v];
        }
}
 
void dfs2(ll x , ll p , ll up) {
    ans[x] = dn[x] + up;
            
    for(auto v : ady[x]) 
        if(v != p)
            dfs2(v , x , up + dn[x] - dn[v] + N - 2 * sz[v]);
}
 
int main() {
    optimiza_io
    cin >> N;
    for(ll i = 1; i < N; i ++) {
        ll u, v;
        cin >> u >> v;
        ady[u].push_back(v);
        ady[v].push_back(u);
    }
    
    dfs(1 , 0);
    dfs2(1 , 0 , 0);
    for(ll i = 1; i <= N; i ++)
        cout << ans[i] << " ";
        
    return 0;
}
 
// CHECAR LIMITES 