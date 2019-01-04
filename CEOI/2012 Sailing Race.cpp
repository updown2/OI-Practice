/*
dp[node 1][node 2][0/1] = max edges in the range starting at node 1/2 (based on the third dimension)
http://ceoi2012.elte.hu/download/modelsolutions/3_solrace.pdf
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
const int MAXN=500, INF=1000000000;
///500,000,000
int N, K, dp[MAXN][MAXN][2], out, loc, dirb[MAXN][MAXN], dirs[MAXN][MAXN], Ab[MAXN][MAXN], As[MAXN][MAXN];
vector<int> adj[MAXN], bck[MAXN];
priority_queue<pair<int, int> > n1; /// ((-/+)relative loc, loc)
bool vis[MAXN];

bool in (int x, int y, int z) {
    if (y < z) return y < x && x < z;
    return x > y || x < z;
}
int solve(int n1, int n2, int at) {
    if (dp[n1][n2][at] != -1) return dp[n1][n2][at];
    dp[n1][n2][at] = 0;
    //w<< n1 s n2 s at<<e;
    /// range is n1+1 to n2-1  (n1+1)%N to (n2-1+N)%N
    if ((n1+1)%N == n2) {dp[n1][n2][at] = 0; return dp[n1][n2][at];}
    if (at == 0) {
        /// at n1
        for (int i: adj[n1]) if (in(i, n1, n2)) {
            dp[n1][n2][0] = max(dp[n1][n2][0], max(solve(n1, i, 1), solve(i, n2, 0))+1);
        }
        return dp[n1][n2][0];
    }
    /// at n2
    for (int i: adj[n2]) if (in(i, n1, n2)) {
        dp[n1][n2][1] = max(dp[n1][n2][1], max(solve(i, n2, 0), solve(n1, i, 1))+1);
    }
    return dp[n1][n2][1];
}

main() {
    //ifstream cin("test.in");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	ffi {int a; cin >> a; while (a != 0) {adj[i].pb(a-1); bck[a-1].pb(i); cin >> a;}}
	ffa dp[i][j][0] = dp[i][j][1] = -1;
	ffa {solve(i, j, 0); solve(i, j, 1);}
	if (K == 0) ffi{
        if (dp[i][i][0] > out) {out = dp[i][i][0]; loc = i+1;}
	}
	else {
        ffa dirb[i][j] = dirs[i][j] = -INF;
        /// set dirb
        ffi {
            ffj vis[j] = false;
            dirb[i][i] = 0;
            vis[i] = true;
            n1.push(mp(0, i));
            while (!n1.empty()) {
                int x = n1.top().b; n1.pop();
                for (int y: adj[x]) if (in(y, x, i)) {
                    /// moving forward
                    dirb[i][y] = max(dirb[i][y], dirb[i][x]+1);
                    if (!vis[y]) {
                        n1.push(mp( -((y-i+N)%N) , y));
                        vis[y] = true;
                    }
                }
            }
        }
        //ffa w<< i+1 s j+1 c dirb[i][j]<<e;
        /// set dirs
        ffi {
            ffj vis[j] = false;
            dirs[i][i] = 0;
            vis[i] = true;
            n1.push(mp(0, i));
            while (!n1.empty()) {
                int x = n1.top().b; n1.pop();
                for (int y: adj[x]) if (in(y, i, x)) {
                    /// moving forward
                    dirs[i][y] = max(dirs[i][y], dirs[i][x]+1);
                    if (!vis[y]) {
                        n1.push(mp( (y-i+N)%N , y));
                        vis[y] = true;
                    }
                }
            }
        }
        //ffa w<< i+1 s j+1 c dirs[i][j]<<e;
        /// set Ab
        For (b, 0, N) For (cc, 0, N) {
            /// choose a closest to cc s.t. in(cc, b, a)
            int diff = INF;
            for (int a: bck[b]) if (in(cc, b, a)) {
                diff = min(diff, (a-cc+N)%N);
            }
            Ab[b][cc] = (cc+diff)%N;
            if (diff == INF) Ab[b][cc] = -1;
            //w<< b+1 s cc+1 c diff s Ab[b][cc]+1<<e;
        }
        /// set As
        For (b, 0, N) For (cc, 0, N) {
            /// choose a closest to cc s.t. in(cc, a, b)
            int diff = INF;
            for (int a: bck[b]) if (in(cc, a, b)) {
                diff = min(diff, (cc-a+N)%N);
            }
            As[b][cc] = (cc-diff+N)%N;
            if (diff == INF) As[b][cc] = -1;
            //w<< b+1 s cc+1 c diff s As[b][cc]+1<<e;
        }



        For (b, 0, N) For (cc, 0, N) for (int d: adj[cc]) {
            if (in(b, d, cc)) {
                int a = Ab[b][cc];
                if (a == -1 || dirb[b][cc] == -INF || a == b || a == cc || a == d || b == cc || b == d || cc == d) continue;
                if (in(cc, b, a) == in(d, b, a)) continue;
                //w << a+1 s b+1 s cc+1 s d+1<<e;
                if (2+dirb[b][cc]+max(dp[d][b][0], dp[a][d][1]) > out) {
                    out = 2+dirb[b][cc]+max(dp[d][b][0], dp[a][d][1]);
                    loc = a+1;
                }
            }
            else {
                int a = As[b][cc];
                if (a == -1 || a == b || a == cc || a == d || b == cc || b == d || cc == d) continue;
                if (in(cc, b, a) == in(d, b, a)) continue;
                if (2+dirs[b][cc]+max(dp[d][a][0], dp[b][d][1]) > out) {
                    out = max(out, 2+dirs[b][cc]+max(dp[d][a][0], dp[b][d][1]));
                    loc = a+1;
                }
            }
        }
	}
	//ffa w<< i+1 s j+1 c solve(i, j, 0) s solve(i, j, 1)<<e;
	w<< out <<e<< loc<<e;
}
