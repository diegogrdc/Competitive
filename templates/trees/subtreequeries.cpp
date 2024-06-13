//  Copyright © 2020 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 500005
#define LOG 19
using namespace std;
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
typedef long long ll;
 
int N,tim, Q;
vector < int > ady[MAX];
int papa[MAX][LOG];
int niv[MAX], in[MAX], out[MAX], acm[MAX];
 
void dfs(int x, int n, int p) {
    in[x] = ++tim;
    papa[x][0] = p;
    niv[x] = n;
    for(auto v : ady[x])
        if(v != p)
            dfs(v, n + 1, x);
    out[x] = ++tim;
}
 
int lca(int a, int b) {
    if(niv[a] < niv[b])
        swap(a, b);
    for(int i = LOG - 1; i >= 0; i --)
        if(niv[papa[a][i]] >= niv[b])
            a = papa[a][i];
    
    if(a == b)
        return a;
    
    for(int i = LOG - 1; i >= 0; i --)
        if(papa[a][i] != papa[b][i])
        {
            a = papa[a][i];
            b = papa[b][i];
        }
        
    return papa[a][0];
}
 
int dist(int a, int b) {
    return niv[a] + niv[b] - 2 * niv[lca(a, b)];
}
 
int main() {
    optimiza_io 
    cin >> N >> Q;
    for(int i = 1; i < N; i ++) {
        int u, v;
        cin >> u >> v;
        ady[u].push_back(v);
        ady[v].push_back(u);
    }
    
    dfs(1, 1, 0);
    
    for(int j = 1; j < LOG; j ++)
        for(int i = 1; i <= N; i ++)
            papa[i][j] = papa[ papa[i][j - 1] ][j - 1];
    
    while(Q --) {
        int a, b;
        cin >> a >> b;
        int l = lca(a, b);
        acm[out[a]]++;
        acm[out[b]]++;
        acm[out[l]]--;
        acm[out[l] + 1]--;
    }
    
    for(int i = 1; i <= 2*N; i ++) 
        acm[i] += acm[i - 1];
    
    for(int i = 1; i <= N; i ++)
        cout << acm[out[i]] - acm[in[i]] << " ";
    return 0;
}