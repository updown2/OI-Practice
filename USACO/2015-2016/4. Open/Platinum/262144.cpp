#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, 60)
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
//500,000,000 operations
const int MAXN = 262145;
//Global Variables
int N, inp[MAXN], dp[MAXN][60], out;

main() {
    //ifstream cin ("test.in");
    ifstream cin("262144.in"); ofstream cout("262144.out");
    ios_base::sync_with_stdio; cin.tie(0);
    cin >> N;
    ffi cin >> inp[i];
    For (i, 0, N+1) ffj dp[i][j] = -1;
    For (j, 1, 60) ffi {
        if (inp[i] == j) dp[i][j] = i;
        else if (dp[i][j-1] == -1) continue;
        else dp[i][j] = dp[dp[i][j-1]+1][j-1];
        if (dp[i][j] != -1) out = j;
        //w<< i+1 s j c dp[i][j]+1 s inp[i] << e;
    }
    w<< out<<e;
}
