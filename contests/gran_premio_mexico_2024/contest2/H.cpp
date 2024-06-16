//  Copyright © 2024 Diego Garcia Rodriguez del Campo. All rights reserved.
#include <bits/stdc++.h>
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
#define what_is(x) cerr << #x << " is " << x << endl;
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long ll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

const int MAX = 1e4 + 5;

int N, CR, CL, cr, cl;
int L[MAX], R[MAX];
set<int> ans;


int main() {
    optimiza_io
    cin >> N >> CR >> CL;
    CR--; CL--;
    cr = 1; cl = N;
    for(int i = 1; i <= N; i++) {
        L[i] = i == 1 ? N : i - 1; 
        R[i] = i == N ? 1 : i + 1;
    }

    while(true) {
        if(N <= 2) {
            for(int i = 0; i < N; i ++) {
                ans.insert(cl);
                cl = L[cl];
            }
            break;
        }
        // Move cr
        for(int i = 0; i < CR % N; i ++)
            cr = R[cr];
        // Move cl
        for(int i = 0; i < CL % N; i ++)
            cl = L[cl];

        // Check hire/discard cases
        if(cl == cr) {
            // Hire and remove
            ans.insert(cl);
            int tol = L[cr];
            int tor = R[cr];
            L[tor] = tol;
            R[tol] = tor;
            cr = tor;
            cl = tol;
            N--; 
        } else {
            // Remove both
            N -= 2;

            int cr_newl = cr;
            while(cr_newl == cr || cr_newl == cl)
                cr_newl = L[cr_newl];
            int cr_newr = cr;
            while(cr_newr == cr || cr_newr == cl)
                cr_newr = R[cr_newr];

            int cl_newl = cl;
            while(cl_newl == cr || cl_newl == cl)
                cl_newl = L[cl_newl];
            int cl_newr = cl;
            while(cl_newr == cr || cl_newr == cl)
                cl_newr = R[cl_newr];
            
            L[cr_newr] = cr_newl; R[cr_newl] = cr_newr; cr = cr_newr;
            L[cl_newr] = cl_newl; R[cl_newl] = cl_newr; cl = cl_newl;
        }

    }
    for(auto x : ans)
        cout << x << ' ';
    cout << '\n';
    return 0;
}
