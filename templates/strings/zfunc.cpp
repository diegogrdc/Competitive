//  Copyright © 2020 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 1000005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
// O indexed 
 
int zz[MAX];
 
void z_function(string & s) {
    int N = s.size();
    for(int i = 1, l = 0, r = 0; i < N; i ++) {
        if(i <= r)
            zz[i] = min(r - i + 1, zz[i - l]);
        while(i + zz[i] < N && s[zz[i]] == s[i + zz[i]])
            zz[i]++;
        if(i + zz[i] - 1 > r)
            l = i, r = i + zz[i] - 1;
    }
 
}
 
int main()
{
    optimiza_io
    string s;
    cin >> s;
    z_function(s);
    for(int i = 1; i <= s.size(); i ++)
        if(i + zz[i] == s.size())
            cout << i << " ";
    cout << "\n";
    return 0;
}
 
// CHECAR LIMITES 