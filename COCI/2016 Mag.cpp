/*
https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/COCI/official/2017/contest1_solutions/solutions.pdf
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
//#define int ll
const int MAXN=1000000, INF=1000000000;
///500,000,000
int N, val[MAXN], sm = INF, dp[MAXN], o1, o2, dp1[MAXN], n1[MAXN], dp2[MAXN];
vector<int> adj[MAXN];

void go (int at, int par) {
    int b1=0, b2=0;
    if (val[at] == 1) dp[at] = 1;
    for (int i: adj[at]) if (i != par) {
        go(i, at);
        if (val[at] == 1) dp[at] = max(dp[at], 1+dp[i]);
        if (dp[i] > b2) {
            b2 = dp[i];
            if (b2 > b1) swap(b1, b2);
        }
    }
    if (val[at] == 1) o1 = max(o1, b1+b2+1);
}
void go2(int at, int par) {
    for (int i: adj[at]) if (i != par && val[i] == 1) {
        if (dp[i] > dp1[at]) {
            dp2[at] = dp1[at];
            dp1[at] = dp[i];
            n1[at] = i;
        }
        else if (dp[i] > dp2[at]) dp2[at] = dp[i];
    }
    if (par != -1 && val[par] == 1) {
        int x;
        if (n1[par] == at) x = dp2[par];
        else x = dp1[par];
        if (x > dp1[at]) {
            dp2[at] = dp1[at];
            dp1[at] = x;
            n1[at] = par;
        }
        else if (x > dp2[at]) dp2[at] = x;
    }
    if (val[at] == 1) {dp1[at]++; dp2[at]++;}
    if (val[at] == 2) o2 = max(o2, dp2[at]);
    for (int i: adj[at]) if (i != par) go2(i, at);
}

main() {
    //ifstream cin("test.in");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	For (i, 1, N) {int a, b; cin >> a >> b; a--; b--; adj[a].pb(b); adj[b].pb(a);}
	ffi {n1[i] = -1; cin >> val[i]; sm = min(sm, val[i]);}
	if (sm != 1) {
        w<< sm <<"/1"<<e;
        return 0;
	}
	go(0, -1);
	go2(0,-1);
	if (o2 == o1) w<< "2/" << 2*o2+1<<e;
	else w<< "1/" << o1<<e;
}
