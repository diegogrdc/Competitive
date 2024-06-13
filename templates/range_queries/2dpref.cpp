//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 1005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
int N, M, Q;
char vals[MAX][MAX];
int sum[MAX][MAX];
 
int getSum(int l1, int r1, int l2, int r2) {
    return sum[l2][r2] - sum[l2][r1 - 1] - sum[l1 - 1][r2] + sum[l1 - 1][r1 - 1];
}
 
int main() {
    optimiza_io
    cin >> N >> Q;
    M = N;
    for(int i = 1; i <= N; i ++)
        for(int j = 1; j <= M; j ++)
            cin >> vals[i][j];
    
    for(int i = 1; i <= N; i ++)
        for(int j = 1; j <= M; j ++)
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (vals[i][j] == '*');
    
    while(Q --) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        cout << getSum(l1, r1, l2, r2) << "\n";
    }
    
    return 0;
}