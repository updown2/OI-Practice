/*
http://usaco.org/current/data/sol_optmilk.html
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
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
#define int ll
const int MAXN=40000, INF=1000000000000000000;
///500,000,000
int N, D, out, inp[MAXN], nn[4*MAXN+1], ny[4*MAXN+1], YN[4*MAXN+1], yy[4*MAXN+1];

void solve(int x, int a, int b, int d) {
    /// base cases for size < 4
    if (a == b) {
        yy[x] = inp[a];
        YN[x] = ny[x] = nn[x] = 0;
        return;
    }
    if (a+1 == b) {
        nn[x] = 0;
        ny[x] = inp[b];
        YN[x] = inp[a];
        yy[x] = max(inp[a], inp[b]);
        return;
    }
    if (a+2 == b) {
        nn[x] = inp[a+1];
        YN[x] = max(inp[a], inp[a+1]);
        ny[x] = max(inp[a+1], inp[b]);
        yy[x] = max(inp[a]+inp[b], inp[a+1]);
        return;
    }
    if (d != -1 && (d < a || b < d)) return; /// not in range
    int c = b;
    b = (a+c)/2;
    solve(x*2, a, b, d), solve(x*2+1, b+1, c, d);
    yy[x] = max(YN[x*2]+yy[2*x+1], yy[2*x]+ny[2*x+1]);
    ny[x] = max(nn[x*2]+yy[2*x+1], ny[2*x]+ny[2*x+1]);
    YN[x] = max(YN[x*2]+YN[2*x+1], yy[2*x]+nn[2*x+1]);
    nn[x] = max(nn[x*2]+YN[2*x+1], ny[2*x]+nn[2*x+1]);
}

main() {
    //ifstream cin("test.in");
    ifstream cin("optmilk.in"); ofstream cout("optmilk.out");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> D;
    ffi cin >> inp[i];
    solve(1, 0, N-1, -1);
    For (d, 0, D) {
        int a, b; cin >> a >> b; a--;
        inp[a] = b;
        solve(1, 0, N-1, a);
        out += yy[1];
    }
    w<< out<<e;
}
