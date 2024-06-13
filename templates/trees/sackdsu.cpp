//  Copyright © 2020 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 200005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
int N, sz[MAX], cur;
vector < int > ady[MAX];
int cl[MAX];
unordered_map < int, int > cnt;
int ans[MAX];
 
void getsz(int x, int p) {
    sz[x] = 1;
    for(auto v : ady[x])
        if(v != p)
            getsz(v, x), sz[x] += sz[v];
}
 
void turn(int x, bool on) {
    // This is problem specific 
    if(on) {
        if(! cnt[cl[x]]) 
            cur++;
        cnt[cl[x]]++;
    }
    else {
        cnt[cl[x]]--;
        if(! cnt[cl[x]])
            cur--;
    }
}
 
void filldfs(int x, int p, bool on) {
    if(on)
        turn(x, 1);
    else 
        turn(x, 0);
    for(auto v : ady[x])
        if(v != p)
            filldfs(v, x, on);
}
 
void dfs(int x, int p, bool keep) {
    int mx = -1, big = -1;
    for(auto v : ady[x])
        if(v != p && sz[v] > mx)
            mx = sz[v], big = v;
    
    for(auto v : ady[x])
        if(v != p && v != big)
            dfs(v, x, 0);
    
    if(big != -1)
        dfs(big, x, 1);
    
    for(auto v : ady[x])
        if(v != p && v != big)
            filldfs(v, x, 1); 
    
    turn(x, 1);
    ans[x] = cur;
    if(! keep)
        filldfs(x, p, 0);
}
 
int main() {
    optimiza_io
    cin >> N;
    for(int i = 1; i <= N; i ++)
        cin >> cl[i];
    
    for(int i = 1; i < N; i ++) {
        int u, v;
        cin >> u >> v;
        ady[u].push_back(v);
        ady[v].push_back(u);
    }
    
    getsz(1, 0);
    dfs(1, 0, 1);
    for(int i = 1; i <= N; i ++)
        cout << ans[i] << " ";
    return 0;
}
 
// CHECAR LIMITES 