//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 5005
#define INF 1e18
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
struct edge {
    ll u, v, w;
};
 
ll N, M;
edge e[MAX];
ll dist[MAX];
bool augment[MAX];
 
ll bellmanford(ll src) {
    
    dist[src] = 0; 
    for(ll i = 1; i < N; i ++) 
        for(ll j = 1; j <= M; j ++) {
            edge x = e[j];
            if(dist[x.u] + x.w < dist[x.v])
                dist[x.v] = dist[x.u] + x.w;
        }
   
 
    return dist[N];
}
 
 
int main()
{
    optimiza_io
    cin >> N >> M;
    for(ll i = 1; i <= M; i ++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
        e[i].w *= -1;
    }
    
    for(ll i = 1; i <= N; i ++) 
        dist[i] = INF;
    
    
    ll ans = bellmanford(1);
    
    for(ll i = 1; i < N; i ++) 
        for(ll j = 1; j <= M; j ++) {
            edge x = e[j];
            if(dist[x.u] + x.w < dist[x.v])
                e[j].w = -1e9;
        }
    
    ll ans2 = bellmanford(1);
    if(ans != ans2) {
        cout << "-1\n";
        exit(0);
    }
    
    
    cout << ans * -1 << "\n";
    return 0;
}