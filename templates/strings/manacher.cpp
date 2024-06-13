//  Copyright © 2020 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 1000005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
int d1[MAX];
int d2[MAX];
 
void getD1(string & s) {
    int N = s.size();
    for (int i = 0, l = 0, r = -1; i < N; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < N && s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }    
}
 
void getD2(string & s) {
    int N = s.size();
    for (int i = 0, l = 0, r = -1; i < N; i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < N && s[i - k - 1] == s[i + k]) {
            k++;
        }
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k ;
        }
    }
}
 
void solve(string & s) {
    getD1(s);
    getD2(s);
}
 
int main()
{
    optimiza_io
    string s;
    cin >> s;
    solve(s);
    
    bool isd1 = true;
    int bst = -1, pos = -1;
    
    for(int i = 0; i < s.size(); i ++)
        if(2 * d1[i] - 1 > bst)
            bst = 2 * d1[i] - 1, pos = i;
    
    for(int i = 0; i < s.size(); i ++)
        if(2 * d2[i] > bst)
            bst = 2 * d2[i], isd1 = 0, pos = i;
     
    if(isd1) {
        for(int i = pos - d1[pos] + 1; i <= pos + d1[pos] - 1; i ++)
            cout << s[i];
    }
    else {
        for(int i = pos - d2[pos]; i <= pos + d2[pos] - 1; i ++)
            cout << s[i];
    }
    return 0;
}
 
// CHECAR LIMITES 