/*
dp[node 1][node 2][0/1] = is it possible to take all the edges in the range ending at node 1/2 (based on the third dimension)
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
const int MAXN=1000;//, INF=1000000000000000000;
///500,000,000
int N, M, loc=-1;
bool dp[MAXN][MAXN][2], edge[MAXN][MAXN], done[MAXN][MAXN][2];

bool solve(int n1, int n2, int at) {
    if (done[n1][n2][at]) return dp[n1][n2][at];
    done[n1][n2][at] = true;
    //w<< n1 s n2 s at<<e;
    /// range is n1+1 to n2-1  (n1+1)%N to (n2-1+N)%N
    if ((n1+1)%N == n2) {dp[n1][n2][at] = edge[n1][n2]; return dp[n1][n2][at];}
    if (at == 0) {
        /// previous edge was from (n1+1)%N to n1 or n2 to n1
        /// n2 to n1
        if (edge[n2][n1] && solve((n1+1)%N, n2, 1)) dp[n1][n2][0] = true;
        /// (n1+1)%N to n1
        if (edge[(n1+1)%N][n1] && solve((n1+1)%N, n2, 0)) dp[n1][n2][0] = true;
        return dp[n1][n2][0];
    }
    /// previous edge was from (n2-1+N)%N to n2 or n1 to n2
    /// n1 to n2
    if (edge[n1][n2] && solve(n1, (n2-1+N)%N, 0)) dp[n1][n2][1] = true;
    /// (n2-1+N)%N to n2
    if (edge[(n2-1+N)%N][n2] && solve(n1, (n2-1+N)%N, 1)) dp[n1][n2][1] = true;
    return dp[n1][n2][1];
}

main() {
    //ifstream cin("test.in");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	For (i, 0, M) {int a, b; cin >> a >> b; a--; b--; edge[a][b] = edge[b][a] = true;}
	//ffa {solve(i, j, 0); solve(i, j, 1);}
	int at;
	ffi{
        if (solve(i, (i-1+N)%N, 0)) {loc = i; at = 0;}
        if (solve(i, (i-1+N)%N, 1)) {loc = i; at = 1;}
	}
	//ffa w<< i+1 s j+1 c solve(i, j, 0) s solve(i, j, 1) <<e;
	if (loc == -1) {w<<-1<<e; return 0;}
	int n1 = loc, n2 = (loc-1+N)%N;
	For (k, 0, N) {
        if (at == 0) w<< n1+1<<e;
        else w<< n2+1<<e;
        //w<< n1+1 s n2+1 s at<<e;
        if ((n1+1)%N == n2) {
            at = 1-at;
            continue;
        }
        if (at == 0) {
            /// previous edge was from (n1+1)%N to n1 or n2 to n1
            /// n2 to n1
            if (edge[n2][n1] && dp[(n1+1)%N][n2][1]) {
                n1 = (n1+1)%N;
                at = 1;
                continue;
            }
            /// (n1+1)%N to n1
            if (edge[(n1+1)%N][n1] && dp[(n1+1)%N][n2][0]) {
                n1 = (n1+1)%N;
                continue;
            }
        }
        else {
            /// previous edge was from (n2-1+N)%N to n2 or n1 to n2
            /// n1 to n2
            if (edge[n1][n2] && dp[n1][(n2-1+N)%N][0]) {
                n2 = (n2-1+N)%N;
                at = 0;
                continue;
            }
            /// (n2-1+N)%N to n2
            if (edge[(n2-1+N)%N][n2] && dp[n1][(n2-1+N)%N][1]) {
                n2 = (n2-1+N)%N;
                continue;
            }
        }
	}
}
