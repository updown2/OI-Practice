/*
find relationships
add relationships for the nodes with an outgoing edge but no incoming edge
add (siz+1)/2 for cycles
add 1 for pointless nodes
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
int N, at, nex[MAXN], out, emp;
bool done[MAXN];
set<int> adj[MAXN];
map<string, int> node;
queue<int> next1;

int get (string have) {
    if (node.find(have) == node.end()) node[have] = at, at++;
    //w<< have s ":" s node[have]<<e;
    return node[have];
}
void finish (int i) {
    done[i] = true;
    for (int j: adj[i]) if (j != nex[i]) nex[j] = -1;
    adj[i].clear(); adj[i].insert(nex[i]);
    i = nex[i];
    done[i] = true;
    for (int j: adj[i]) if (j != nex[i]) nex[j] = -1;
    adj[i].clear(); adj[i].insert(nex[i]);
}
int go (int at) {
    if (done[at]) return 0;
    done[at] = true;
    int x = 1+go(nex[at]);
    //w<< at s ":" s x<<e;
    return x;
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    if (N%2 == 1) {w<< -1<<e; return 0;}
    ffi {
        string a, b; cin >> a >> b; int c = get(a), d = get(b);
        if (c == d) nex[c] = -1;
        else nex[c] = d; adj[d].insert(c);
    }
    ffi if (nex[i] != -1 && nex[nex[i]] == i) finish(i);
    //ffi w<< done[i]<< " "; w<<e;
    ffi if (adj[i].empty() && nex[i] != -1) next1.push(i);
    while (!next1.empty()) {
        int i = next1.front(); next1.pop();
        if (nex[i] == -1 || !adj[i].empty()) continue;
        //w<< i s nex[i]<<e;
        /// direct nex[i] to i
        out++;
        if (nex[nex[i]] != -1) {
            adj[nex[nex[i]]].erase(nex[i]);
            if (adj[nex[nex[i]]].empty()) next1.push(nex[nex[i]]);
        }
        nex[nex[i]] = i;
        finish(i);
    }
    //ffi w<< done[i]<< " "; w<<e;
    //ffi {w<< i s ":"; for (int j: adj[i]) w<< j << " "; w<<e;}
    //ffi w<< i s ":" s nex[i]<<e;
    /// Count pointless nodes
    ffi if (!done[i] && nex[i] == -1) emp++;
    //w<< "pointless count:" s emp<<e;
    /// Find cycles
    ffi if (!done[i] && nex[i] != -1) {
        /// must be a cycle
        /// mark the cycle as done
        int siz = go(i);
        out += (siz+1)/2;
    }
    out += emp;
    w<< out<<e;
}
