//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 200005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
vector < int > ady[MAX];
int N, M, match[MAX], dist[MAX], Q;
 
bool bfs() {
    queue < int > q;
    for(int i = 1; i <= N; i ++) {
        dist[i] = -1;
        if(! match[i]) {
            dist[i] = 0;
            q.push(i);
        }
    }
    
    dist[0] = -1;
    while(! q.empty()) {
        int u = q.front();
        q.pop();
        if(u) {
            for(auto v : ady[u]) 
                if(dist[match[v]] == -1) {
                    dist[match[v]] = dist[u] + 1;
                    q.push(match[v]);
                    
                }
        }
    }
    
    return dist[0] != -1;
}
 
bool dfs(int u) {
    if(! u)
        return true;
        
    for(auto v : ady[u])
        if(dist[match[v]] == dist[u] + 1) 
            if(dfs(match[v])) {
                match[v] = u;
                match[u] = v;
                return true;
            }
        
    dist[u] = -1;
    return false;
}
 
 
int bipartite_match() {
    int ans = 0;
    while(bfs()) {
        for(int i = 1; i <= N; i ++)
            if(! match[i] && dfs(i))
                ans++;
    }
    return ans;
}
 
int main()
{
    optimiza_io
    cin >> N >> M >> Q;
    while(Q --) {
        int a, b;
        cin >> a >> b;
        ady[a].push_back(b + N);
    }
    
    cout << bipartite_match() << "\n";
    for(int i = 1; i <= N; i ++)
        if(match[i])
            cout << i << " " << match[i] - N << endl;
    return 0;
}