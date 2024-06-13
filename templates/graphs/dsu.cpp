//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 200005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
int N, M, ans;
int id[MAX];
 
int find(int x)
{
    if(id[x] == x)
        return x;
    return id[x] = find(id[x]);
}
 
void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if(a == b)
        return;
    id[a] = b;
    ans--;
}
 
 
int main()
{
    optimiza_io
    cin >> N >> M;
    ans = N;
    for(int i = 1; i <= N; i ++)
        id[i] = i;
        
    while(M --) {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }
    
    cout << ans - 1 << "\n";
    for(int i = 2; i <= N; i ++)
        if(find(1) != find(i)) {
            cout << "1 " << i << "\n";
            merge(1, i);
        }
    return 0;
}