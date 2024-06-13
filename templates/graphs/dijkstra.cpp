//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 200005
#define pii pair < ll, ll >
#define fi first
#define se second
#define INF 1e9
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
struct node {
    ll x, d;
    bool operator < (const node & a) const {
        return d > a.d;
    }
};
 
ll N, M;
vector < pii > ady[MAX];
ll dist[MAX];
 
void dijkstra(ll ini) {
    
    for(ll i = 1; i <= N; i ++)
        dist[i] = INF;
        
    priority_queue < node > q;
    q.push({ ini, 0 });
    
    while(! q.empty()) {
        node n = q.top();
        q.pop();
        if(dist[n.x] != INF)
            continue;
        dist[n.x] = n.d;
        for(auto v : ady[n.x])
            if(dist[v.fi] == INF)
                q.push({ v.fi, n.d + v.se });
    }
} 
 
int main() {
    optimiza_io
    cin >> N >> M;
    while(M --) {
        ll a, b, c;
        cin >> a >> b >> c;
        ady[a].push_back({ b, c });
    }
    
    dijkstra(1);
    for(ll i = 1; i <= N; i ++)
        cout << dist[i] << " ";
    return 0;
}