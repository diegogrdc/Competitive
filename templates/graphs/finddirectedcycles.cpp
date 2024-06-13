//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 200005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
int N, M;
vector < int > ady[MAX];
bool vis[MAX];
bool inStack[MAX];
int pre[MAX];
vector < int > ans;
 
void dfs(int x, int p) {
    vis[x] = 1;
    pre[x] = p;
    inStack[x] = 1;
    for(auto v : ady[x]) {
        if(vis[v] && inStack[v]) {
            ans.push_back(v);
            for(int i = x;; i = pre[i]) {
                ans.push_back(i);
                if(i == v)
                    break;
            }
            reverse(ans.begin(), ans.end());
            cout << ans.size() << "\n";
            for(auto t : ans)
                cout << t << " ";
            exit(0);
        }
        else if(! vis[v])
            dfs(v, x);
    }
    inStack[x] = 0;
}
 
int main()
{
    optimiza_io
    cin >> N >> M;
    while(M --) {
        int a, b;
        cin >> a >> b;
        ady[a].push_back(b);
    }
    
    for(int i = 1; i <= N; i ++)
        if(! vis[i]) 
            dfs(i, 0);
    
    cout << "IMPOSSIBLE\n";
    return 0;
}