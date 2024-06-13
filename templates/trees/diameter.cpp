//  Copyright © 2020 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 200005
#define pii pair < int , int >
#define fi first
#define se second
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long i64;
 
int N, dist;
vector < int > ady[MAX];
bool vis[MAX];
 
int bfs(int x) {
    memset(vis , 0 , sizeof vis);
    queue < pii > q;
    q.push({ x , 0 });
    vis[x] = 1;
    while(! q.empty()) {
        pii n = q.front();
        x = n.fi;
        dist = n.se;
        q.pop();
        for(auto v : ady[n.fi])
            if(! vis[v]) {
                q.push({ v , dist + 1 });
                vis[v] = 1;
            }
    }
    return x;
}
 
int main() {
    optimiza_io
    cin >> N;
    for(int i = 1; i < N; i ++) {
        int u, v;
        cin >> u >> v;
        ady[u].push_back(v);
        ady[v].push_back(u);
    }
    
    int x = bfs(1);
    x = bfs(x);
    
    cout << dist << "\n";
    return 0;
}
 
// CHECAR LIMITES 