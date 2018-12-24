/*
https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/Baltic/official/boi2012_solutions/melody-sol.pdf
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 1, N+1)
#define ffj For(j, 1, N+1)
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
const int MAXN=101, INF=1000000000;
///500,000,000
int N, M, G, L, dp[100001], dist[MAXN][MAXN], C[MAXN][100001], from[100001], st, at, inp[100001], f2[MAXN][MAXN];
string notes[MAXN];
stack<int> ord;
vector<int> ans;

void add(int a, int b) {
    /// assume that a is already added
    if (dist[a][b] == 1) {
        ans.pb(b);
        return;
    }
    int k = f2[a][b];
    add(a, k); add(k, b);
}

main() {
    //ifstream cin("test.in");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> G;
	ffi cin >> notes[i];
	ffa dist[i][j] = INF;
	ffa {
        int bad = 0;
        For (k, 0, M) if (notes[i][k] != notes[j][k]) bad++;
        if (bad <= G) dist[i][j] = 1;
	}
	For (k, 1, N+1) ffa if (dist[i][k] + dist[k][j] < dist[i][j]) {
	    f2[i][j] = k;
        dist[i][j] = dist[i][k]+dist[k][j];
	}
	//ffa w<< i s j c dist[i][j]<<e;
	cin >> L;
	For (i, 1, L+1) {
        int a; cin >> a; inp[i] = a;
        For (j, 1, MAXN) if(dist[a][j] < i) {
            //w<< i c a s j s "works at" s C[j][i-dist[a][j]] s i-dist[a][j]<<e;
            if (dp[C[j][i-dist[a][j]]] > dp[i]) {
                dp[i] = dp[C[j][i-dist[a][j]]];
                from[i] = C[j][i-dist[a][j]];
            }
        }
        dp[i]++;
        if (dp[i] > dp[st]) st = i;
        //w<< i c dp[i] s from[i]<<e;
        For (j, 1, MAXN) C[j][i] = C[j][i-1];
        C[a][i] = i;
	}
	at = st;
	while (st != 0) {
        ord.push(st);
        //w<<st<<e;
        st = from[st];
	}
	/// first element is an exception
	For (i, 0, ord.top()) ans.pb(inp[ord.top()]);
	while (ord.size() >= 2) {
        int a = ord.top(); ord.pop(); int b = ord.top();
        int x = dist[inp[a]][inp[b]];
        int y = (b-a)-dist[inp[a]][inp[b]];
        For (i, 0, y) ans.pb(inp[a]);
        add(inp[a], inp[b]);
	}
	/// last element is an exception
	For (i, ord.top(), L) ans.pb(inp[ord.top()]);
	w<< L-dp[at]<<e;
	for (int i: ans) w<< i<< " "; w<<e;
}
