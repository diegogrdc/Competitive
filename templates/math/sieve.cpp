//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 1000005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
int T;
int pr[MAX];
 
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
    return 0;
}