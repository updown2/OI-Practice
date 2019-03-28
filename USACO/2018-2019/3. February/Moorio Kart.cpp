#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, N)
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
const int MAXN = 1500, MOD=1000000007;
//Global Variables
int N, M, X, Y, cnt[MAXN][2501], tree[MAXN], N2, sum[MAXN], dp_old[2501], sum_old, dp[2501], nsum;
vector<pair<int, int> > adj[MAXN];

void go_tree(int at) {
    if (tree[at] != -1) return;
    tree[at] = N2;
    for (auto i: adj[at]) go_tree(i.a);
}
void get_len(int at, int d, int p, bool good=true) {
    if (good) {
        if (d < Y) cnt[tree[at]][d]++;
        else {
            cnt[tree[at]][Y]++;
            sum[tree[at]] += d;
        }
    }
    for (auto i: adj[at]) if (i.a != p) get_len(i.a, d+i.b, at);
}

main() {
    //ifstream cin ("test.in");
    ifstream cin("mooriokart.in"); ofstream cout("mooriokart.out");
    ios_base::sync_with_stdio; cin.tie(0);
    cin >> N >> M >> X >> Y;
    Y = Y-(N-M)*X; Y = max(Y, (int)0);
    For (j, 0, M) {int a, b, d; cin >> a >> b >> d; a--; b--; adj[a].pb(mp(b, d)); adj[b].pb(mp(a, d));}
    ffi tree[i] = -1;
    ffi if (tree[i] == -1) {go_tree(i); N2++;} /// floodfill trees
    ffi {
        /// start at node i
        get_len(i, 0, -1, false);
    }
    sum[0] /= 2; For (j, 0, Y+1) cnt[0][j] /= 2; /// every path should only be counted once
    For (i, 0, N2) sum[i] %= MOD;
    //For (i, 0, N2) {w<< "i:" s i+1 c sum[i]<<e; For (j, 0, 10) if (cnt[i][j] != 0) w<< j s cnt[i][j]<<e;}
    For (i, 0, Y+1) dp[i] = cnt[0][i]; nsum = sum[0];
    For (j, 1, N2) {
        /// move to old
        For (i, 0, Y+1) {dp_old[i] = dp[i]; dp[i] = 0;} sum_old = nsum; nsum = 0;
        /// knapsack
        For (i, 0, Y) if (cnt[j][i] != 0) For (p, 0, Y) if (dp_old[p] != 0) {
            /// combine i & p
            if (i+p < Y) {
                dp[i+p] += cnt[j][i]*dp_old[p];
                dp[i+p] %= MOD;
            }
            else {
                dp[Y] += cnt[j][i]*dp_old[p];
                dp[Y] %= MOD;
                nsum += dp_old[p]*cnt[j][i]*(i+p);
                nsum %= MOD;
            }
        }
        /// previous N-1 >= Y
        For (p, 0, Y) {
            dp[Y] += dp_old[Y]*cnt[j][p];
            dp[Y] %= MOD;
            nsum += cnt[j][p]*p*dp_old[Y] + sum_old*cnt[j][p];
            nsum %= MOD;
        }
        /// current >= Y
        For (i, 0, Y) {
            dp[Y] += cnt[j][Y]*dp_old[i];
            dp[Y] %= MOD;
            nsum += dp_old[i]*i*cnt[j][Y] + sum[j]*dp_old[i];
            nsum %= MOD;
        }
        /// i = p = Y
        dp[Y] += cnt[j][Y]*dp_old[Y];
        dp[Y] %= MOD;
        nsum += sum_old*cnt[j][Y] + sum[j]*dp_old[Y];
        nsum %= MOD;
    }
    //w<< nsum s dp[Y]<<e;
    nsum += X*(N-M)*dp[Y];
    assert(nsum >= 0);
    nsum %= MOD;
    //w<< nsum<<e;
    int mul = N-M-1;
    For (i, 1, mul+1) {
        nsum *= i;
        nsum %= MOD;
    }
    w<< nsum<<e;
}
