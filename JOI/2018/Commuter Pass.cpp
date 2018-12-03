/*
https://codeforces.com/blog/entry/57637?#comment-413356
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
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
const int MAXN=100000, INF=1000000000000000000;
///500,000,000
int N, M, S, T, U, V, du[MAXN], dv[MAXN], d[MAXN], dp1[MAXN], dp2[MAXN];
bool vis[MAXN];
vector<pair<int, int> > adj[MAXN]; /// (node, cost)
vector<int> from[MAXN], to[MAXN];
priority_queue<pair<int, int> > next1; /// (-dist, node)
queue<int> bk;

void sdp1(int at) {
    if (vis[at]) return;
    vis[at] = true;
    dp1[at] = dv[at];
    for (int i: from[at]) {
        sdp1(i);
        dp1[at] = min(dp1[at], dp1[i]);
    }
}
void sdp2(int at) {
    if (vis[at]) return;
    vis[at] = true;
    dp2[at] = dv[at];
    for (int i: to[at]) {
        sdp2(i);
        dp2[at] = min(dp2[at], dp2[i]);
    }
}

main() {
    //ifstream cin("test.in");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> S >> T >> U >> V; S--; T--; U--; V--;
	ffj {int a, b, d; cin >> a >> b >> d; a--; b--; adj[a].pb(mp(b, d)); adj[b].pb(mp(a, d));}
	ffi du[i] = dv[i] = d[i] = dp1[i] = dp2[i] = INF;
	next1.push(mp(0, U));
	while (!next1.empty()) {
        int d = -next1.top().a; int x = next1.top().b;
        next1.pop();
        if (du[x] < INF) continue;
        du[x] = d;
        for (auto i: adj[x]) if (!vis[i.a]) next1.push(mp(-d-i.b, i.a));
	}
	next1.push(mp(0, V));
	while (!next1.empty()) {
        int d = -next1.top().a; int x = next1.top().b;
        next1.pop();
        if (dv[x] < INF) continue;
        dv[x] = d;
        for (auto i: adj[x]) if (!vis[i.a]) next1.push(mp(-d-i.b, i.a));
	}
	next1.push(mp(0, S));
	while (!next1.empty()) {
        int a = -next1.top().a; int x = next1.top().b;
        next1.pop();
        if (d[x] < INF) continue;
        d[x] = a;
        for (auto i: adj[x]) if (!vis[i.a]) next1.push(mp(-a-i.b, i.a));
	}
	//ffi w<< du[i] s dv[i] s d[i]<<e;
	bk.push(T); vis[T] = true;
	while (!bk.empty()) {
        int x = bk.front(); bk.pop();
        for (auto i: adj[x]) if (d[i.a] + i.b == d[x]) {
            from[x].pb(i.a);
            to[i.a].pb(x);
            if (!vis[i.a]) {
                vis[i.a] = true;
                bk.push(i.a);
            }
        }
	}
	ffi vis[i] = false;
	sdp1(T);
	ffi vis[i] = false;
	sdp2(S);
	//ffi w<< i+1 c dp1[i] s dp2[i]<<e;
	int out = du[V];
	ffi out = min(out, du[i]+min(dp1[i], dp2[i]));
	w<< out<<e;
}
