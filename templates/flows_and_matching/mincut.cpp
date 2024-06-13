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
bool vis[MAX];
 
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
    edges.emplace_back(v, u, cap); // cap for bidir
    ady[u].push_back(idx++);
    ady[v].push_back(idx++);
}
 
void dfsMinCut(int x) {
    vis[x] = 1;
    for(auto id : ady[x]) {
        if(edges[id].flow < edges[id].cap && ! vis[edges[id].v]) 
            dfsMinCut(edges[id].v);
    }
}
 
 
int main()
{
    optimiza_io
    cin >> N >> M;
    while(M --) {
        int a, b;
        cin >> a >> b;
        add_edge(a, b, 1);
    }
    S = 1;
    T = N;
    cout << flow() << "\n";
    dfsMinCut(S);
    for(int i = 1; i <= N; i ++)
        for(auto id : ady[i])
            if(vis[edges[id].u] && ! vis[edges[id].v])
                cout << edges[id].u << " " << edges[id].v << "\n";
    
    return 0;
}