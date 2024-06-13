//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 200005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
int N, M;
int dist[MAX];
bool vis[MAX];
vector < int > ady[MAX];
void bfs(int ini)
{
    queue < int > q;
    q.push(ini);
    vis[ini] = 1;
    dist[ini] = 1;
    while(! q.empty())
    {
        int x = q.front();
        q.pop();
        for(auto v : ady[x])
        {
            if(vis[v])
                continue;
            vis[v] = 1;
            dist[v] = dist[x] + 1;
            q.push(v);
        }
    }
}
 
void backtrack(int x) {
    if(x == 1) {
        cout << "1 ";
        return;
    }
    for(auto v : ady[x])
        if(dist[v] == dist[x] - 1) {
            backtrack(v);
            cout << x << " ";
            return;
        }
}
 
int main()
{
    optimiza_io
    cin >> N >> M;
    while(M --) {
        int a, b;
        cin >> a >> b;
        ady[a].push_back(b);
        ady[b].push_back(a);
    }
    
    bfs(1);
    if(! vis[N]) {
        cout << "IMPOSSIBLE\n";
        exit(0);
    }
    
    cout << dist[N] << "\n";
    backtrack(N);
    return 0;
}