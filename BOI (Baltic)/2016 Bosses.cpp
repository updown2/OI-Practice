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
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
//#define int ll
//500,000,000 operations
const int MAXN = 5000, INF=1000000000;
//Global Variables
int N, out=INF;
vector<int> adj[MAXN];
bool vis[MAXN];
queue<pair<int, int> > nex; /// (at, depth)

main() {
    //ifstream cin ("test.in");
    //ifstream cin(".in"); ofstream cout(".out");
    ios_base::sync_with_stdio; cin.tie(0);
    cin >> N;
    ffi {
        int k; cin >> k; For (j, 0, k) {
            int a; cin >> a; a--;
            adj[a].pb(i);
        }
    }
    ffi {
        /// this is the starting node
        int curr = 0;
        ffj vis[j] = false;
        nex.push(mp(i, 1));
        while (!nex.empty()) {
            int at = nex.front().a; int d = nex.front().b;
            nex.pop();
            if (vis[at]) continue;
            vis[at] = true;
            curr += d;
            for (int j: adj[at]) nex.push(mp(j, d+1));
        }
        bool good = true;
        ffj if (!vis[j]) good = false;
        if (good) out = min(out, curr);
    }
    w<< out<<e;
}
