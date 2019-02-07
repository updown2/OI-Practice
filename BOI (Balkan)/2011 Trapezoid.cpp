/*
dpmax[i] = max trapezoids you can take if you take i
dpcnt[i] = number of different ways to take dpmax[i]
coordinate compress
keep a segtree tree[b[i]] = dp[i]
sort by c & d
at a c:
- set dp[i], we only care about D[j] if D[j] < C[i] so every one so far can be used
- dp[i] comes from query(all b[j] < a[i])
at d:
- add to segtree
*/
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
const int MAXN = 100000, MOD = 30013;
//Global Variables
int N, A[MAXN], B[MAXN], C[MAXN], D[MAXN], AB[2*MAXN], dpmax[MAXN], dpcnt[MAXN], treemax[8*MAXN+1], treecnt[8*MAXN+1];
map<int, int> ab, cd;
pair<int, int> CD[2*MAXN];


void update (int ind, int L, int R, int x, int i) {
    if (x < L || R < x) return;
    if (L == R) {
        treemax[ind] = dpmax[i];
        treecnt[ind] = dpcnt[i];
        return;
    }
    update(ind*2, L, (L+R)/2, x, i); update(ind*2+1, (L+R)/2+1, R, x, i);
    if (treemax[ind*2] == treemax[ind*2+1]) {
        treemax[ind] = treemax[ind*2];
        treecnt[ind] = (treecnt[ind*2]+treecnt[ind*2+1])%MOD;
    }
    else if (treemax[ind*2] > treemax[ind*2+1]) {
        treemax[ind] = treemax[ind*2];
        treecnt[ind] = treecnt[ind*2];
    }
    else {
        treemax[ind] = treemax[ind*2+1];
        treecnt[ind] = treecnt[ind*2+1];
    }
}
pair<int, int> query(int ind, int L, int R, int oL, int oR) { /// (max, cnt)
    if (oL <= L && R <= oR) return mp(treemax[ind], treecnt[ind]);
    if (R < oL || oR < L) return mp(0, 0);
    pair<int, int> i = query(ind*2, L, (L+R)/2, oL, oR), j = query(ind*2+1, (L+R)/2+1, R, oL, oR);
    if (i.a == j.a) return mp(i.a, (i.b+j.b)%MOD);
    if (i.a < j.a) return j;
    return i;
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    ffi {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
        AB[2*i] = A[i], AB[2*i+1] = B[i];
        CD[2*i].a = C[i], CD[2*i+1].a = D[i];
        CD[2*i].b = CD[2*i+1].b = i;
    }
    /// coordinate compress. new coordinates: 1 : 2*N
    sort(AB, AB+2*N); sort(CD, CD+2*N);
    For (i, 1, 2*N+1) {
        ab[AB[i-1]] = i;
        cd[CD[i-1].a] = i;
    }
    ffi {
        A[i] = ab[A[i]]; B[i] = ab[B[i]]; C[i] = cd[C[i]]; D[i] = cd[D[i]];
        //w<< i c A[i] s B[i] s C[i] s D[i]<<e;
    }
    For (j, 0, 2*N) {
        int i = CD[j].b;
        if (dpmax[i] == 0) {
            /// we are at a C
            pair<int, int> get = query(1, 1, 2*N, 1, A[i]); /// (max, cnt)
            if (get.a == 0) get.b = 1;
            dpmax[i] = get.a+1;
            dpcnt[i] = get.b;
        }
        else {
            /// we are at a D
            update(1, 1, 2*N, B[i], i);
        }
    }
    int out1 = 0, out2 =0;
    ffi out1 = max(out1, dpmax[i]);
    ffi if (dpmax[i] == out1) {out2 += dpcnt[i]; out2 %= MOD;}
    w<< out1 s out2<<e;
}
