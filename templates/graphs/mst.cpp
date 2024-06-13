//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 200005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
struct edge {
    ll u, v, c;
    bool operator < (const edge & a) const {
        return c < a.c;
    }
};
 
ll id[MAX], ans;
 
ll find(ll x){ return id[x] == x ? x : (id[x] = find(id[x])); }
 
void merge(ll a, ll b, ll c)
{
    a = find(a);
    b = find(b);
    if(a == b)
        return;
    ans += c;
    id[a] = b;
}
 
ll N, M;
edge e[MAX];
 
 
int main()
{
    optimiza_io
    cin >> N >> M;
    for(ll i = 1; i <= M; i ++)
        cin >> e[i].u >> e[i].v >> e[i].c;
    
    for(ll i = 1; i <= N; i ++)
        id[i] = i;
        
    sort(e + 1, e + M + 1);
    for(ll i = 1; i <= M; i ++)
        merge(e[i].u, e[i].v, e[i].c);
    
    for(int i = 2; i <= N; i ++)
        if(find(i) != find(1)) {
            cout << "IMPOSSIBLE\n";
            exit(0);
        }
    
    cout << ans;
    return 0;
}