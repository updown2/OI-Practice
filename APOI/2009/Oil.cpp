/*
cut the grid twice
store the max of the 4 corners prefix
compute ranges max of rows and cols (separate)
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(ll i=a; i<b; i++)
#define ffi For(i, 1, N+1)
#define ffj For(j, 1, M+1)
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
const int MAXN = 1501, INF = 1000000000000000000;
//Global Variables
int N, M, K, pre[MAXN][MAXN], tl[MAXN][MAXN], tr[MAXN][MAXN], bl[MAXN][MAXN], br[MAXN][MAXN], out, rb[MAXN], cb[MAXN], bcol[MAXN][MAXN], brow[MAXN][MAXN];
///                           (1, 1)          (1, M)          (N, 1)          (N, M)

main() {
	//ifstream cin ("test.in");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> K;
	ffa {
        cin >> pre[i][j];
        pre[i][j] += pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
	}
	//For (i, 1, K+1) For (j, 1, K+1) tl[i][j] =  tr[i][M-j+1] = bl[N-i+1][j] = br[N-i+1][M-j+1] = -INF;
	ffa {
        if (i < K || j < K) {tl[i][j] = -INF; continue;}
        int box = pre[i][j] - pre[i-K][j] - pre[i][j-K] + pre[i-K][j-K];
        //w<< i s j s ":" s box<<e;
        tl[i][j] = max(max(tl[i-1][j], tl[i][j-1]), box);
	}
	ffi for (int j=M; j>=1; j--) {
        if (i < K || M-j+1 < K) {tr[i][j] = -INF; continue;}
        int box = pre[i][j+K-1] - pre[i-K][j+K-1] - pre[i][j-1] + pre[i-K][j-1];
        //w<< i s j s ":" s box<<e;
        tr[i][j] = max(max(tr[i-1][j], tr[i][j+1]), box);
	}
	for (int i=N; i>=1; i--) ffj {
        if (j < K || N-i+1 < K) {bl[i][j] = -INF; continue;}
        int box = pre[i+K-1][j] - pre[i+K-1][j-K] - pre[i-1][j] + pre[i-1][j-K];
        //w<< i s j s ":" s box<<e;
        bl[i][j] = max(max(bl[i+1][j], bl[i][j-1]), box);
	}
	for (int i=N; i>=1; i--) for (int j=M; j>=1; j--) {
        if (M-j+1 < K || N-i+1 < K) {br[i][j] = -INF; continue;}
        int box = pre[i+K-1][j+K-1] - pre[i+K-1][j-1] - pre[i-1][j+K-1] + pre[i-1][j-1];
        //w<< i s j s ":" s box<<e;
        br[i][j] = max(max(br[i+1][j], br[i][j+1]), box);
	}
	//ffi {ffj w<< tl[i][j]<< " "; w<<e;}
	//ffi {ffj w<< tr[i][j]<< " "; w<<e;}
	//ffi {ffj w<< bl[i][j]<< " "; w<<e;}
	//ffi {ffj w<< br[i][j]<< " "; w<<e;}
	ffi {
	    if (i < K) {rb[i] = -INF; continue;}
        int curr = -INF;
        For (j, K, M+1) curr = max(curr, pre[i][j] - pre[i-K][j] - pre[i][j-K] + pre[i-K][j-K]);
        rb[i] = curr;
        //w<< i s curr<<e;
	}
	ffj {
	    if (j < K) {cb[j] = -INF; continue;}
        int curr = -INF;
        For (i, K, N+1) curr = max(curr, pre[i][j] - pre[i-K][j] - pre[i][j-K] + pre[i-K][j-K]);
        cb[j] = curr;
        //w<< j s curr<<e;
	}
	ffi {
        int curr = -INF;
        For (j, i, N+1) {
            curr = max(curr, rb[j]);
            brow[i][j] = curr;
        }
	}
	For (i, 1, M+1) {
        int curr = -INF;
        For (j, i, M+1) {
            curr = max(curr, cb[j]);
            bcol[i][j] = curr;
        }
	}
	/// split into 3 rows
	For (i, K, M+1) For (j, i+K, M+1) {
	    if (j+K > M) break;
        /// blocks are 1-i, i+1-j, j+1-M
        out = max(out, tl[N][i] + bcol[i+K][j] + tr[N][j+1]);
        //w<< i s j s ":" s tl[N][i] s bcol[i+K][j] s tr[N][j+1] <<e;
	}
	/// split into 3 cols
	For (i, K, N+1) For (j, i+K, N+1) {
	    if (j+K > N) break;
        /// blocks are 1-i, i+1-j, j+1-N
        out = max(out, tl[i][M] + brow[i+K][j] + br[j+1][1]);
        //w<< i s j s ":" s tl[i][M] s brow[i+K][j] s br[j+1][1] <<e;
	}
	/// split in both directions
	ffa {
        /// top left, top right, and bottom
        out = max(out, tl[i][j] + tr[i][j+1] + br[i+1][1]);
        /// top left, bottom left, and right
        out = max(out, tl[i][j] + bl[i+1][j] + br[1][j+1]);
        /// top, bottom left, and bottom right
        out = max(out, tl[i][N] + bl[i+1][j] + br[i+1][j+1]);
        /// left, top right, and bottom right
        out = max(out, tl[N][j] + tr[i][j+1] + br[i+1][j+1]);
	}
	w<< out<<e;
}
