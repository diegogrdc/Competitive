//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 10
#define pii pair < int, int >
#define fi first
#define se second
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
const int N = 8;
int m[8][2]{{1,2},{2,1},{-1,2},{2,-1},{-2,1},{1,-2},{-1,-2},{-2,-1}};
int pos[MAX][MAX];
bool vis[MAX][MAX];
int ans[MAX][MAX];
vector < pii > movs[MAX][MAX];
 
bool cmp(pii a, pii b) {
    return pos[a.fi][a.se] <= pos[b.fi][b.se];
}
 
 
void dfs(int x, int y, int p) {
    vis[x][y] = 1;
    ans[x][y] = p;
    if(p == N*N) {
        for(int i = 1; i <= N; i ++)
            for(int j = 1; j <= N; j ++)
                cout << ans[i][j] << " \n"[j == N];
                
        exit(0);
    } 
            
    for(int k = 0; k < 8; k ++) {
        int xx = x + m[k][0];
        int yy = y + m[k][1];
        if(xx >= 1 && xx <= N && yy >= 1 && yy <= N)
            pos[xx][yy]--;
    }
    
    sort(movs[x][y].begin(), movs[x][y].end(), cmp);
            
    for(auto v : movs[x][y]) 
        if(! vis[v.fi][v.se]) {
            dfs(v.fi, v.se, p + 1);
        }
        
    vis[x][y] = 0;   
    ans[x][y] = 0;
    
    for(int k = 0; k < 8; k ++) {
        int xx = x + m[k][0];
        int yy = y + m[k][1];
        if(xx >= 1 && xx <= N && yy >= 1 && yy <= N)
            pos[xx][yy]++;
    }
}
 
int main()
{
    optimiza_io
    for(int i = 1; i <= N; i ++)
        for(int j = 1; j <= N; j ++) 
            for(int k = 0; k < 8; k ++) {
                int x = i + m[k][0];
                int y = j + m[k][1];
                if(x >= 1 && x <= N && y >= 1 && y <= N) {
                    pos[i][j]++;
                    movs[i][j].push_back({ x, y });
                }
            }
        
    int inx, iny;
    cin >> inx >> iny;
    dfs(iny, inx, 1);
    return 0;
    
}