//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 200005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
int N, M, cmpid;
vector < int > ady[MAX], rady[MAX];
bool vis[MAX];
stack < int > s;
int cmp[MAX];
vector < int > c[MAX];
 
void rdfs(int x) {
    cmp[x] = cmpid;
    c[cmpid].push_back(x);
    for(auto v : rady[x])
        if(! cmp[v])
            rdfs(v);
}
 
void dfs(int x) {
    vis[x] = 1;
    for(auto v : ady[x])
        if(! vis[v])
            dfs(v);
    s.push(x);
}
 
 
int main()
{
    optimiza_io
    cin >> N >> M;
    while(M --) {
        int u, v;
        cin >> u >> v;
        ady[u].push_back(v);
        rady[v].push_back(u);
    }
    
    for(int i = 1; i <= N; i ++)
        if(! vis[i])
            dfs(i);
        
    while(! s.empty()) {
        int x = s.top();
        s.pop();
        if(cmp[x])
            continue;
        cmpid++;
        rdfs(x);
    }
    
    return 0;
}