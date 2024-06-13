//  Copyright © 2020 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 200005
#define pii pair < ll, ll > 
#define ht first
#define wt second
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
ll N, ans;
stack < pii > s;
 
int main()
{
    optimiza_io
    cin >> N;
    for(ll i = 1; i <= N; i ++) {
        pii x;
        cin >> x.ht;
        x.wt = 1;
        ans = max(ans, x.ht);
        int ext = 0;
        while(! s.empty() && s.top().ht >= x.ht) {
            ext += s.top().wt;
            ans = max(ans, s.top().ht * ext);
            s.pop();
        }            
        x.wt += ext;
        s.push(x);
    }
    while(! s.empty()) {
        pii x = s.top(); s.pop();
        ans = max(ans, x.ht * x.wt);
        if(! s.empty()) {
            pii y = s.top(); s.pop();
            y.wt += x.wt;
            s.push(y);
        }
    }
    
    cout << ans << "\n";
    return 0;
}
 
// CHECAR LIMITES 