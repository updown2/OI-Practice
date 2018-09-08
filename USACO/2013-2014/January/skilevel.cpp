/*
- Create a graph where the nodes are the NM cells and the edges are the 4 neighbors
The weights of the edges are the differences between the values
- Use Union-Find to find MST and update the answer for each cell as soon as its component
size reaches T
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, M)
#define ffa ffi ffj
#define s <<" "<<
#define cc <<" : "<<
#define w cout
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
//500,000,000 operations
const int MAXN = 500*500, INF = 100000000;
//Global Variables
int N, M, T, grid[MAXN], siz[MAXN], par[MAXN], ans[MAXN], out;
vector<int> und[MAXN];
bool done[MAXN];
priority_queue<pair<int, pair<int, int> > > next1;

int up(int at) {
    if (par[at] == at) return at;
    return up(par[at]);
}
void comb(int a, int b) {
    //w << "combining" s a s "and" s b<<e;
    if (siz[a] < siz[b]) {
        par[a] = b;
        siz[b] += siz[a];
        und[b].pb(a);
    }
    else {
        par[b] = a;
        siz[a] += siz[b];
        und[a].pb(b);
    }
}

void mark(int a, int c) {
    if (done[a]) return;
    done[a] = true;
    //w<< "marking" s a s "with" s c<<e;
    ans[a] = c;
    for (int i: und[a]) mark(i, c);
}

main() {
    //ifstream cin("test.in");
    ifstream cin("skilevel.in"); ofstream cout("skilevel.out");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> T;
    For (i, 0, N*M) {
        siz[i] = 1;
        par[i] = i;
    }
    ffa cin >> grid[i*M+j];
    ffa {
        int ind = i*M+j;
        if (i != 0) next1.push(mp(-abs(grid[ind]-grid[ind-M]), mp(ind, ind-M)));
        if (j != 0) next1.push(mp(-abs(grid[ind]-grid[ind-1]), mp(ind, ind-1)));
        //w<< ind c e; for (int k: adj[ind]) w s k; w<<e;
    }
    while (!next1.empty()) {
        int c = -next1.top().a, a = next1.top().b.a, b = next1.top().b.b;
        next1.pop();
        a = up(a), b = up(b);
        if (a == b) continue;
        comb(a, b);
        if (done[a] && done[b]) continue;
        if (siz[up(a)] >= T) mark(a, c);
        if (siz[up(b)] >= T) mark(b, c);
    }

    //ffi {ffj w<< ans[i*M+j]<< " "; w<<e;}
    For (i, 0, N*M) {
        int a; cin >> a;
        if (a == 1) out += ans[i];
    }
    w<< out<<e;
}
