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
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
//500,000,000 operations
const int MAXN = 250, INF = 1000000000;
//Global Variables
int N, M, adj[MAXN][MAXN], from[MAXN], original, best;
priority_queue<pair<int, pair<int, int> > > nex; /// (-dist, (at, from) )
bool vis[MAXN];

void solve() {
    ffi vis[i] = false;
    nex.push(mp(0, mp(0, 0)));
    while (!nex.empty()) {
        int at = nex.top().b.a, d = nex.top().a, pre = nex.top().b.b; nex.pop();
        if (vis[at]) continue;
        if (at == N-1) best = max(best, -d);
        vis[at] = true;
        ffi nex.push(mp(d-adj[at][i], mp(i, at)));
    }
}

main() {
    //ifstream cin ("test.in");
    ifstream cin("rblock.in"); ofstream cout("rblock.out");
    ios_base::sync_with_stdio; cin.tie(0);
    cin >> N >> M;
    ffa adj[i][j] = INF;
    ffi from[i] = -1;
    For (i, 0, M) {
        int a, b, d; cin >> a >> b >> d; a--; b--; adj[a][b] = adj[b][a] = d;
    }
    nex.push(mp(0, mp(0, 0)));
    while (!nex.empty()) {
        int at = nex.top().b.a, d = nex.top().a, pre = nex.top().b.b; nex.pop();
        if (from[at] != -1) continue;
        if (at == N-1) original = best = -d;
        from[at] = pre;
        ffi nex.push(mp(d-adj[at][i], mp(i, at)));
    }
    //ffi w<< from[i]+1<<e;
    //w<< original<<e;
    For (i, 1, N) {
        /// double previous edge
        adj[i][from[i]] = adj[from[i]][i] = adj[i][from[i]]*2;
        solve();
        /// undo
        adj[i][from[i]] = adj[from[i]][i] = adj[i][from[i]]/2;
    }
    w<< best - original<<e;
}
