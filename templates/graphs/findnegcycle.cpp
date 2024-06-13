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
 
ll N, M, lst;
edge e[MAX];
ll dist[MAX], pre[MAX];
 
void bellmanford() {
    
    for(ll i = 1; i <= N; i ++) 
        dist[i] = INF;
    
    for(ll i = 1; i <= N; i ++) {
        lst = -1;
        for(ll j = 1; j <= M; j ++) {
            edge x = e[j];
            if(dist[x.u] + x.w < dist[x.v]) {
                dist[x.v] = dist[x.u] + x.w;
                pre[x.v] = x.u;
                lst = x.v;
            } 
        }
    }
    
    if(lst == -1) {
        cout << "NO\n";
        exit(0);
    }
    
    for (ll i = 0; i < N; i++)
            lst = pre[lst];
            
    vector < ll > cyc;
    for(ll i = lst; ; i = pre[i]) {
        cyc.push_back(i);
        if(i == lst && cyc.size() > 1)
            break;
    }
    reverse(cyc.begin(), cyc.end());
    cout << "YES\n";
    for(auto v : cyc)
        cout << v << " ";
    
}
 
int main()
{
    optimiza_io
    cin >> N >> M;
    for(ll i = 1; i <= M; i ++) 
        cin >> e[i].u >> e[i].v >> e[i].w;
    
    bellmanford();
    return 0;
}