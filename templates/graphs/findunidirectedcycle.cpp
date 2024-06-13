//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 200005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
int N, M, lim;
bool f;
vector < int > ans;
vector < int > ady[MAX];
bool vis[MAX];
 
void end() {
    cout << ans.size() << "\n";
    for(auto v : ans)
        cout << v << " ";
    cout << "\n";
    exit(0);
}
 
void dfs(int x, int p) {
    vis[x] = 1;
    for(auto v : ady[x])
        if(v != p) {
            if(vis[v]) {
                lim = v;
                f = 1;
                ans.push_back(v);
                ans.push_back(x);
                return;
            }
            dfs(v, x);
            if(f) {
                ans.push_back(x);
                if(x == lim)
                    end();
                return;
            }
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
            
    cout << "IMPOSSIBLE\n";
    return 0;
}