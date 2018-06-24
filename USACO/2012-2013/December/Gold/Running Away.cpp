/*
Binary jumping to update nodes that can reach the current node
node 0 has INF distance to node 1 to prevent not having a node that can't be reached in L distance
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N+1)
#define ffj For(j, 0, M)
#define ffa ffi ffj
#define s <<" "<<
#define w cout
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
const int MAXN=200001, INF=2000000000000000000;
///500,000,000
int N, L, anc[MAXN][20], len[MAXN][20], pre[MAXN];
vector<int> adj[MAXN];

void fix(int at) {
    for (int i: adj[at]) {fix(i); pre[at] += pre[i];}
}

main() {
    //ifstream cin("test.in");
    ifstream cin("runaway.in"); ofstream cout("runaway.out");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> L;
    anc[1][0] = 0, len[1][0] = INF; adj[0].pb(1);
    For (i, 2, N+1) {int p, l; cin >> p >> l; anc[i][0] = p; adj[p].pb(i); len[i][0] = l;}
    For (k, 0, 19) ffi {
        anc[i][k+1] = anc[anc[i][k]][k];
        len[i][k+1] = len[i][k] + len[anc[i][k]][k];
    }
    For (i, 1, N+1) {
        int at = i; int went = 0;
        for (int k=19; k>=0; k--) if (went+len[at][k] <= L) {
            went += len[at][k];
            at = anc[at][k];
        }
        at = anc[at][0];
        //w<< i s at<<e;
        pre[i]++;
        pre[at]--;
    }
    //ffi w<< pre[i]<<e;
    fix(0);
    For (i, 1, N+1) w<< pre[i]<<e;
}
