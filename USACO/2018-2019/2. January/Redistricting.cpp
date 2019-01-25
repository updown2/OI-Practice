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
const int MAXN = 300001, INF = 1000000000;
//Global Variables
int N, K, pre[MAXN], sm, dp[MAXN], at, st[4*MAXN+1];
vector<pair<int, int> > tree[4*MAXN+1];
string inp;

void update(int ind, int L, int R, int x, int v) {
    if (x < L || R < x) return;
    if (L == R) {
        while (!tree[ind].empty() && tree[ind][tree[ind].size()-1].a >= v) tree[ind].pop_back();
        tree[ind].emplace_back(v, at);
        st[ind] = min(st[ind], (int)tree[ind].size()-1);
        return;
    }
    update(ind*2, L, (L+R)/2, x, v); update(ind*2+1, (L+R)/2+1, R, x, v);
    while (!tree[ind].empty() && tree[ind][tree[ind].size()-1].a >= v) tree[ind].pop_back();
    tree[ind].emplace_back(v, at);
    st[ind] = min(st[ind], (int)tree[ind].size()-1);
}
int query(int ind, int L, int R, int oL, int oR) {
    if (oR < L || R < oL) return INF;
    if (oL <= L && R <= oR) {
        if (tree[ind].empty()) return INF;
        while (st[ind] < tree[ind].size() && tree[ind][st[ind]].b <= at-K-1) st[ind]++;
        if (st[ind] == tree[ind].size()) return INF;
        return tree[ind][st[ind]].a;
    }
    return min(query(ind*2, L, (L+R)/2, oL, oR), query(ind*2+1, (L+R)/2+1, R, oL, oR));
}


main() {
    //ifstream cin("test.in");
    ifstream cin("redistricting.in"); ofstream cout("redistricting.out");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K >> inp; inp = ' '+inp; N++;
    For (i, 1, N) {
        pre[i] = pre[i-1];
        if (inp[i] == 'H') pre[i]++;
        else pre[i]--;
        sm = min(sm, pre[i]);
    }
    /// update pre so that the smallest prefix is 1 (only care about relative prefixes)
    ffi pre[i] += 1-sm;
    //ffi w<< pre[i]<<e;
    ffi {
        at = i;
        if (i != 0) dp[i] = min(query(1, 0, N, 0, pre[i]-1), query(1, 0, N, pre[i], N)+1);
        update(1, 0, N, pre[i], dp[i]);
        //w<< i c dp[i]<<e;
    }
    w<< dp[N-1]<<e;
}
