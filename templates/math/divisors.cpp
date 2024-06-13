//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 1000005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
int T;
int pr[MAX];
 
int divs(int x) {
    if(x == 1)
        return 1;
    int ans = 1;
    int ant = 0;
    int cnt = 0;
    while(pr[x]) {
        if(pr[x] == ant) 
            cnt++;
        else {
            ans *= (cnt + 1);
            cnt = 1;
            ant = pr[x];
        }
        x /= pr[x];
    }
    if(x == ant)
        ans *= (cnt + 2);
    else
        ans *= (cnt + 1) * 2;
    
    return ans;
}
 
void sieve(int LIM) {
    
    for(int i = 2; i <= sqrt(LIM); i ++)
        if(! pr[i]) 
            for(int j = i * i; j <= LIM; j += i)
                if(! pr[j])
                    pr[j] = i;
}
 
int main()
{
    optimiza_io
    sieve(1e6);
    cin >> T;
    while(T --) {
        int x;
        cin >> x;
        cout << divs(x) << "\n";
    }
    return 0;
}