/*
- create the ranges that are possible for every node
- every start and end value creates a range because we add segments to the
left and the right of joke[at]
- start at joke[at] and bfs/dfs in both directions with the possible ranges of
your children to find the possible start and end locations
the answer is the number of ranges that pass over node 0
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, MAXV)
#define ffj For(j, 0, MAXV)
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
const int MAXN=10000, MAXV = 100;
///500,000,000
int N, joke[MAXN];
vector<int> adj[MAXN], st[MAXN], en[MAXN], dirfor[MAXV], dirbck[MAXV];
queue<int> nxt;
bool vis[MAXV];

void go(int at) {
    for (int i: adj[at]) go(i);
    ffi dirfor[i].clear(), dirbck[i].clear();
    for (int i: adj[at]) for (int j: st[i]) for (int k: en[i]) if ( k < joke[at] || joke[at] < j ) dirfor[j].pb(k), dirbck[k].pb(j);
    ffi vis[i] = false;
    nxt.push(joke[at]);
    vis[joke[at]] = true;
    while (!nxt.empty()) {
        int x = nxt.front(); nxt.pop();
        en[at].pb(x);
        if (x == MAXV-1) continue;
        for (int i: dirfor[x+1]) if (!vis[i]) {nxt.push(i); vis[i] = true;}
    }
    ffi vis[i] = false;
    nxt.push(joke[at]);
    vis[joke[at]] = true;
    while (!nxt.empty()) {
        int x = nxt.front(); nxt.pop();
        st[at].pb(x);
        if (x == 0) continue;
        for (int i: dirbck[x-1]) if (!vis[i]) {nxt.push(i); vis[i] = true;}
    }
    //w<< at+1<<e; w<< "st:"; for (int i: st[at]) w s i+1; w<<e; w<< "en:"; for (int i: en[at]) w s i+1; w<<e;
}

main() {
    //ifstream cin("test.in");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	For (i, 0, N) {cin >> joke[i]; joke[i]--;}
	For (i, 1, N) {int a, b; cin >> a >> b; a--; b--; adj[a].pb(b);}
	go(0);
	w<< st[0].size()*en[0].size()<<e;
}
