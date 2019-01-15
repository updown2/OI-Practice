/*
nodes are spots (0-N-1:left, N - 2*N-1: right)
edges are people
weight of edge is strength
if there is only one edge in a node, remove and repeat
we are not left with cycles so all edges should have exactly two edges in it
find the possibility for each cycle
use bitset for quick dp
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, 2*N)
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
//#define int ll
const int MAXN=60000, INF=1000000000;
///500,000,000
int N, K, s1, s2, tot;
bool vis[MAXN];
vector<int> vals;
multiset<pair<int, int> > adj[MAXN];
multiset<pair<int, int> >::iterator it;
queue<int> emp;
bitset<10*MAXN+1> dp; /// 10*MAXN bc MAXN = 2*30,000

void go(int at, int diff, int put) {
    if (vis[at]) {vals.pb(abs(diff)); return;}
    vis[at] = true;
    it = adj[at].begin();
    int x = (*it).a, d = (*it).b;
    if (put == 0) diff += d;
    else diff -= d;
    adj[x].erase(adj[x].find(mp(at, d)));
    adj[at].erase(it);
    go(x, diff, 1-put);
}

main() {
    //ifstream cin("test.in");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	ffi {
        int a, b, d; cin >> a >> b >> d;
        a--; b = b-1+N;
        adj[a].insert(mp(b, d)); adj[b].insert(mp(a, d));
        //w<< a s b<<e;
        tot += d;
	}
	if (K == 0 && tot%2 != 0) {
        w<< "NO"<<e;
        exit(0);
	}
	ffi if (adj[i].size() == 1) emp.push(i);
	while (!emp.empty()) {
        int x = emp.front(); emp.pop();
        if (adj[x].empty()) {
            w<< "NO"<<e;
            return 0;
        }
        it = adj[x].begin();
        if (x < N) s1 += (*it).b;
        else s2 += (*it).b;
        adj[(*it).a].erase(adj[(*it).a].find(mp(x, (*it).b)));
        if (adj[(*it).a].size() == 1) emp.push((*it).a);
        adj[x].erase(it);
	}
	ffi if (adj[i].size() != 2 && adj[i].size() != 0) {
        w<< "NO"<<e;
        exit(0);
	}
	ffi if (!vis[i] && adj[i].size() == 2) {
        go(i, 0, 0);
	}
	tot = 0;
	//for (int i: vals) w<< i<< " "; w<<e;
	dp[abs(s1-s2)] = 1; /// check if this is correct
	for (int i: vals) {
        tot += i;
        dp |= dp << (2*i);
	}
	For (i, 0, 10*MAXN+1) if (dp[i] == 1) {
	    //w<< i s tot<<e;
        if (abs(tot-i) <= K) {
            w<< "YES"<<e;
            return 0;
        }
	}
	w<< "NO"<<e;
}
