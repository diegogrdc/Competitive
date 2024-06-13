//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 1005
#define pii pair < int, int >
#define fi first
#define se second
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
int N, M, ans;
char a[MAX][MAX];
int m[4][2]{{0,1},{1,0},{-1,0},{0,-1}};
bool vis[MAX][MAX];
 
void bfs(int ix, int iy)
{
    queue < pii > q;
    q.push({ ix, iy });
    vis[ix][iy] = 1;
    while(! q.empty())
    {
        pii n = q.front();
        q.pop();
        for(int i = 0; i < 4; i ++)
        {
            int mx = n.fi + m[i][0];
            int my = n.se + m[i][1];
            if(! mx or ! my or mx > N or my > M)
                continue;
            if(vis[mx][my] or a[mx][my] == '#')
                continue;
            vis[mx][my] = 1;
            q.push({ mx, my });
        }
    }
}
 
int main()
{
    optimiza_io
    cin >> N >> M;
    for(int i = 1; i <= N; i ++)
        for(int j = 1; j <= M; j ++)
            cin >> a[i][j];
    
    for(int i = 1; i <= N; i ++)
        for(int j = 1; j <= M; j ++)
            if(! vis[i][j] && a[i][j] == '.') {
                ans++;
                bfs(i, j);
            }
    cout << ans;
    return 0;
}