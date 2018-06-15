/*
segtree on a tree
travel through the tree and update the values to get nex[i]
use binary jumping to get nex^K[i]
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(ll i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, M)
#define ffa ffi ffj
#define s <<" "<<
#define w cout
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
//#define int ll
//500,000,000 operations
const int MAXN = 300000, INF = 2000000000;
//Global Variables
int N, nex[MAXN][2], A[MAXN], dep[MAXN], loc[MAXN][2], tree[4*MAXN+1], lazy[4*MAXN+1];
ll K, p2[60];
vector<int> adj[MAXN], ord;

void go(int at, int p) {
    dep[at] = dep[p]+1;
    loc[at][0] = ord.size();
    ord.pb(at);
    for (int i: adj[at]) if (i != p) go(i, at);
    loc[at][1] = ord.size()-1;
}
void build(int x, int L, int R) {
    if (L == R) {
        L = ord[L];
        tree[x] = A[L] - dep[L];
        return;
    }
    int mid = (L+R)/2; build(x*2, L, mid), build(x*2+1, mid+1, R);
    tree[x] = max(tree[x*2], tree[x*2+1]);
}
void push (int x, int L, int R) {
    tree[x] += lazy[x];
    if (L != R) {
        lazy[x*2] += lazy[x];
        lazy[x*2+1] += lazy[x];
    }
    lazy[x] = 0;
}
int query (int x, int L, int R, int oL, int oR) {
    if (R < oL || oR < L) return -INF;
    push(x, L, R);
    if (oL <= L && R <= oR) return tree[x];
    int mid = (L+R)/2;
    return max(query(x*2, L, mid, oL, oR), query(x*2+1, mid+1, R, oL, oR));
}
int get_index (int x, int L, int R) {
    if (L == R) return ord[L];
    int val = query(x, L, R, L, R); ///everything above should already be pushed
    int mid = (L+R)/2;
    int a = INF, b = INF;
    if (query(x*2, L, mid, L, mid) == val) a = get_index(x*2, L, mid);
    if (query(x*2+1, mid+1, R, mid+1, R) == val) b = get_index(x*2+1, mid+1, R);
    return min(a, b);
}
void update (int x, int L, int R, int oL, int oR, int v) {
    push(x, L, R);
    if (R < oL || oR < L) return;
    if (oL <= L && R <= oR) {
        lazy[x] += v;
        push(x, L, R);
        return;
    }
    int mid = (L+R)/2;
    update(x*2, L, mid, oL, oR, v); update(x*2+1, mid+1, R, oL, oR, v);
    tree[x] = max(tree[x*2], tree[x*2+1]);
}
void solve(int at, int p) {
    update(1, 0, N-1, loc[at][0], loc[at][0], -INF); /// can't pick self
    //w<< at s ":"<<e; ffi w<< query(1, 0, N-1, loc[i][0], loc[i][0])<<" "; w<<e;
    nex[at][0] = get_index(1, 0, N-1);
    update(1, 0, N-1, loc[at][0], loc[at][0], INF); /// undo

    update(1, 0, N-1, 0, N-1, -1);
    //w<< "decreased"<<e; ffi w<< query(1, 0, N-1, loc[i][0], loc[i][0])<<" "; w<<e;
    for (int j: adj[at]) if (j != p) {
        update(1, 0, N-1, loc[j][0], loc[j][1], 2);
        solve(j, at);
        update(1, 0, N-1, loc[j][0], loc[j][1], -2); /// undo
    }
    update(1, 0, N-1, 0, N-1, 1); /// undo
}

main() {
	//ifstream cin ("test.in");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	ffi cin >> A[i];
	For (i, 1, N) {int a, b; cin >> a >> b; a--; b--; adj[a].pb(b), adj[b].pb(a);}
    dep[0] = -1;
    go(0, 0);
    //ffi w<< loc[i][0] s loc[i][1]<<e;
    build(1, 0, N-1);
    solve(0, 0);
    //ffi w<< i s nex[i][0]<<e;
    //for (int i: ord) w<<i<<e;
    //For (k, 0, 59) ffi nex[i][k+1] = nex[nex[i][k]][k];
    int at = 0;
    p2[0] = 1;
    For (i, 1, 60) p2[i] = 2*p2[i-1];
    For (k, 0, 60) {
        //w<< k s k%2 s ":"<<e; ffi w<< nex[i][k%2]<< " ";w<<e;
        ffi nex[i][(k+1)%2] = nex[nex[i][k%2]][k%2];
        //w<< k s ":"<<e; ffi w<< nex[i][k%2]<< " ";w<<e;
        if (K & p2[k]) at = nex[at][k%2];
    }
    w<< at+1<<e;
}
