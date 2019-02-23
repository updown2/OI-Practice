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
//#define int ll
//500,000,000 operations
const int MAXN = 50, INF=1000000000;
//Global Variables
int R, C, N, dist[15][15], ff[MAXN][MAXN], dp[1<<15][15]; /// dp[bits taken][loc]
char grid[MAXN][MAXN];
bool vis[MAXN][MAXN], vvv[1<<15][15];
queue<pair<int, pair<int, int> > > nex;
queue<pair<int, int> > ord;

void go (int x, int y) {
    if (x < 0 || x == R || y < 0 || y == C || ff[x][y] != -1 || grid[x][y] != 'X') return;
    ff[x][y] = N;
    go(x-1, y); go(x+1, y); go(x, y-1); go(x, y+1);
}

main() {
    //ifstream cin ("test.in");
    ifstream cin("island.in"); ofstream cout("island.out");
    ios_base::sync_with_stdio; cin.tie(0);
    cin >> R >> C;
    For (i, 0, R) For (j, 0, C) {cin >> grid[i][j]; ff[i][j] = -1; vis[i][j] = true;}
    For (i, 0, R) For (j, 0, C) if (grid[i][j] == 'X' && ff[i][j] == -1) {go(i, j); N++;}
    //For (i, 0, R) {For (j, 0, C) w<< ff[i][j]<<" "; w<<e;}
    ffa dist[i][j] = INF;
    ffi dist[i][i] = 0;
    ffi {
        For (x, 0, R) For (y, 0, C) {
            if (grid[x][y] != '.') vis[x][y] = false;
            if (ff[x][y] == i) nex.push(mp(0, mp(x, y)));
        }
        while (!nex.empty()) {
            int d = nex.front().a, x = nex.front().b.a, y = nex.front().b.b;
            nex.pop();
            if (x < 0 || x == R || y < 0 || y == C || vis[x][y]) continue;
            vis[x][y] = true;
            //w<< x+1 s y+1 c d<<e;
            if (ff[x][y] != -1 && ff[x][y] != i) dist[i][ff[x][y]] = min(dist[i][ff[x][y]], d-1);
            else {
                nex.push(mp(d+1, mp(x, y+1)));
                nex.push(mp(d+1, mp(x, y-1)));
                nex.push(mp(d+1, mp(x-1, y)));
                nex.push(mp(d+1, mp(x+1, y)));
            }
        }
    }
    /// Floyd Warshall
    For (k, 0, N) ffa dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
    //ffa w<< i+1 s j+1 c dist[i][j]<<e;
    /// Traveling Salesman
    For (i, 1, 1<<N) ffj dp[i][j] = INF;
    ffi {ord.push(mp(0, i)); vvv[0][i] = true;}
    while (!ord.empty()) {
        int x = ord.front().a, at = ord.front().b; ord.pop();
        //w<< x s at+1 c dp[x][at]<<e;
        ffi if (!(x & (1<<i))) {
            /// try taking the bit
            int y = x | (1<<i);
            dp[y][i] = min(dp[y][i], dp[x][at]+dist[at][i]);
            if (!vvv[y][i]) {
                vvv[y][i] = true;
                ord.push(mp(y, i));
            }
        }
    }
    int out = INF;
    ffi out = min(out, dp[(1<<N) - 1][i]);
    w<< out<<e;
}
