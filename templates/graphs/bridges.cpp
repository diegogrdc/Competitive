//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 200005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
int N, M, idx, cnt;
vector < int > ady[MAX];
int disc[MAX], low[MAX], cmp[MAX];
bool inStack[MAX];
stack < int > s;
 
void dfs(int x) {
    disc[x] = ++idx;
    low[x] = idx;
    s.push(x);
    inStack[x] = 1;
    for(auto v : ady[x]) {
        if(! disc[v]) {
            dfs(v);
            low[x] = min(low[x], low[v]);
        }
        else if(inStack[v])
            low[x] = min(low[x], disc[v]);
    }
    if(low[x] == disc[x]) {
        cnt++;
        while(1) {
            int t = s.top();
            s.pop();
            inStack[t] = 0;
            cmp[t] = cnt;
            if(x == t)
                break;
        }
    }
}
 
int main()
{
    optimiza_io
    cin >> N >> M;
    while(M --) {
        int u, v;
        cin >> u >> v;
        ady[u].push_back(v);
    }
    
    for(int i = 1; i <= N; i ++)
        if(! cmp[i])
            dfs(i);
            
    cout << cnt << "\n";
    for(int i = 1; i <= N; i ++)
        cout << cmp[i] << " ";
    return 0;
}