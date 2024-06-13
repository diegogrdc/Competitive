//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 200005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
int N, M;
vector <int> ady[MAX];
int in[MAX];
vector <int> ans;
 
void toposort() {
    queue < int > q;
    for(int i = 1; i <= N; i ++)
        if(! in[i])
            q.push(i);
    while(! q.empty()) {
        int x = q.front();
        q.pop();
        ans.push_back(x);
        for(auto v : ady[x]) {
            in[v]--;
            if(! in[v])
                q.push(v);
        }
    }
}
 
 
int main()
{
    optimiza_io
    cin >> N >> M;
    while(M --) {
        int a, b;
        cin >> a >> b;
        ady[a].push_back(b);
        in[b]++;
    }
    
    toposort();
    if(ans.size() != N) {
        cout << "IMPOSSIBLE\n";
        exit(0);
    }
    for(auto v : ans)
        cout << v << " ";
    return 0;
}