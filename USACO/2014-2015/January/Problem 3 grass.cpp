/*
Compress the SCCs.
Create a dpf for longest path from node 1 and dpt longest path to node 1
answer is biggest dpf[i] + dpt[j] where there is a path from j to i (bc reverse)
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
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
#define int ll
const int MAXN=100000, INF=10000000000, MOD = 1000000009;
///500,000,000
int N, M, N2, siz[MAXN], cyc[MAXN], dpt[MAXN], dpf[MAXN], out;
bool vis[MAXN];
vector<int> bac[MAXN], inp[MAXN];
set<int> adjf[MAXN], adjb[MAXN];
stack<int> ord;

void getord(int at) {
    if (vis[at]) return;
    vis[at] = true;
    for (int i: bac[at]) getord(i);
    ord.push(at);
}
void getcyc(int at) {
    if (cyc[at] != -1) return;
    cyc[at] = N2;
    for (int i: inp[at]) getcyc(i);
}
bool getto(int at) {
    if (dpt[at] == -INF) return false;
    if (dpt[at] != -2) return true;
    if (at == cyc[0]) {
        dpt[at] = 0;
        return true;
    }
    int ret = -INF;
    for (int i: adjf[at]) if (getto(i)) {
        ret = max(ret, dpt[i]);
    }
    if (ret == -1) {
        dpt[at] = -1;
        return false;
    }
    dpt[at] = ret + siz[at];
    return true;
}
bool getfrom(int at) {
    if (dpf[at] == -INF) return false;
    if (dpf[at] != -2) return true;
    if (at == cyc[0]) {
        dpf[at] = siz[at];
        return true;
    }
    int ret = -INF;
    for (int i: adjb[at]) if (getfrom(i)) {
        ret = max(ret, dpf[i]);
    }
    if (ret == -1) {
        dpf[at] = -1;
        return false;
    }
    dpf[at] = ret + siz[at];
    return true;
}


main() {
    ifstream cin("grass.in"); ofstream cout("grass.out");
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    ffj {int a, b; cin >> a >> b; a--; b--; inp[a].pb(b); bac[b].pb(a);}
    ffi {cyc[i] = -1; getord(i);}
    ffi {
        int at = ord.top(); ord.pop();
        if (cyc[at] != -1) continue;
        //w<< "looking at" s at+1<<e;
        getcyc(at);
        N2++;
    }
    //ffi w<< i+1 s ":" s cyc[i]<<e;
    ffi {
        dpf[i] = dpt[i] = -2;
        int k = cyc[i];
        siz[k]++;
        for (int j: inp[i]) if (k != cyc[j]) {
            adjf[k].insert(cyc[j]);
            adjb[cyc[j]].insert(k);
        }
    }
    For (i, 0, N2) getto(i), getfrom(i);
    //For (i, 0, N2) w<< i s ":" s dpt[i]<<e;
    //For (i, 0, N2) w<< i s ":" s dpf[i]<<e;
    out = siz[cyc[0]];
    For (i, 0, N2) for (int j: adjf[i]) {
        /// exists an edge from i to j
        out = max(out, dpf[j]+dpt[i]);
    }
    w<< out<<e;
}