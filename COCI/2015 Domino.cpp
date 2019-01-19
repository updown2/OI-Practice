/*
https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/COCI/official/2016/contest3_solutions/solutions.pdf
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, N)
#define ffa ffi ffj
#define s <<" "<<
#define c <<" : "<<
#define w cout
#define e endl//"\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define x1 b.a.a
#define y1 b.a.b
#define x2 b.b.a
#define y2 b.b.b
//#define int ll
const int MAXN=2000, INF=1000000000, big=56;
///500,000,000
int N, K, inp[MAXN][MAXN], dp[1<<20], D, out, poss;
bool vis[1<<20], adj[big][big];
vector<pair<int, pair<pair<int, int>, pair<int, int> > > > sums;
vector<int> Aon, Bon;
set<pair<int, pair<pair<int, int>, pair<int, int> > > > have;
set<pair<int, pair<pair<int, int>, pair<int, int> > > >::iterator it;


bool diff(int r1, int c1, int r2, int c2) {
    return r1 != r2 || c1 != c2;
}
void goA(int at) {
    if (vis[at]) return;
    vis[at] = true;
    if (__builtin_popcount(at) < D) return;
    if (__builtin_popcount(at) == D) {
        Aon.clear();
        For (i, 0, 20) if (at & (1<<i)) Aon.pb(i);
        bool good = true;
        For (i, 0, D) For (j, i+1, D) if (!adj[Aon[i]][Aon[j]]) good = false;
        if (!good) return;
        /// they are all connected so there exists an answer
        for (int i: Aon) dp[at] += sums[i].a;
        return;
    }
    For (i, 0, 20) if (at & (1<<i)) {
        int x = at - (1<<i);
        goA(x);
        dp[at] = max(dp[at], dp[x]);
    }
}
void goB(int at) {
    if (at == big) return;
    /// see if we are done
    if (Bon.size() == K-D) {
        int tot = dp[poss];
        for (int i: Bon) tot += sums[i].a;
        out = max(out, tot);
        /*if (out == tot) {
            For (i, 0, 20) w<<
        }*/
        return;
    }
    /// skip at
    goB(at+1);
    /// see if we can take at
    bool good = true;
    for (int i: Bon) if (!adj[i][at]) good = false;
    if (!good) return;
    /// take at
    vector<int> del;
    For (i, 0, 20) if (poss & (1<<i) && !adj[i][at]) {poss -= (1<<i); del.pb(i);}
    Bon.pb(at);
    if (dp[poss] > 0) goB(at+1);
    /// undo
    for (int i: del) poss += (1<<i);
    Bon.pop_back();
}

main() {
    //ifstream cin("test.in");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	ffa {
	    cin >> inp[i][j];
	    //if (inp[i][j] != 808) w<< i s j s inp[i][j]<<e;
    }
	For (i, 0, N-1) ffj {
	    have.insert(mp(-inp[i][j]-inp[i+1][j], mp(mp(i, j), mp(i+1, j))));
	    if (have.size() > big) {
            it = have.end(); it--;
            have.erase(it);
	    }
	}
	ffi For (j, 0, N-1) {
	    have.insert(mp(-inp[i][j]-inp[i][j+1], mp(mp(i, j), mp(i, j+1))));
	    if (have.size() > big) {
            it = have.end(); it--;
            have.erase(it);
	    }
	}
	for (auto i: have) sums.pb(i);
	while (sums.size() < big) sums.pb(mp(0, mp(mp(0, 0), mp(0, 0))));
	for (auto &i: sums) i.a *= -1;
	//for (auto i: sums) w<< i.a c i.x1 s i.y1 c i.x2 s i.y2<<e;
	For (i, 0, big) For (j, i+1, big) if (diff(sums[i].x1, sums[i].y1, sums[j].x1, sums[j].y1) &&
                                     diff(sums[i].x1, sums[i].y1, sums[j].x2, sums[j].y2) &&
                                     diff(sums[i].x2, sums[i].y2, sums[j].x1, sums[j].y1) &&
                                     diff(sums[i].x2, sums[i].y2, sums[j].x2, sums[j].y2)) adj[i][j] = adj[j][i] = true;
    for (D=0; D<=K; D++) {
        /// take D nodes in subgraph A, K-D in subgraph B
        /// subgraph A: 0-19, subgraph B: 20-(big-1)
        For (i, 0, 1<<20) dp[i] = 0, vis[i] = false;
        goA((1<<20) - 1);
        //w<< "D =" s D c dp[(1<<20)-1]<<e;
        /// for all possibilities of K-D nodes in B
        poss = (1<<20) -1;
        goB(20);
    }
    ll tot = 0;
    ffa tot += inp[i][j];
    w<< tot - out<<e;
}
