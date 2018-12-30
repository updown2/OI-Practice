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
#define e endl//"\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
//#define int ll
const int MAXN=1000000, INF=1000000000;
///500,000,000
int N, inp[MAXN], dp[MAXN][3];

main() {
    //ifstream cin("test.in");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N; ffi {cin >> inp[i]; dp[i][0] = dp[i][1] = dp[i][2] = INF;}
	dp[0][inp[0]+1] = 0;
	For (i, 1, N) {
        if (inp[i] == -1) {
            dp[i][0] = dp[i-1][0];
            //dp[i][1] = INF;
            dp[i][2] = dp[i-1][2]+2;
        }
        else if (inp[i] == 0) {
            dp[i][0] = dp[i-1][0]+1;
            dp[i][1] = min(dp[i-1][0], dp[i-1][1]);
            dp[i][2] = dp[i-1][2]+1;
        }
        else {
            dp[i][0] = dp[i-1][0]+2;
            dp[i][1] = dp[i-1][0]+1;
            dp[i][2] = min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2]));
        }
        //w<< i+1 c dp[i][0] s dp[i][1] s dp[i][2]<<e;
	}
	int ans = min(dp[N-1][0], min(dp[N-1][1], dp[N-1][2]));
	if (ans > 10*N) w<< "BRAK"<<e;
	else w<< ans<<e;
}
