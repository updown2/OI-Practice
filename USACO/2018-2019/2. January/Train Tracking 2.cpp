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
#define int ll
//500,000,000 operations
const int MAXN = 100001, MOD = 1000000007;
//Global Variables
int N, dp[MAXN], K, sum, mul, inp[MAXN], vals[MAXN], out=1;
bool done[MAXN];

int ppp(int a, int b) {
    int ret = 1;
    For (i, 0, b) {ret *= a; ret %= MOD;}
    /// not the issue
    //assert(ret > 0);
    return ret;
}

int solve(int N2, int Ci) {
    //w<< "solve" s N2 s Ci<<e;
    dp[0] = 1;
    sum = 1;
    mul = ppp(1000000000-Ci, K);
    For (i, 1, N2+1) {
        //w<< "before" s sum<<e;
        dp[i] = sum;
        int x = sum;
        sum *= (1000000000-Ci);
        sum += x;
        sum %= MOD;
        if (i-K >= 0) {
            sum -= (dp[i-K]*mul)%MOD;
            if (sum < 0) sum += MOD;
            dp[i-K] = 0;
        }
        //w<< dp[i]<< " "; w<<e;
    }
    //assert(sum > 0);
    return sum;
}

main() {
    //ifstream cin("test.in");
    ifstream cin("tracking2.in"); ofstream cout("tracking2.out");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K; For (i, 0, N-K+1) cin >> inp[i];
    /// check forward
    For (i, 0, N-K) if (inp[i] < inp[i+1]) {vals[i] = inp[i]; done[i] = true;}
    /// check backwards
    For (i, 1, N-K+1) if (inp[i-1] > inp[i]) {vals[i+K-1] = inp[i]; done[i+K-1] = true;}
    //ffi w<< done[i]<<e;
    /// find all the empty segments
    int i=0;
    while (i < N) {
        if (done[i]) {i++; continue;}
        int j = i;
        while (j+1 < N && !done[j+1]) j++;
        //w<< "range" s i s j<<e;
        /// range is i to j
        int len = j-i+1;
        if (len < K) {
            int sm = 1;
            if (j+1 < N) sm = max(sm, vals[j+1]);
            if (i-1 >= 0) sm = max(sm, vals[i-1]);
            out *= ppp((1000000000-sm+1), len);
            out %= MOD;
        }
        else {
            out *= solve(len, inp[i]); /// CHECK INP[I]
            out %= MOD;
        }
        i = j+1;
        //assert(out > 0);
    }
    w<< out<<e;
}
