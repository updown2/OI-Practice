/*
https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/COCI/official/2017/contest4_solutions/solutions.pdf
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 1, N+1)
#define ffj For(j, 0, 100001)
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
const int MAXN=501, INF=1000000000;
///500,000,000
int N, inp[MAXN], dp[MAXN][100001], tot;
/// dp[ind][abs(diff money)] = min left over money

main() {
    //ifstream cin("test.in");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	ffi {cin >> inp[i]; tot += inp[i];}
	For (i, 0, N+1) ffj dp[i][j] = INF;
	dp[0][0] = 0;
	ffa {
        dp[i][j] = min(dp[i][j], dp[i-1][j]+inp[i]);
        if (j >= inp[i]) dp[i][j] = min(dp[i][j], dp[i-1][j-inp[i]]);
        if (j+inp[i] < 100001) dp[i][j] = min(dp[i][j], dp[i-1][j+inp[i]]);
        if (inp[i] >= j) dp[i][j] = min(dp[i][j], dp[i-1][inp[i]-j]);
	}
	w<< dp[N][0] + (tot-dp[N][0])/2<<e;
}
