//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 505
#define INF 1e17
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
ll N, M, Q;
ll ady[MAX][MAX];
 
int main()
{
    optimiza_io
    cin >> N >> M >> Q;
    for(ll i = 1; i <= N; i ++)
        for(ll j = 1; j <= N; j ++)
            if(i != j)
                ady[i][j] = INF;
    
    while(M --) {
        ll a, b, c;
        cin >> a >> b >> c;
        ady[a][b] = min(ady[a][b], c);
        ady[b][a] = min(ady[a][b], c);
    }
    
    // FLOYD
    for(ll k = 1; k <= N; k ++)
        for(ll i = 1; i <= N; i ++)
            for(ll j = 1; j <= N; j ++)
                ady[i][j] = min(ady[i][j], ady[i][k] + ady[k][j]);
    
    while(Q --) {
        ll a, b;
        cin >> a >> b;
        cout << (ady[a][b] == INF ? -1 : ady[a][b]) << "\n";
    }
    return 0;
}