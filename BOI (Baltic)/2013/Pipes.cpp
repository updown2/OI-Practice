/*
http://boi2013.informatik-olympiade.de/wp-content/uploads/2013/05/pipes-spoiler.pdf
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
#define e endl // "/n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
//500,000,000 operations
const int MAXN = 500000, INF = 1000000000;
//Global Variables
int N, M, out[MAXN], inp[MAXN];
set<pair<int, int> > adj[MAXN]; /// (node, edge #)
set<pair<int, int> >::iterator it;
queue<int> next1;

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    if (M > N) {w<<0<<e; return 0;}
    ffi cin >> inp[i];
    ffj {int a, b; cin >> a >> b; a--; b--; adj[a].insert(mp(b, j)); adj[b].insert(mp(a, j));}
    ffi if (adj[i].size() == 1) next1.push(i);
    while (!next1.empty()) {
        int x = next1.front(); next1.pop();
        if (adj[x].size() != 1) continue;
        it = adj[x].begin();
        int y = (*it).a;
        inp[y] -= inp[x];
        out[(*it).b] = inp[x]*2;
        inp[x] = 0;
        adj[y].erase(mp(x, (*it).b));
        adj[x].erase(it);
        if (adj[y].size() == 1) next1.push(y);
    }
    if (N == M) {
        int cnt = 0;
        ffi if (adj[i].size() > 0) cnt++;
        if (cnt%2 == 0) {w<<0<<e; return 0;}
        int st;
        ffi if (adj[i].size() > 0) st = i;
        int tot = 0;
        int mul = 1;
        int at = -st, prev, p2;
        while (at != st) {
            if (at == -st) at = st;
            it = adj[at].begin();
            int y = (*it).a;
            tot += inp[at]*mul;
            mul *= -1;
            adj[y].erase(mp(at, (*it).b));
            prev = (*it).b;
            p2 = at;
            at = y;
        }
        out[prev] = tot;
        inp[p2] -= tot/2;
        inp[st] -= tot/2;
        adj[p2].erase(mp(st, prev));
        at = st;
        while (adj[at].size() > 0) {
            it = adj[at].begin();
            int y = (*it).a;
            int ed = (*it).b;
            out[ed] = inp[at]*2;
            inp[y] -= inp[at];
            inp[at] = 0;
            at = y;
        }
    }
    ffj w<< out[j]<<e;
}
