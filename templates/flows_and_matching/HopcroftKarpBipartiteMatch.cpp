//  Copyright © 2021 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 1005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
#define what_is(x) cerr << #x << " is " << x << endl;
#define pii pair <int, int>
#define fi first
#define se second
using namespace std;
typedef long long ll;

const int NIL = 0;
const int INF = 1e9;
int N, M;
int mu[MAX], mv[MAX];
vector<int> ady[MAX];
int dist[MAX];

bool bfs() {
    queue<int> q;
    for(int u = 1; u <= N; u ++) {
        if(mu[u] == NIL) {
            dist[u] = 0;
            q.push(u);
        } else 
            dist[u] = INF;
    }
    dist[NIL] = INF;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        if(dist[u] < dist[NIL]) {
            for(auto v : ady[u])
                if(dist[mv[v]] == INF) {
                    dist[mv[v]] = dist[u] + 1;
                    q.push(mv[v]);
                }
        }
    }
    return dist[NIL] != INF;
}

bool dfs(int u) {
    if(u != NIL) {
        for(auto v : ady[u])
            if(dist[mv[v]] == dist[u] + 1)
                if(dfs(mv[v])) {
                    mv[v] = u;
                    mu[u] = v;
                    return true;
                }
        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroftKarp() {
    for(int i = 1; i <= N; i ++)
        mu[i] = NIL;
    for(int i = 1; i <= M; i ++)
        mv[i] = NIL; 
    int match = 0;
    while(bfs()) {
        for(int i = 1; i <= N; i ++) 
            if(mu[i] == NIL)
                if(dfs(i))
                    match++;
    }
    return match;
}
 
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    optimiza_io
    int K;
    cin >> N >> M >> K;
    while(K--) {
        int u, v;
        cin >> u >> v;
        ady[u].push_back(v);
    }
    cout << hopcroftKarp() << "\n";
    for(int i = 1; i <= N; i ++)
        cout << mu[i] << "\n";
    return 0;
}
 
// CHECAR LIMITES 