//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define pii pair < int, int >
#define fi first
#define se second
#define MAX 200005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
int N;
stack < pii > s;
 
 
int main()
{
    optimiza_io
    cin >> N;
    s.push({ 0, 0 });
    for(int i = 1; i <= N; i ++) {
        int x;
        cin >> x;
        while(s.top().fi >= x)
            s.pop();
        cout << s.top().se << " ";
        s.push({ x, i });
    }
    cout << "\n";
    return 0;
}