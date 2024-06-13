//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 200005
#define INF 1e9
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
// CHECK INF
 
int N, Q, vals[MAX];
int tree[MAX*8];
 
void initTree(int x, int l, int r) {
    if(l == r) {
        tree[x] = 1;
        return;
    }
    
    int mid = (l + r) / 2;
    initTree(2*x+1, l, mid);
    initTree(2*x+2, mid+1, r);
    tree[x] = tree[2*x+1] + tree[2*x+2];
}
 
void upd(int x, int l, int r, int q, int v) {
    if(l > q or r < q)
        return;
    if(l == r) {
        tree[x] = v;
        return;
    }
    
    int mid = (l + r) / 2;
    upd(2*x+1, l, mid, q, v);
    upd(2*x+2, mid+1, r, q, v);
    tree[x] = tree[2*x+1] + tree[2*x+2];
}
 
int leftmost(int x, int l, int r, int q) {
    
    if(tree[x] < q)
        return 0;
    if(l == r)
        return l;
    
    int mid = (l + r) / 2;
    int ans = leftmost(2*x+1, l, mid, q);
    if(ans)
        return ans;
    return leftmost(2*x+2, mid+1, r, q - tree[2*x+1]);
}
 
 
 
 
int main()
{
    optimiza_io
    cin >> N;
    for(int i = 1; i <= N; i ++)
        cin >> vals[i];
    
    initTree(0, 1, N);
    
    for(int i = 1; i <= N; i ++) {
        int p;
        cin >> p;
        int ans = leftmost(0, 1, N, p);
        cout << vals[ans] << " "; 
        upd(0, 1, N, ans, 0);
        
    }
    
    return 0;
}