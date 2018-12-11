/*
vd[i][j] = distance from 'V' to (i, j)
cover[i][j] = in how many moves will V be in the same row or col as (i, j) (without being blocked by the island)
if (cover[i][j] == 0) cover[i][j] = 1 because the ship cannot attack before the 1st move
bfs from your starting location, you cannot go to a square where cover[i][j] <= time to reach (i, j) in the bfs
*/
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
const int MAXN=700, INF=1000000000000000000;
///500,000,000
int N, M, vd[MAXN][MAXN], cover[MAXN][MAXN];
char inp[MAXN][MAXN];
bool vis[MAXN][MAXN];
queue<pair<int, pair<int, int> > > next1;

main() {
    //ifstream cin("test.in");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	ffa {vd[i][j] = cover[i][j] = INF; cin >> inp[i][j]; if (inp[i][j] == 'V') next1.push(mp(0, mp(i, j)));}
	while (!next1.empty()) {
        int d = next1.front().a, x = next1.front().b.a, y = next1.front().b.b; next1.pop();
        if (x < 0 || y < 0 || x >=N || y >= M || vd[x][y] < INF || inp[x][y] == 'I') continue;
        vd[x][y] = d;
        next1.push(mp(d+1, mp(x+1, y)));
        next1.push(mp(d+1, mp(x-1, y)));
        next1.push(mp(d+1, mp(x, y+1)));
        next1.push(mp(d+1, mp(x, y-1)));
	}
	//ffi {ffj w<< vd[i][j]<< " "; w<<e;}
	ffa if (vd[i][j] < INF) {
	    cover[i][j] = min(cover[i][j], vd[i][j]);
	    for (int k=i+1; k<N && inp[k][j] != 'I'; k++) cover[k][j] = min(cover[k][j], vd[i][j]);
	    for (int k=i-1; k>=0 && inp[k][j] != 'I'; k--) cover[k][j] = min(cover[k][j], vd[i][j]);
	    for (int k=j+1; k<M && inp[i][k] != 'I'; k++) cover[i][k] = min(cover[i][k], vd[i][j]);
	    for (int k=j-1; k>=0 && inp[i][k] != 'I'; k--) cover[i][k] = min(cover[i][k], vd[i][j]);
	}
	ffa cover[i][j] = max(cover[i][j], (int)1);
	//ffi {ffj w<< cover[i][j]<< " "; w<<e;}
	ffa if (inp[i][j] == 'Y') next1.push(mp(0, mp(i, j)));
	while (!next1.empty()) {
        int d = next1.front().a, x = next1.front().b.a, y = next1.front().b.b; next1.pop();
        //w<< "entered" c x s y s cover[x][y]<<e;
        if (x < 0 || y < 0 || x >=N || y >= M || vis[x][y] || inp[x][y] == 'I' || cover[x][y] <= d) continue;
        //w<< x s y<<e;
        if (inp[x][y] == 'T') {w<< "YES"<<e; return 0;}
        vis[x][y] = true;
        next1.push(mp(d+1, mp(x+1, y)));
        next1.push(mp(d+1, mp(x-1, y)));
        next1.push(mp(d+1, mp(x, y+1)));
        next1.push(mp(d+1, mp(x, y-1)));
	}
	w<< "NO"<<e;
}
