/*
https://codeforces.com/blog/entry/44657?#comment-293060
*/
#include "gap.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 2, N)
#define ffj For(j, 0, N)
#define ffa ffi ffj
#define ss <<" "<<
#define c <<" : "<<
#define w cout
#define e endl//"\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
//#define int ll
const int MAXN=100000;
///500,000,000
long long findGap(int T, int N) {
    if (T == 1) {
        ll ans[N], l = 0, r = N-1, mn, mx;
        while (r >= l) {
            if (l == 0) MinMax(0, 1e18, &mn, &mx);
            else if (ans[l-1]+1 <= ans[r+1]-1) MinMax(ans[l-1]+1, ans[r+1]-1, &mn, &mx);
            ans[l] = mn; ans[r] = mx;
            l++; r--;
        }
        ll ret = 0;
        For (i, 1, N) ret = max(ret, ans[i] - ans[i-1]);
        return ret;
    }
    ll l, r, mn, mx;
    MinMax(0, 1e18, &l, &r);
    set<ll> vals; vals.insert(l); vals.insert(r);
    ll ad = (r-l+N-2)/(N-1);
    For (i, 0, N-1) if (min(r-1, l+(i+1)*ad) >= l+i*ad+1) {
        MinMax(l+i*ad+1, min(r-1, l+(i+1)*ad), &mn, &mx); vals.insert(mn); vals.insert(mx);
    }
    ll prev = l;
    ll ret = 0;
    for (ll i: vals) {
        if (i == -1) continue;
        ret = max(ret, i-prev);
        prev = i;
    }
	return ret;
}
