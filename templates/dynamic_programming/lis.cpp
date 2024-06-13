//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 200005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
int N, a[MAX];
int head[MAX], prv[MAX];
  
int lis()  { 
    cin >> N;
    for(int i = 1; i <= N; i ++)
        cin >> a[i];
        
    int lst = 1;
    head[1] = 1;
    for(int i = 2; i <= N; i ++) {
        if(a[i] < a[head[1]]) 
            head[1] = i;
        else if(a[i] > a[head[lst]]) {
            prv[i] = head[lst];
            head[++lst] = i;
        }
        else  {
            int l = 0;
            int r = lst;
            while(l < r) {
                int m = (l + r + 1) / 2;
                if(a[head[m]] < a[i])
                    l = m;
                else
                    r = m - 1;
            }
            int p = l + 1;
            prv[i] = head[p - 1];
            head[p] = i;
        }
    }
    
    /* for(int i = head[lst]; i > 0; i = prv[i]) 
        cout << a[i] << " ";
    cout << "\n";
    */
    
    return lst; 
} 
  
  
 
int main()
{
    optimiza_io
    cout << lis();
    return 0;
}