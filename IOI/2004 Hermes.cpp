#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 1, N+1)
#define ffj For(j, 0, N+1)
#define ffa ffi ffj
#define s <<" "<<
#define c <<" : "<<
#define w cout
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
//#define int ll
const int MAXN = 20001, INF = 1000000000;
//500,000,000 operations
int N, loc[MAXN][2], dp[2][2][2001], out=INF;
/// dp[i%2][0: x is fixed, 1: y is fixed][other x/y coordinate]

main() {
    //ifstream cin ("test.in");
    ios_base::sync_with_stdio; cin.tie(0);
    cin >> N;
    ffi cin >> loc[i][0] >> loc[i][1];
    ffj {loc[j][0] += 1000; loc[j][1] += 1000;}
    For (i, 0, 2001) dp[0][0][i] = dp[0][1][i] = INF;
    dp[0][0][1000] = dp[0][1][1000] = 0;
    ffi {
        int cu = i%2; int pr = 1-cu;
        int x = loc[i][0], y = loc[i][1], xp = loc[i-1][0], yp = loc[i-1][1];
        /// reset
        For (j, 0, 2001) dp[cu][0][j] = dp[cu][1][j] = INF;
        /// transition
        For (j, 0, 2001) {
            /// point 1 is (xp, j)
            /// can go to (x, j) or (xp, y)
            dp[cu][0][j] = min(dp[cu][0][j], dp[pr][0][j] + abs(xp-x));
            dp[cu][1][xp] = min(dp[cu][1][xp], dp[pr][0][j] + abs(j-y));
            /// point 2 is (j, yp)
            /// can go to (x, yp) or (j, y)
            dp[cu][0][yp] = min(dp[cu][0][yp], dp[pr][1][j] + abs(j-x));
            dp[cu][1][j] = min(dp[cu][1][j], dp[pr][1][j] + abs(yp-y));
        }
        //For (j, 0, 2001) {if (dp[cu][0][j] < INF) w<< i s x-1000 s j-1000 c dp[cu][0][j]<<e; if (dp[cu][1][j] < INF) w<< i s j-1000 s y-1000 c dp[cu][1][j]<<e;}
    }
    For (j, 0, 2001) {out = min(out, min(dp[N%2][0][j], dp[N%2][1][j]));}
    w<< out<<e;
}
