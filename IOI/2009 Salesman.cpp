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
const int MAXN = 500003, INF = 2*1e9;
//Global Variables
int N, U, D, S, dp[MAXN], t0D[4*MAXN+1], t0U[4*MAXN+1], dpU[4*MAXN+1], dpD[4*MAXN+1], pre[MAXN];
pair<int, pair<int, int> > fairs[MAXN]; /// (day, (location, profit) )

void updatedpU(int ind, int L, int R, int x, int v) {
    if (x < L || R < x) return;
    if (L == R) {
        dpU[ind] = v;
        return;
    }
    updatedpU(ind*2, L, (L+R)/2, x, v);
    updatedpU(ind*2+1, (L+R)/2+1, R, x, v);
    dpU[ind] = max(dpU[ind*2], dpU[ind*2+1]);
}
void updatedpD(int ind, int L, int R, int x, int v) {
    if (x < L || R < x) return;
    if (L == R) {
        dpD[ind] = v;
        return;
    }
    updatedpD(ind*2, L, (L+R)/2, x, v);
    updatedpD(ind*2+1, (L+R)/2+1, R, x, v);
    dpD[ind] = max(dpD[ind*2], dpD[ind*2+1]);
}
void updatet0D(int ind, int L, int R, int x, int v) {
    if (x < L || R < x) return;
    if (L == R) {
        t0D[ind] = v;
        return;
    }
    updatet0D(ind*2, L, (L+R)/2, x, v);
    updatet0D(ind*2+1, (L+R)/2+1, R, x, v);
    t0D[ind] = max(t0D[ind*2], t0D[ind*2+1]);
}
void updatet0U(int ind, int L, int R, int x, int v) {
    if (x < L || R < x) return;
    if (L == R) {
        t0U[ind] = v;
        return;
    }
    updatet0U(ind*2, L, (L+R)/2, x, v);
    updatet0U(ind*2+1, (L+R)/2+1, R, x, v);
    t0U[ind] = max(t0U[ind*2], t0U[ind*2+1]);
}

int querydpU(int ind, int L, int R, int oL, int oR) {
    if (oR < L || R < oL) return -INF;
    if (oL == 6 && oR == 6) w<< ind s L s R c dpU[ind]<<e;
    if (oL <= L && R <= oR) return dpU[ind];
    return max(querydpU(ind*2, L, (L+R)/2, oL, oR), querydpU(ind*2+1, (L+R)/2+1, R, oL, oR));
}
int querydpD(int ind, int L, int R, int oL, int oR) {
    if (oR < L || R < oL) return -INF;
    if (oL <= L && R <= oR) return dpD[ind];
    return max(querydpD(ind*2, L, (L+R)/2, oL, oR), querydpD(ind*2+1, (L+R)/2+1, R, oL, oR));
}
int queryt0U(int ind, int L, int R, int oL, int oR) {
    if (oR < L || R < oL) return -INF;
    if (oL <= L && R <= oR) return t0U[ind];
    return max(queryt0U(ind*2, L, (L+R)/2, oL, oR), queryt0U(ind*2+1, (L+R)/2+1, R, oL, oR));
}
int queryt0D(int ind, int L, int R, int oL, int oR) {
    if (oR < L || R < oL) return -INF;
    if (oL <= L && R <= oR) return t0D[ind];
    return max(queryt0D(ind*2, L, (L+R)/2, oL, oR), queryt0D(ind*2+1, (L+R)/2+1, R, oL, oR));
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> U >> D >> S;
    ffi cin >> fairs[i].a >> fairs[i].b.a >> fairs[i].b.b;
    fairs[N] = mp(MAXN, mp(S, 0));
    N++;
    sort(fairs, fairs+N);
    For (i, 0, MAXN) dp[i] = -INF;
    For (i, 0, 4*MAXN+1) t0D[i] = t0U[i] = dpU[i] = dpD[i] = -INF;
    dp[S] = 0;
    updatedpU(1, 0, MAXN-1, S, -U*S);
    updatedpD(1, 0, MAXN-1, S, D*S);
    //w<< querydpU(1, 0, MAXN-1, 0, MAXN-1)<<e;
    int i=0;
    while (i < N) {
        int k = i;
        while (k+1 < N && fairs[k+1].a == fairs[i].a) k++;
        /// fairs with the same day are i to k
        /// update with pre values
        if (i != 0) pre[i-1] = 0;
        pre[i] = fairs[i].b.b;
        For (l, i+1, k+1) pre[l] = pre[l-1] + fairs[l].b.b;
        For (l, i, k+1) {
            int loc = fairs[l].b.a;
            int prel1 = 0;
            if (l != 0) prel1 = pre[l-1];
            int tdp0 = max(querydpU(1, 0, MAXN-1, loc, MAXN-1) + U*loc, querydpD(1, 0, MAXN-1, 0, loc) - D*loc);
            //w<< loc s tdp0 c tdp0 + D*loc-prel1 s tdp0 - U*loc + pre[l]<<e;
            //if (loc == S) w<<"at S" s querydpU(1, 0, MAXN-1, 6, 6) s tdp0<<e;
            updatet0D(1, 0, MAXN-1, loc, tdp0 + D*loc-prel1);
            updatet0U(1, 0, MAXN-1, loc, tdp0 - U*loc + pre[l]);
        }
        For (l, i, k+1) {
            int loc = fairs[l].b.a;
            int prel1 = 0;
            if (l != 0) prel1 = pre[l-1];
            dp[loc] = max(queryt0D(1, 0, MAXN-1, 0, loc) + pre[l] - D*loc, queryt0U(1, 0, MAXN-1, loc, MAXN-1) - prel1+ U*loc);
            //w<< "dp" s loc s dp[loc] c queryt0D(1, 0, MAXN-1, 0, loc)<<e;
            //if (loc == 6) w<< dp[loc]<<e;
            updatedpU(1, 0, MAXN-1, loc, dp[loc]-U*loc);
            //if (loc == 6) w<< dp[loc] s querydpU(1, 0, MAXN-1, S, MAXN-1)<<e;
            updatedpD(1, 0, MAXN-1, loc, dp[loc]+D*loc);
        }
        /// reset values
        For (l, i, k+1) {
            int loc = fairs[l].b.a;
            updatet0D(1, 0, MAXN-1, loc, -INF);
            updatet0U(1, 0, MAXN-1, loc, -INF);
        }
        i = k+1;
    }
    //For (i, 0, MAXN) if (dp[i] != -INF) w<< i c dp[i]<<e;
    w << dp[S]<<e;
}
