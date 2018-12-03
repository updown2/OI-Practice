#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, Q)
#define ffa ffi ffj
#define s <<" "<<
#define c <<" : "<<
#define w cout
#define e endl // "/n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
//500,000,000 operations
const int MAXN = 100000, INF = 100000000000000;
//Global Variables
int T, N, Q, queries[MAXN][3], par[MAXN], siz[MAXN];
set<pair<int, int> > edges;
stack<string> out;

int root (int a) {
    if (par[a] == a) return a;
    return root(par[a]);
}
void conn (int a, int b) {
    a = root(a); b = root(b);
    if (a == b) return;
    if (siz[a] > siz[b]) {
        /// b into a
        siz[a] += siz[b];
        par[b] = a;
    }
    else {
        /// a into b
        siz[b] += siz[a];
        par[a] = b;
    }
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    For (t, 1, T+1) {
        w<< "Colony" s "#"<<t << ":"<<e;
        cin >> N;
        edges.clear();
        For (i, 0, N-1) {
            int a, b; cin >> a >> b; a--; b--; edges.insert(mp(min(a, b), max(a, b)));
        }
        cin >> Q;
        ffj {
            int a, b, d; cin >> a >> b >> d; b--; d--;
            queries[j][0] = a;
            queries[j][1] = b;
            queries[j][2] = d;
            if (a == 1) edges.erase(mp(min(b, d), max(b, d)));
        }
        ffi {siz[i] = 1; par[i] = i;}
        for (auto i: edges) conn(i.a, i.b);
        for (int j=Q-1; j>=0; j--) {
            //w<< "query" c queries[j][1] s queries[j][2]<<e;
            if (queries[j][0] == 1) {
                conn(queries[j][1], queries[j][2]);
                out.push("Tunnel from "+ to_string(queries[j][1]+1) + " to " + to_string(queries[j][2]+1) + " collapsed!");
            }
            else {
                int a = root(queries[j][1]);
                int b = root(queries[j][2]);
                if (a == b) out.push("Room " + to_string(queries[j][1]+1) + " can reach " + to_string(queries[j][2]+1));
                else out.push("Room " + to_string(queries[j][1]+1) + " cannot reach " + to_string(queries[j][2]+1));
            }
        }
        while (!out.empty()) {w<<out.top()<<e; out.pop();}
        w<<e;
    }
}
