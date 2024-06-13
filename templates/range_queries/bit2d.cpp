//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 1005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
int N, M, Q;
int vals[MAX][MAX];
int bit[MAX][MAX];
 
void add(int x, int y, int v) {
    for(int i = x; i <= N; i += i & -i)
        for(int j = y; j <= M; j += j & -j) 
            bit[i][j] += v;
}
 
int qry(int x, int y) {
    int ans = 0;
    for(int i = x; i > 0; i -= i & -i)
        for(int j = y; j > 0; j -= j & -j)   
            ans += bit[i][j];
    
    return ans;
}
 
int sum(int x1, int y1, int x2, int y2) {
    return qry(x2, y2) - qry(x1 - 1, y2) - qry(x2, y1 - 1) + qry(x1 - 1, y1 - 1);
}
 
int main()
{
    optimiza_io
    cin >> N >> Q;
    M = N;
    for(int i = 1; i <= N; i ++) 
        for(int j = 1; j <= M; j ++) {
            char x;
            cin >> x;
            vals[i][j] = (x == '*' ? 1 : 0);
            add(i, j, vals[i][j]);
        }
        
    
    while(Q --) {
        int t, x1, x2, y1, y2;
        cin >> t >> x1 >> y1;
        if(t == 1) {
            add(x1, y1, - vals[x1][y1]);
            vals[x1][y1] = ! vals[x1][y1];
            add(x1, y1, vals[x1][y1]);
        }
        else {
            cin >> x2 >> y2;
            cout << sum(x1, y1, x2, y2) << "\n";
        }
    }
        
    return 0;
}