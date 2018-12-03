/*
https://codeforces.com/blog/entry/57637?#comment-413356
*/
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
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
const int MAXN=3000, INF=10000000000;
///500,000,000
int N, M, out, dp[2*MAXN][3]; /// 0 is none, 1 is up, 2 is side
char grid[MAXN][MAXN];
int up[MAXN][MAXN], side[MAXN][MAXN];

main() {
    //ifstream cin("test.in");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	ffa cin >> grid[i][j];
	For (i, 1, N-1) ffj if (grid[i-1][j] == 'R' && grid[i][j] == 'G' && grid[i+1][j] == 'W') up[i][j] = 1;
	ffi For (j, 1, M-1) if (grid[i][j-1] == 'R' && grid[i][j] == 'G' && grid[i][j+1] == 'W') side[i][j] = 1;
	For (i, 1, N+M-2) {
	    bool st = true;
	    int curr = 0;
        for (int x =i, y = 0; x >= 0 && y < M; x--, y++) {
            if (x >= N) continue;
            //w<< i c x s y<<e;
            if (st) {
                dp[y][0] = 0;
                dp[y][1] = up[x][y];
                dp[y][2] = side[x][y];
                st = false;
            }
            else {
                dp[y][0] = max(dp[y-1][0], max(dp[y-1][1], dp[y-1][2]));
                dp[y][1] = up[x][y] + max(dp[y-1][0], dp[y-1][1]);
                dp[y][2] = side[x][y] + max(dp[y-1][0], dp[y-1][2]);
            }
            curr = max(max(curr, dp[y][0]), max(dp[y][1], dp[y][2]));
	    }
	    out += curr;
    }
    w<< out<<e;
}
