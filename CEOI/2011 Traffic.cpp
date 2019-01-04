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
//#define int ll
const int MAXN=300000, INF=1000000000;
///500,000,000
int N, M, A, B, acomp, comp[MAXN], dps[MAXN], dpb[MAXN], cnt[MAXN], x[MAXN], y[MAXN];
bool st[MAXN], en[MAXN], vis[MAXN];
vector<int> adj[MAXN], bck[MAXN];
set<int> ca[MAXN];
vector<pair<int, int> > ans, in;
stack<int> ord;

void go1(int at) {
    if (vis[at]) return;
    vis[at] = true;
    for (int i: adj[at]) go1(i);
    ord.push(at);
}

void go2(int at) {
    if (comp[at] != -1) return;
    comp[at] = acomp;
    for (int i: bck[at]) go2(i);
}

void solve(int at) {
    if (vis[at]) return;
    vis[at] = true;
    for (int i: ca[at]) {
        solve(i);
        dps[at] = min(dps[at], dps[i]);
        dpb[at] = max(dpb[at], dpb[i]);
    }
}
void fin(int at) {
    if (vis[at]) return;
    vis[at] = true;
    for (int i: adj[at]) fin(i);
}

main() {
    //ifstream cin("test.in");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> A >> B;
	ffi {
	    comp[i] = cnt[i] = -1; int a, b; cin >> a >> b; x[i] = a, y[i] = b;
        if (a == 0) {st[i] = true; ans.emplace_back(-b, i);}
        if (a == A) en[i] = true;
    }
	ffj {
        int a, b, k; cin >> a >> b >> k; a--; b--; adj[a].pb(b); bck[b].pb(a);
        if (k == 2) adj[b].pb(a), bck[a].pb(b);
	}
	ffi if (st[i]) fin(i);
	ffi {
	    if (en[i] && vis[i]) in.emplace_back(y[i], i);
        vis[i] = false;
	}
	ffi go1(i);
	ffi {
        int at = ord.top(); ord.pop();
        if (comp[at] != -1) continue;
        go2(at);
        acomp++;
	}
	ffi {
        vis[i] = false;
        dps[i] = 1000000;
        dpb[i] = -1;
        for (int j: adj[i]) ca[comp[i]].insert(comp[j]);
	}
	//w<< acomp<<e;
	sort(in.begin(), in.end());
    int ccc = 0;
    for (auto i: in) {
        int x = comp[i.b];
        dps[x] = min(dps[x], ccc);
        dpb[x] = max(dpb[x], ccc);
        ccc++;
    }
	For (i, 0, acomp) solve(i);
	sort(ans.begin(), ans.end());
	for (auto i: ans) {
        int at = comp[i.b];
        int out = max(dpb[at] - dps[at] + 1, 0);
        w<< out<<e;
	}
}
