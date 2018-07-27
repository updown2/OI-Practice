/*
dp[loc][prev01][prev00][prev[11][prev10] = max coal
0: None
1: M
2: B
3: F
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, K+1)
#define ffa ffi ffj
#define s <<" "<<
#define c <<" : "<<
#define w cout
//#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
//#define int ll
//500,000,000 operations
const int MAXN = 100000, INF = 100000000;
//Global Variables
int N, dp[2][4][4][4][4], out, inp[MAXN];
string in;

int cnt(int a, int b, int d) {
    /// make a the smallest
    if (a > b) swap(a, b);
    if (a > d) swap(a, d);
    /// b<d
    if (b>d) swap(b, d);
    if (a == 0 && b == 0 && d == 0) return 0;
    if (a == 0 && b == 0) return 1;
    if (a == 0) return cnt(b, b, d);
    if (a == b && a == d) return 1;
    if (a == b || a == d || b == d) return 2;
    return 3;
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> in;
    ffi {
        if (in[i] == 'M') inp[i] = 1;
        else if (in[i] == 'B') inp[i] = 2;
        else inp[i] = 3;
    }
    dp[0][0][inp[0]][0][0] = 1;
    /// Push dp
    For (i, 0, N-1) {
        For (d, 0, 4) For (e, 0, 4) For (f, 0, 4) For (g, 0, 4) {
            if (dp[i%2][d][e][f][g] == 0) continue;
            //w<< i s d s e s f s g c dp[i][d][e][f][g]<<endl;
            dp[(i+1)%2][e][inp[i+1]][f][g] = max(dp[(i+1)%2][e][inp[i+1]][f][g], dp[i%2][d][e][f][g] + cnt(d, e, inp[i+1]));
            dp[(i+1)%2][d][e][g][inp[i+1]] = max(dp[(i+1)%2][d][e][g][inp[i+1]], dp[i%2][d][e][f][g] + cnt(f, g, inp[i+1]));
            dp[i%2][d][e][f][g] = 0;
        }
    }
    For (d, 0, 4) For (e, 0, 4) For (f, 0, 4) For (g, 0, 4) {
        out = max(out, dp[(N-1)%2][d][e][f][g]);
    }
    w<< out<<endl;
}
