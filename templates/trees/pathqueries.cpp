//  Copyright © 2020 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 200005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
template<class T>inline bool read(T &x){
    int c=getchar();int sgn=1;
    while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}
    for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0';
    x*=sgn; return ~c;
}
 
ll N, Q, tim;
ll vl[MAX], in[MAX], out[MAX], bit[MAX];
vector <ll> ady[MAX];
 
void upd(ll x , ll v) {
    for(ll i = x; i <= N; i += i & -i)
        bit[i] += v;
}
 
ll qry(ll x) {
    ll ans = 0;
    for(ll i = x; i > 0; i -= i & -i)
        ans += bit[i];
    return ans;
}
 
void dfs(ll x , ll p) {
    in[x] = ++tim;
    for(auto v : ady[x])
        if(v != p)
            dfs(v , x);
    out[x] = tim;
}
 
int main() {
    optimiza_io
    read(N);
    read(Q);
    for(ll i = 1; i <= N; i ++)
        read(vl[i]);
    
    for(ll i = 1; i < N; i ++) {
        ll u, v;
        read(u); read(v);
        ady[u].push_back(v);
        ady[v].push_back(u);
    }
    
    dfs(1 , 0);
    for(ll i = 1; i <= N; i ++) {
        upd(in[i] , vl[i]);
        upd(out[i] + 1 , -vl[i]);
    }
    
    while(Q --) {
        ll t, x, s;
        read(t);
        if(t == 2) {
            read(s);
            cout << qry(in[s]) << "\n";
        }
        else {
            read(s); read(x);
            upd(in[s] , - vl[s]);
            upd(out[s] + 1 , vl[s]);
            vl[s] = x;
            upd(in[s] , vl[s]);
            upd(out[s] + 1 , -vl[s]);
        }
    }
    return 0;
}
 
// CHECAR LIMITES 