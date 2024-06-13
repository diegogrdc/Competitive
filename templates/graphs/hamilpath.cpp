//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 1050005
#define MOD 1000000007
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
int N, M;
bool vis[22][MAX];
int memo[22][MAX];
vector < int > ady[22];
 
int dp(int x, int msk) {
    if(msk == (1 << N) - 1) 
        return x == N-1;
    if((msk & (1 << (N - 1))))
        return 0;
    
    if(vis[x][msk])
        return memo[x][msk];
    
    int ans = 0;
    for(auto v : ady[x])
        if(! (msk & (1 << v)))
            ans = (ans + dp(v, msk | (1 << v))) % MOD;
    vis[x][msk] = 1;
    return memo[x][msk] = ans;
}
 
int main()
{
    optimiza_io
    cin >> N >> M;
    while(M --) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        ady[a].push_back(b);
    }
    
    cout << dp(0, 1) << "\n";
    return 0;
}