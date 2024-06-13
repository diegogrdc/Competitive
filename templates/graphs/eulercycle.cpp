//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 300005
#define pii pair < int, int > 
#define fi first
#define se second
using namespace std;
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
typedef long long ll;
 
 
vector < pii > ady[MAX];
vector < int > euler;
int N, M, ini;
int in[MAX];
bool used[MAX];
 
void dfs(ll x)
{
    while(! ady[x].empty())
    {
        pii v = ady[x][ady[x].size() - 1];
        if(! used[v.se]) {
            ady[x].pop_back();
            used[v.se] = 1;
            dfs(v.fi);
        }
        else
            ady[x].pop_back();
    }
    euler.push_back(x);
}
 
 
int main()
{
    optimiza_io 
    cin >> N >> M;
    for(int i = 1; i <= M; i ++) {
        int a, b;
        cin >> a >> b;
        ady[a].push_back({ b, i });
        ady[b].push_back({ a, i });
        in[b]++;
        in[a]++;
    }
    
    for(int i = 1; i <= N; i ++)
        if(in[i] & 1) {
        cout << "IMPOSSIBLE\n";
        exit(0);
    } 
    
    dfs(1);
    
    if(euler.size() != M+1) {
        cout << "IMPOSSIBLE\n";
        exit(0);
    }
    
    for(auto x : euler)
        cout << x << " ";
    return 0;
}