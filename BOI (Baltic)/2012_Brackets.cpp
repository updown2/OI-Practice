/*
imagine that brackets and parenthesis are the same. this works bc options such as ([)] is not valid
dp[index][# of open parenthesis] = # of ways to reach this
sliding window
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 1, N+1)
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
#define int ll
const int MAXN=15002, MOD=1000000009;
///500,000,000
int N, dp[2][MAXN];
string in;

main() {
    //ifstream cin("test.in");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> in; in = ' ' + in;
	dp[0][0] = 1;
	ffi {
	    if (in[i] == '(') {
            dp[1][0] = dp[0][1];
            For (j, 1, (N+1)/2+1) {
                dp[1][j] = (dp[0][j-1] + dp[0][j+1])%MOD;
            }
	    }
	    else {
            For (j, 0, (N+1)/2+1) {
                dp[1][j] = dp[0][j+1];
            }
	    }
	    //For (j, 0, (N+1)/2+1) w<< i s j c dp[1][j]<<e; w<<e;
	    swap(dp[0], dp[1]);
	}
	w<< dp[0][0]<<e;
}
