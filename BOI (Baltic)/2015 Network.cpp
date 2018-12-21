/*
x = total number of nodes
find a node y s.t. the max nodes in any branch is <= floor(x/2)
if x is odd, connect any leaf to y
pair leaves with leaves from different branches greedily taking the biggest two branches
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, K)
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
//500,000,000 operations
const int MAXN = 500000;
//Global Variables
int N, root, x, y, leaves[MAXN], par[MAXN];
vector<int> adj[MAXN], vals[MAXN];
priority_queue<pair<int, int> > take; /// (size of queue, index)

void gol(int p, int at) {
    par[at] = p;
    if (adj[at].size() == 1) {x++; leaves[at] = 1; return;}
    for (int i: adj[at]) if (i != p) {gol(at, i); leaves[at] += leaves[i];}
}
void gorr(int p, int at, int use = -1) {
    if (use == -1 && p != -1) use=at;
    //w<< at+1 s use+1<<e;
    if (adj[at].size() == 1) vals[use].pb(at);
    for (int i: adj[at]) if (i != p) gorr(at, i, use);
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    For (i, 1, N) {int a, b; cin >> a >> b; a--; b--; adj[a].pb(b); adj[b].pb(a);}
    ffi if (adj[i].size() != 1) root = i;
    gol(-1, root);
    ffi if (adj[i].size() != 1) {
        bool good;
        if (x-leaves[i] > (x+1)/2) good = false;
        else good = true;
        for (int j: adj[i]) if (j != par[i]) {
            if (leaves[j] > (x+1)/2) good = false;
        }
        if (good) y = i;
    }
    //w<< root+1 s x s y+1<<e;
    /// reroot the tree at y
    root = y;
    gorr(-1, y);
    for (int i: adj[y]) take.push(mp(vals[i].size(), i));
    w<< (x+1)/2<<e;
    For (i, 0, x/2) {
        int a = take.top().b; take.pop();
        int b = take.top().b; take.pop();
        w<< vals[a][vals[a].size()-1]+1 s vals[b][vals[b].size()-1]+1<<e;
        vals[a].pop_back(); vals[b].pop_back();
        take.push(mp(vals[a].size(), a)); take.push(mp(vals[b].size(), b));
    }
    if (x%2 == 1) {
        int a = take.top().b;
        w<< y+1 s vals[a].front()+1<<e;
    }
}
