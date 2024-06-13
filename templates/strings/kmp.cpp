//  Copyright © 2020 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 2000005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
int pre[MAX];
 
void kmp(string s) {
    int N = s.size();
    for(int i = 1; i < N; i ++) {
        int j = pre[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pre[j - 1];
        if (s[i] == s[j])
            j++;
        pre[i] = j;
    }
}
 
int main()
{
    optimiza_io
    string s, t;
    cin >> s >> t;
    int M = t.size();
    int ans = 0;
    t += '#'; 
    t += s;
    kmp(t);
    for(int i = 0; i < t.size(); i ++)
        if(pre[i] == M)
            ans++;
    cout << ans << "\n";
    return 0;
}
 
// CHECAR LIMITES 