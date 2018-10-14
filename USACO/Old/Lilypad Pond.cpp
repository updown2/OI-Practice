/*
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(ll i=a; i<b; i++)
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
const int MAXN=30, INF=1000000000;
///500,000,000
int N, M, grid[MAXN][MAXN], dist[MAXN][MAXN], ways[MAXN][MAXN];
bool visited[MAXN][MAXN];
vector<pair<int, int> > adj[MAXN][MAXN];
queue<pair<int, pair<int, int> > > next1;

void go1 (int sx, int sy, int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >= M || visited[x][y] || grid[x][y] == 2) return;
    visited[x][y] = true;
    if (sx != x || sy != y) {
        /// not starting cell
        if (grid[x][y] != 1) {
            /// reached an end
            adj[sx][sy].pb(mp(x, y));
            return;
        }
    }
    go1(sx, sy, x-1, y+2); go1(sx, sy, x-1, y-2); go1(sx, sy, x+1, y+2); go1(sx, sy, x+1, y-2);
    go1(sx, sy, x-2, y+1); go1(sx, sy, x-2, y-1); go1(sx, sy, x+2, y+1); go1(sx, sy, x+2, y-1);
}

main() {
    ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    ffa cin >> grid[i][j];

    ffa if (grid[i][j] != 1 && grid[i][j] != 2) {
        For (k, 0, N) For (l, 0, M) visited[k][l] = false;
        go1(i, j, i, j);
        //w<< i s j<<":"<<e; for (auto k: adj[i][j]) w<< k.a s k.b<<e;
    }
    ffa visited[i][j] = false, dist[i][j] = INF;
    ffa if (grid[i][j] == 3) {
        next1.push(mp(-1, mp(i, j))); ways[i][j] = 1;
    }

    while (!next1.empty()) {
        int d = next1.front().a, x = next1.front().b.a, y = next1.front().b.b; next1.pop();
        if (visited[x][y]) continue;
        visited[x][y] = true;
        dist[x][y] = d;
        for (auto i: adj[x][y]) {
            if (dist[i.a][i.b] == dist[x][y] -1) ways[x][y] += ways[i.a][i.b];
            next1.push(mp(d+1, i));
        }
    }

    ffa if (grid[i][j] == 4) {
        if (dist[i][j] == INF) w<< -1<<e;
        else w<< dist[i][j]<<e<<ways[i][j]<<e;
    }
}
