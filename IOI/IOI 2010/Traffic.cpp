/*
save congestion between self and parent
update congestion as travel through tree
*/
#include "grader.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(ll i=a; i<b; i++)
#define ffi For(i, 0, N2)
#define ffj For(j, 0, M)
#define ffa ffi ffj
#define s <<" "<<
#define w cout
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
const ll MAXN = 1000000, INF = 1000000000000000000;
ll tree[4*MAXN+1], siz[MAXN], N2, outa, outb = INF;
vector<int> adj[MAXN];

int LocateCentre(int N, int P[], int S[], int D[]);

void go(int at, int p) {
    //w<< at<<e;
    //for (int i: adj[at]) w<< i<< " "; w<<e;
    for (int i: adj[at]) if(i != p) {go(i, at); siz[at] += siz[i];}
}
void build(int x, int L, int R) {
    if (L == R) {
        tree[x] = siz[L];
        if (L == 0) tree[x] = 0;
        return;
    }
    int mid = (L+R)/2; build(x*2, L, mid), build(x*2+1, mid+1, R);
    tree[x] = max(tree[x*2], tree[x*2+1]);
}
ll query (int x, int L, int R, int oL, int oR) {
    if (R < oL || oR < L) return -INF;
    if (oL <= L && R <= oR) return tree[x];
    int mid = (L+R)/2;
    return max(query(x*2, L, mid, oL, oR), query(x*2+1, mid+1, R, oL, oR));
}
void update (int x, int L, int R, int loc, ll v) {
    if (R < loc || loc < L) return;
    if (L == R) {
        tree[x] = v;
        return;
    }
    int mid = (L+R)/2;
    update(x*2, L, mid, loc, v); update(x*2+1, mid+1, R, loc, v);
    tree[x] = max(tree[x*2], tree[x*2+1]);
}
void solve(ll at, ll p) {
    ll have = query(1, 0, N2-1, 0, N2-1);
    if (have < outb) {
        outb = have;
        outa = at;
    }
    for (ll j: adj[at]) if (j != p) {
        update(1, 0, N2-1, j, siz[0] - siz[j]);
        solve(j, at);
        update(1, 0, N2-1, j, siz[j]); /// undo
    }
}

int LocateCentre(int N, int P[], int S[], int D[]) {
    N2 = N;
    //w<< N s N2<<e;
    ffi siz[i] = P[i];
    For (i, 0, N2-1) {adj[S[i]].pb(D[i]); adj[D[i]].pb(S[i]);}
    go(0, 0);
    //ffi w<< siz[i]<<e;
    build(1, 0, N2-1);
    solve(0, 0);
    return outa;
}
