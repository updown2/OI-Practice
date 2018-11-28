/*
Same idea as this code: https://github.com/tmwilliamlin168/CompetitiveProgramming/blob/master/TOKI/18-Group.cpp
*/
#include "group.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, M)
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
const ll MAXN = 100000, INF = 10000000000;
//Global Variables
ll t=-INF, b=INF, l=INF, r=-INF;

bool works(ll d, int N, ll X[], ll Y[]) {
    /// rect from (l, b) to (l+d, b+d) and (r-d, t-d) to (r, t)
    ll cnt = 0;
    ffi {
        if (X[i] >= l && X[i] <= l+d && Y[i] >= b && Y[i] <= b+d) cnt++;
        else if (X[i] >= r-d && X[i] <= r && Y[i] >= t-d && Y[i] <= t) cnt++;
    }
    if (cnt == N) return true;
    /// rect from (l, t-d) to (l+d, t) and (r-d, b) to (r, b+d)
    cnt = 0;
    ffi {
        if (X[i] >= l && X[i] <= l+d && Y[i] >= t-d && Y[i] <= t) cnt++;
        else if (X[i] >= r-d && X[i] <= r && Y[i] >= b && Y[i] <= b+d) cnt++;
    }
    return cnt==N;
}

int getMinimumDelay(int N, vector<int> x, vector<int> y) {
    ll nx[MAXN], ny[MAXN];
    ffi {
        pair<ll, ll> loc = mp(x[i]+y[i], x[i]-y[i]);
        nx[i] = loc.a, ny[i] = loc.b;
        t = max(t, ny[i]); b = min(b, ny[i]);
        l = min(l, nx[i]); r = max(r, nx[i]);
    }
    //w<< b s t c l s r<<e;
    ll st = 0, en = INF;
    while (st != en) {
        ll mid = (st+en)/2;
        if (works(mid, N, nx, ny)) en = mid;
        else st = mid+1;
    }
    return st;
}
