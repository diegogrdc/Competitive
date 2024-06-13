//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 500005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
int N, M, cnt;
vector < int > ady[MAX], rady[MAX];
stack < int > s;
int comp[MAX];
bool ans[MAX], vis[MAX];
 
void dfs1(int x) {
    vis[x] = 1;
    for(auto v : ady[x])
        if(! vis[v])
            dfs1(v);
    s.push(x);
}
 
void dfs2(int x) {
    comp[x] = cnt;
    for(auto v : rady[x])
        if(! comp[v])
            dfs2(v);
}
 
bool solve_2sat() {
    N = 2*M+1; // NUMBER OF VARIABLES 
    
    for(int i = 2; i <= N; i ++) vis[i] = 0;
    
    for(int i = 2; i <= N; i ++)
        if(! vis[i])
            dfs1(i);
    
    while(! s.empty()) {
        int x = s.top();
        s.pop();
        if(comp[x])
            continue;
        cnt++;
        dfs2(x);
    }
    
    for(int i = 1; i <= N/2; i ++) {
        if(comp[2*i] == comp[2*i+1])
            return false;
        ans[i] = comp[2*i] > comp[2*i+1];
    }
    return true;
}
 
int main()
{
    optimiza_io
    
    // WEIRD WAY TO READ GRAPH
    cin >> N >> M;
    while(N --) {
        char op1, op2;
        int a, b;
        cin >> op1 >> a >> op2 >> b;
        a = 2 * a + (op1 == '-' ? 1 : 0);
        b = 2 * b + (op2 == '-' ? 1 : 0);
        ady[a ^ 1].push_back(b);
        ady[b ^ 1].push_back(a);
        rady[b].push_back(a ^ 1);
        rady[a].push_back(b ^ 1);
    }
    
    if(! solve_2sat()) {
        cout << "IMPOSSIBLE\n";
        exit(0);
    }
    
    for(int i = 1; i <= N/2; i ++)
        cout << (ans[i] ? "+ " : "- ");
    return 0;
}