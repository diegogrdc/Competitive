//  Copyright © 2020 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 10
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
ll N, X;
ll a[MAX][MAX], ans[MAX][MAX], tmp[MAX][MAX];
const ll MOD = 1e9 + 7;
 
void mulmat(ll C[][MAX], ll A[][MAX], ll B[][MAX]) {
    for(ll i = 1; i <= N; i ++)
        for(ll j = 1; j <= N; j ++)
            for(ll k = 1; k <= N; k ++) 
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
}
 
void cpymat(ll A[][MAX], ll B[][MAX]) {
    for(ll i = 1; i <= N; i ++)
        for(ll j = 1; j <= N; j ++)
            A[i][j] = B[i][j];
}
 
void initmat(ll A[][MAX], ll x) {
    for(ll i = 1; i <= N; i ++)
        for(ll j = 1; j <= N; j ++)
            A[i][j] = x;
}
 
void printmat(ll A[][MAX]) {
    for(ll i = 1; i <= N; i ++)
        for(ll j = 1; j <= N; j ++)
            cout << A[i][j] << " \n"[j == N];
}
 
void fastpowmat(ll A[][MAX], ll N) {
    ll x = 1;
    while(x <= N) {
        if(x & N) {
            initmat(tmp, 0);
            mulmat(tmp, ans, a);
            cpymat(ans, tmp);
        }
        x *= 2;
        initmat(tmp, 0);
        mulmat(tmp, a, a);
        cpymat(a, tmp);
    }
}
 
 
 
int main()
{
    optimiza_io
    cin >> X;
    N = 6;
    for(int i = 1; i <= N; i ++)
        a[i][i + 1] = 1;
    
    // LAST ROW OF MATRIX
    for(int i = 1; i <= N; i ++)
        a[N][i] = 1;
    
    initmat(ans, 1);
    fastpowmat(a, X);
    cout << ans[1][1] << "\n";
    return 0;
}
 
// CHECAR LIMITES 
 
 
/*
 
f(1)=1
f(2)=2
f(3)=
*/