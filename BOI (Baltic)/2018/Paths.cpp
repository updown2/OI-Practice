/*
dp[node][colors used] = max paths starting at node using only unused colors
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
#define int ll
//500,000,000 operations
const int MAXN = 300000, INF = 1000000000000000000;
//Global Variables
int N, M, K, color[MAXN], out, dp[MAXN][32];
vector<int> adj[MAXN];

void get(int at, int x) {
    if (dp[at][x] != -1) return;
    int c = color[at];
    if (x & (1<<c)) {
        /// already used the color
        dp[at][x] = 0;
        return;
    }
    dp[at][x] = 1; /// add path with one node, removing it later
    int y = (x | (1<<c)); /// now using the color
    //w<< "new:"; For (i, 0, 5) w s (x & (1<<i)); w<<e;
    int ret = 0;
    for (int i: adj[at]) {
        get(i, y);
        ret += dp[i][y];
    }
    dp[at][x] += ret;
    //w<< at+1<< " "; For (i, 0, 5) w <<((x & (1<<i))>0); w s ":" s dp[at][x]<<e;
    return;
}

main() {
	//ifstream cin ("test.in");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> K;
	ffi {cin >> color[i]; color[i]--; For (j, 0, 32) dp[i][j] = -1;}
	ffj {int a, b; cin >> a >> b; a--; b--; adj[a].pb(b); adj[b].pb(a);}
	ffi {get(i, 0); out += dp[i][0];}
	out -= N; /// remove paths with only one node
	w<< out<<e;
}
