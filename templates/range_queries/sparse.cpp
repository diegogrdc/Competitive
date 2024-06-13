//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 200005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
// LOG MUST BE EXACT OR SMALLER
// IF BIGGER -> OVERFLOW
 
const int LOG = 17;
int N, Q;
int tam[MAX], a[MAX];
int men[MAX][LOG + 1];
int may[MAX][LOG + 1];
 
void doSparse() {
    for(int i = 2; i <= N; i ++)
            tam[i] = tam[i / 2] + 1;
        
    for(int i = 1; i <= N; i ++)
        men[i][0] = may[i][0] = a[i];
      
    for(int j = 1; j <= LOG; j ++)  
        for(int i = 1; i + (1 << j) <= N+1; i ++)
        {
            men[i][j] = min(men[i][j - 1], men[i + (1 << (j - 1))][j - 1]);
            may[i][j] = max(may[i][j - 1], may[i + (1 << (j - 1))][j - 1]);
        }
    
}
 
int getMin(int l, int r) {
    int j = tam[r - l + 1];
    return min(men[l][j], men[r - (1 << j) + 1][j]);
}
 
int getMax(int l, int r) {
    int j = tam[r - l + 1];
    return max(may[l][j], may[r - (1 << j) + 1][j]);
}
 
 
int main()
{
    optimiza_io
    cin >> N >> Q;
    for(int i = 1; i <= N; i ++)
        cin >> a[i];
        
    doSparse();
    
    while(Q --) {
        int l, r;
        cin >> l >> r;
        cout << getMin(l, r) << "\n";
    }
    return 0;
}