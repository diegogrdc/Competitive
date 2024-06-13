//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 200005
#define pii pair < int, int >
#define fi first
#define se second
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> OST;
 
// .insert()
// .erase()
// .order_of_key (all smaller than k)
// order_of_key: The number of items in a set that are strictly smaller than k
// find_by_order: It returns an iterator to the ith largest element
 
int N, Q;
int vals[MAX];
 
int main()
{
    optimiza_io
    OST T;
    cin >> N >> Q;
    for(int i = 1; i <= N; i ++) {
        cin >> vals[i];
        T.insert({ vals[i], i });
    }
    while(Q --) {
        char t;
        int a, b;
        cin >> t >> a >> b;
        if(t == '?')
            cout << T.order_of_key({ b + 1, 0 }) - T.order_of_key({ a, 0 }) << "\n";
        else {
            T.erase({ vals[a], a });
            vals[a] = b;
            T.insert({ vals[a], a });
        }
    }
    return 0;
}