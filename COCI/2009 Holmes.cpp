/*
https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/COCI/official/2010/contest6_solutions/solutions.pdf
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
//500,000,000 operations
const int MAXN = 100000;
//Global Variables
int N, M, E;
vector<int> adj[MAXN], bck[MAXN];
bool on[MAXN], vis[MAXN], bad[MAXN], out[MAXN];

void dfs(int at) {
    if (vis[at] || bad[at]) {
        return;
    }
    vis[at] = true;
    for (int i: adj[at]) {
        dfs(i);
    }
}
void gobck(int at) {
    if (bad[at]) {
        return;
    }
    bad[at] = true;
    for (int i: bck[at]) {
        gobck(i);
    }
}

int main() {
    //ifstream cin("test.in");
    cin >> N >> M >> E;
    ffj {
        int a, b;
        cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        bck[b].push_back(a);
    }
    For (i, 0, E) {
        int a;
        cin >> a;
        on[a-1] = true;
    }
    /// try every node as bad
    ffi {
        For (j, 0, N) bad[j] = vis[j] = false;
        gobck(i);
        For (j, 0, N) if (!bad[j] && bck[j].size() == 0) dfs(j);
        For (j, 0, N) if (on[j] && !vis[j]) out[i] = true;
    }
    ffi if (out[i]) w<< i+1<<" "; w<<e;
}
