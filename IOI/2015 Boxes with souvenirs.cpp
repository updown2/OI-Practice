/*
dpfor[team i] = minimum cost to go only forward and give gifts to all teams 1...i
dpbck[team i] = minimum cost to go only backwards and give gifts to all teams i...N
to get a dp value, it is optimal to take the last K, second last K, and so on (and possible < k for the last one)
see code for transitions (they are very simple)
*/
#include "boxes.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, N)
#define ffa ffi ffj
#define s <<" "<<
#define c <<" : "<<
#define w cout
#define e endl//"\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
//#define int ll
//500,000,000 operations
const int MAXN = 10000000;
//Global Variables
ll vals[MAXN], N2, dpfor[MAXN], dpbck[MAXN];

long long delivery(int N, int K, int L, int p[]) {
    /// remove 0s
    ffj if (p[j] != 0) {
        vals[N2] = p[j];
        N2++;
    }
    N = N2;
    ffi {
        if (i < K) dpfor[i] = min((ll)L, 2*vals[i]); /// 1 trip is always optimal
        else dpfor[i] = min((ll)L, 2*vals[i]) + dpfor[i-K];
        //w<< i c dpfor[i]<<e;
    }
    for (int i=N-1; i>=0; i--) {
        if (i >= N-K) dpbck[i] = min((ll) L, 2*(L-vals[i]));
        else dpbck[i] = min((ll) L, 2*(L-vals[i])) + dpbck[i+K];
        //w<< i c dpbck[i]<<e;
    }
    ll ret = min(dpfor[N-1], dpbck[0]);
    For (i, 1, N) ret = min(ret, dpfor[i-1]+dpbck[i]);
    return ret;
}
