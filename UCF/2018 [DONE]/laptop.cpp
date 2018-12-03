#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, Q)
#define ffa ffi ffj
#define s <<" "<<
//#define c <<" : "<<
#define w cout
#define e endl // "/n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
//500,000,000 operations
const int MAXN = 2000, INF = 100000000000000;
//Global Variables
int T, N, p2[16];
double R, dist[16], dp[1<<16][16];
vector<int> at[16];
string c;

bool poss(int a, int b) {
    if (c[a] == 'B' && c[b] != 'B') return false;
    if (c[a] == 'G' && c[b] == 'R') return false;
    return true;
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    p2[0] = 1; For (i, 1, 16) p2[i] = 2*p2[i-1];
    For (i, 0, 1<<15) at[__builtin_popcount(i)].pb(i);
    For (t, 1, T+1) {
        cin >> N >> R >> c;
        dist[0] = dist[N] = 0; For (i, 1, N+1) dist[i] = 2*R*sin(M_PI*i/(double)N);;
        //ffi w<< dist[i]<<e;
        For (i, 0, 1<<N) For (j, 0, N) dp[i][j] = INF; ffi dp[0][i] = 0;
        For (x, 0, N) {
            /// number taken
            for (int j: at[x]) {
                if (j >= p2[N]) break;
                ffi {
                    //if (dp[j][i] < INF) {For (i, 0, N) w<< (((1<<i)&j)>0); w s i s dp[j][i]<<e;}
                    For (k, 0, N) if (j|(1<<k) != j && poss(i, k)) {
                        /// from i to k
                        dp[j|(1<<k)][k] = min(dp[j|(1<<k)][k], dp[j][i]+dist[abs(i-k)]);
                    }
                }
            }
        }
        double out = INF;
        ffi out = min(out, dp[(1<<N)-1][i]);
        w.setf(std::ios::fixed,std::ios::floatfield); w.precision(3);
        w<< "Scenario #"<<t<<":" s out <<e;
    }
}
