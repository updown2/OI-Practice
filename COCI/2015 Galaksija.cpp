/*
solution is under contest 4 here:
http://hsin.hr/coci/archive/2015_2016/
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
const int MAXN=100000, INF=1000000000;
///500,000,000
int N, edges[MAXN][3], out, root[MAXN], siz[MAXN], xxor[MAXN];
vector<int> del, ans;
vector<pair<int, int> > adj[MAXN];
map<int, int> have[MAXN];
vector<int> nodes;

void go(int at, int bef, int xxx, int rt) {
    nodes.pb(at);
    xxor[at] = xxx;
    if (have[rt].find(xxx) != have[rt].end()) out += have[rt][xxx];
    for (auto i: adj[at]) if (i.a != bef) go(i.a, at, xxx^i.b, rt);
}
int top(int x) {
    if (x == root[x]) return x;
    root[x] = top(root[x]);
    return root[x];
}

main() {
    //ifstream cin("test.in");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	For (i, 1, N) For (j, 0, 3) cin >> edges[i][j];
	For (i, 1, N) {int a; cin >> a; del.pb(a);}
	ffi root[i] = i, siz[i] = 1, have[i][0] = 1;
	reverse(del.begin(), del.end());
	ans.pb(0);
	for (int x: del) {
        int a = edges[x][0]-1, b = edges[x][1]-1, v = edges[x][2];
        /// add edge from a to b
        /// reroot
        int A = top(a), B = top(b);
        nodes.clear();
        if (siz[A] > siz[B]) {
            /// merge b into a
            go(b, -1, xxor[a]^v, A);
            for (int i: nodes) {
                if (have[A].find(xxor[i]) != have[A].end()) have[A][xxor[i]]++;
                else have[A][xxor[i]] = 1;
            }
            root[B] = A;
            siz[A] += siz[B];
        }
        else {
            /// merge a into b
            go(a, -1, xxor[b]^v, B);
            for (int i: nodes) {
                if (have[B].find(xxor[i]) != have[B].end()) have[B][xxor[i]]++;
                else have[B][xxor[i]] = 1;
            }
            root[A] = B;
            siz[B] += siz[A];
        }
        adj[a].emplace_back(b, v); adj[b].emplace_back(a, v);
        ans.pb(out);
	}
	reverse(ans.begin(), ans.end());
	for (int i: ans) w<< i<<e;
}
