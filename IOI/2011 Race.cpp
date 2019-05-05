#include "race.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, M)
#define ffj For(j, 0, N)
#define ffa ffi ffj
#define s <<" "<<
#define c <<" : "<<
#define w cout
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
//#define int ll
const int MAXN = 200000;
//500,000,000 operations
ll k;
int out = MAXN+1, siz, und[MAXN];;
bool gone[MAXN];
vector<int> nodes;
vector<pair<int, ll> > adj[MAXN];
map<ll, int> len;

void dfs(int at, int p) {
    und[at] = 1;
    siz++;
    nodes.pb(at);
    for (auto i: adj[at]) if (i.a != p && !gone[i.a]) {
        dfs(i.a, at);
        und[at] += und[i.a];
    }
}

void query(int at, ll path, int took, int p) {
    if (len.find(k-path) != len.end()) {
        //w<< siz s p s at<<e;
        out = min(out, len[k-path]+took);
    }
    for (auto i: adj[at]) if (i.a != p && !gone[i.a]) query(i.a, path+i.b, took+1, at);
}

void update(int at, ll path, int took, int p) {
    if (len.find(path) == len.end()) len[path] = took;
    len[path] = min(len[path], took);
    //w<< "add" s path s at<<e;
    for (auto i: adj[at]) if (i.a != p && !gone[i.a]) update(i.a, path+i.b, took+1, at);
}

void solve(int at) {
    siz = 0;
    nodes.clear();
    dfs(at, at);
    /// find centroid
    int ce;
    for (int i: nodes) {
        int big = siz-und[i];
        for (auto j: adj[i]) if (!gone[j.a] && und[j.a] < und[i]) {
            big = max(big, und[j.a]);
        }
        if (big <= siz/2) ce = i;
    }
    //w<< "reset for" s ce<<e;
    len.clear();
    len[0] = 0;
    for (auto i: adj[ce]) if (!gone[i.a]) {
        query(i.a, i.b, 1, ce);
        update(i.a, i.b, 1, ce);
    }
    /// solve sub problems
    gone[ce] = true;
    for (auto i: adj[ce]) if (!gone[i.a]) solve(i.a);
}

int best_path(int N, int K, int H[][2], int L[]){
    k = K;
    For (i, 0, N-1) {
        adj[H[i][0]].emplace_back(H[i][1], L[i]);
        adj[H[i][1]].emplace_back(H[i][0], L[i]);
    }
    solve(0);
    if (out > MAXN) out = -1;
    return out;
}
