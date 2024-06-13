//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 200005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
struct flowEdge {
    int u, v;
    long long cap, flow = 0;
    flowEdge(int u, int v, long long cap) : v(v), u(u), cap(cap) {}
    
};
 
const long long flow_inf = 1e18;
vector < flowEdge > edges;
vector < int > ady[MAX];
int N, M, S, T, idx, ptr[MAX];
int level[MAX];
queue < int > q;
 
bool bfs() {
    while(! q.empty()) {
        int u = q.front();
        q.pop();
        for(auto id : ady[u]) {
            if(edges[id].cap <= edges[id].flow)
                continue;
            if(level[edges[id].v] != -1)
                continue;
            level[edges[id].v] = level[u] + 1;
            q.push(edges[id].v);
        }
    }
    return level[T] != -1;
}
 
long long dfs(int u, long long pushed) {
    if(! pushed)
        return 0;
    if(u == T)
        return pushed;
    while(ptr[u] < ady[u].size()) {
        int id = ady[u][ptr[u]];
        int v = edges[id].v;
        if(level[u] + 1 != level[v] or edges[id].cap <= edges[id].flow) {
            ptr[u]++;
            continue;
        }
        long long tr = dfs(v, min(pushed, edges[id].cap - edges[id].flow));
        if(tr) {
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        ptr[u]++;
    }
    return 0;
}
 
 
long long flow() {
    long long f = 0;
    while(1) {
        // RESET LEVEL
        for(int i = 1; i <= N; i ++)
            level[i] = -1;
            
        level[S] = 0;
        q.push(S);
        if(! bfs()) 
            break;
            
        // RESET PTR
        for(int i = 1; i <= N; i ++)
            ptr[i] = 0;
            
        while(long long pushed = dfs(S, flow_inf))  
            f += pushed;
    }
    return f;
}
 
void add_edge(int u, int v, long long cap) {
    edges.emplace_back(u, v, cap);
    edges.emplace_back(v, u, 0LL); // cap for bidir
    ady[u].push_back(idx++);
    ady[v].push_back(idx++);
}
 
void dfsPath(int x, vector < int > & v) {
    v.push_back(x);
    if(x == N)
        return;
    for(auto id : ady[x])
        if(edges[id].flow == 1) {
            dfsPath(edges[id].v, v);
            edges[id].flow = 0;
            break;
        } 
}
 
 
int main()
{
    optimiza_io
    cin >> N >> M;
    while(M --) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v, 1);
    }
    S = 1;
    T = N;
    
    int ans = flow();
    cout << ans << "\n";
    while(ans --) {
        vector < int > path;
        dfsPath(1, path);
        cout << path.size() << "\n";
        for(auto v : path)
            cout << v << " ";
        cout << "\n";
    }
    
    return 0;
}