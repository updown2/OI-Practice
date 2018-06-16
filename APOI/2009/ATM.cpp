/*
Compress SCCs to get a DAG
dp[i] = max money from a path from node S
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(ll i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, M)
#define ffa ffi ffj
#define s <<" "<<
#define w cout
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
//#define int ll
//500,000,000 operations
const int MAXN = 500000, INF = 2000000000;
//Global Variables
int N, M, S, P, inpcash[MAXN], cash[MAXN], cyc[MAXN], N2, dp[MAXN], out;
bool inppub[MAXN], pub[MAXN], vis[MAXN], valid[MAXN];
vector<int> inp[MAXN], bac[MAXN];
set<int> adj[MAXN];
stack<int> ord;

void getord(int at) {
    if (vis[at]) return;
    vis[at] = true;
    for (int i: bac[at]) getord(i);
    ord.push(at);
}
void mark(int at) {
    if (cyc[at] != -1) return;
    cyc[at] = N2;
    for (int i: inp[at]) mark(i);
}
void go(int at) {
    if (vis[at]) return;
    vis[at] = true;
    if (at == S) {dp[at] = cash[at]; valid[at] = true; return;}
    int ret = -1;
    for (int i: adj[at]) {
        go(i);
        if (valid[i]) ret = max(ret, dp[i]);
    }
    //w<< at s ":" s ret<<e;
    if (ret == -1) return;
    valid[at] = true;
    dp[at] = ret + cash[at];
}

main() {
	//ifstream cin ("test.in");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	ffj {int a, b; cin >> a >> b; a--; b--; inp[a].pb(b), bac[b].pb(a);}
	ffi {cin >> inpcash[i]; cyc[i] = -1;}
	cin >> S >> P; S--;
	For (p, 0, P) {int a; cin >> a; inppub[a-1] = true;}
	ffi getord(i);
	ffi {
        int j = ord.top(); ord.pop();
        if (cyc[j] != -1) continue;
        mark(j); N2++;
	}
	//ffi w<< i+1 s cyc[i]<<e;
	ffi {
        int k = cyc[i];
        if (inppub[i]) pub[k] = true;
        cash[k] += inpcash[i];
        for (int j: inp[i]) if (cyc[j] != k) adj[cyc[j]].insert(k);
        if (i == S) S = k+N;
	}
	S -= N;
	/*w<< "S:" s S<<e;
	For (i, 0, N2) {
        w<< i s ":" s cash[i]<<e;
        for (int j: adj[i]) w<< j << " "; w<<e;
	}*/
	ffi vis[i] = false; /// N > N2
	For (i, 0, N2) if (pub[i]) {
        go(i);
        out = max(out, dp[i]);
	}
	//For (i, 0, N2) w<< i s ":" s dp[i]<<e;
	w<< out<<e;
}
