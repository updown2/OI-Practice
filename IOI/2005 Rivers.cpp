/*
dp[node][mills added in the subtree][length from root to next mill (use a map to go from index to the value)]
if a node has > 2 children, split it into two kids. keep the first kid and add a child with weight = 0 as the second child.
attach the rest of the children as children of the second child
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, P)
#define ffa ffi ffj
#define s <<" "<<
#define c <<" : "<<
#define w cout
#define e endl//"\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
//500,000,000 operations
const int MAXN = 200, INF = 2000000000;
//Global Variables
int N, K, W[MAXN], dp[MAXN][51][MAXN/2+1], dep[MAXN], BL;
bool re[MAXN]; /// real node or added node?
set<int> store;
map<int, int> trans, bk; /// index --> L
vector<pair<int, int> > adj[MAXN];

void rs (int at) { /// restructure
    if (adj[at].size() > 2) {
        /// make a node at N and connect adj[1...] to that node
        while (adj[at].size() > 1) {
            auto x = adj[at][adj[at].size()-1];
            adj[at].pop_back();
            adj[N].pb(x);
        }
        adj[at].pb(mp(N, 0)); N++;
    }
    for (auto i: adj[at]) rs(i.a);
}
void sd (int at, int d) {
    dep[at] = d;
    for (auto i: adj[at]) sd(i.a, d+i.b);
}
void go (int at) {
    for (auto i: adj[at]) go(i.a);
    For (j, 0, K+1) {
        for (int l=BL-1; l>=0; l--) {
            int L = trans[l];
            if (L > dep[at]) continue; /// not used here or in the future bc depth only decreases
            if (L == dep[at] && re[at]) {
                /// place a mill here
                if (j == 0) continue; /// don't need
                For (k, 0, j) {
                    int x1 = 0, x2 = 0;
                    if (adj[at].size() > 0) {
                        int n1 = adj[at][0].a;
                        x1 = dp[n1][k][l];
                        if (re[n1]) x1 = min(x1, dp[n1][k][bk[dep[n1]]]);
                    }
                    if (adj[at].size() > 1) {
                        int n2 = adj[at][1].a;
                        x2 = dp[n2][j-k-1][l];
                        if (re[n2]) x2 = min(x2, dp[n2][j-k-1][bk[dep[n2]]]);
                    }

                    //if (adj[at].size() > 0) x1 = min(dp[adj[at][0].a][k][l], dp[adj[at][0].a][k][bk[dep[adj[at][0].a]]]);
                    //if (adj[at].size() > 1) x2 = min(dp[adj[at][1].a][j-k-1][l], dp[adj[at][1].a][j-k-1][bk[dep[adj[at][1].a]]]);
                    dp[at][j][l] = min(dp[at][j][l], x1+x2);
                }
                continue;
            }
            /// don't place a mill here
            For (k, 0, j+1) {
                int x1 = 0, x2 = 0;
                if (adj[at].size() > 0) {
                    int n1 = adj[at][0].a;
                    x1 = dp[n1][k][l];
                    if (re[n1]) x1 = min(x1, dp[n1][k][bk[dep[n1]]]);
                }
                if (adj[at].size() > 1) {
                    int n2 = adj[at][1].a;
                    x2 = dp[n2][j-k][l];
                    if (re[n2]) x2 = min(x2, dp[n2][j-k][bk[dep[n2]]]);
                }

                //if (adj[at].size() > 0) x1 = min(dp[adj[at][0].a][k][l], dp[adj[at][0].a][k][bk[dep[adj[at][0].a]]]);
                //if (adj[at].size() > 1) x2 = min(dp[adj[at][1].a][j-k][l], dp[adj[at][1].a][j-k][bk[dep[adj[at][1].a]]]);
                dp[at][j][l] = min(dp[at][j][l], x1+x2+W[at]*(dep[at]-L));
            }
        }
    }
    //For (j, 0, K+1) {For (l, 0, BL) {int L = trans[l]; if (L > dep[at]) continue;w<< at s j s L c dp[at][j][l]<<e;}}
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K; N++;
    For (i, 1, N) {
        re[i] = true;
        int a, b;
        cin >> W[i] >> a >>b;
        adj[a].emplace_back(i, b);
    }
    rs(0);
    ffi For (j, 0, K+1) For (k, 0, 101) dp[i][j][k] = INF;
    //ffi {w<<i << ":"<<e; for (auto j: adj[i]) w<< j.a s j.b<<e;}
    sd(0, 0);
    //ffi w<< i c dep[i]<<e;
    ffi store.insert(dep[i]);
    for (auto j: store) {
        trans[BL] = j;
        bk[j] = BL;
        BL++;
    }
    go(0);
    w<< dp[0][K][0]<<e;
}
