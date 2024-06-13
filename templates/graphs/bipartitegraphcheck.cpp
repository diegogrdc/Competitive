//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 200005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
int N, M;
vector < int > ady[MAX];
int team[MAX];
bool vis[MAX];
 
void fail() { cout << "IMPOSSIBLE\n"; exit(0); }
 
void dfs(int x, int t) {
    vis[x] = 1;
    team[x] = t + 1;
    for(auto v : ady[x]) {
        if(vis[v] && team[v] == team[x]) 
            fail();
        if(! vis[v])
            dfs(v, t ^ 1);
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
    
    for(int i = 1; i <= N; i ++)
        if(! vis[i])
            dfs(i, 0);
    
    for(int i = 1; i <= N; i ++)
        cout << team[i] << " ";
    return 0;
}