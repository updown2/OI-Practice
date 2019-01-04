/*
Create a graph from one side of the to the other side that the prisoners have to pass
Add edges between nodes if the circles intersect
max flow, min cut # of nodes
split the nodes into an in node and an out node
the edge between a node is 1 and the other edges are INF
answer is the maxflow
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, M)
#define ffa ffi ffj
#define s <<" "<<
//#define c <<" : "<<
#define w cout
#define e endl//"\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
const int MAXN=600, INF=1000000000;
///500,000,000
int N, L, W, inp[MAXN][2], source, sink, res[MAXN][MAXN]; //(N+1) x (N+1) grid
bool visited[MAXN];
vector<int> adj[MAXN];

void connect(int a, int b, int c) {
	res[a][b] += c;
	For (i, 0, adj[a].size()) {
		if (adj[a][i] == b) {
			return;
		}
	}
	adj[a].push_back(b);
	adj[b].push_back(a);

}
int dfs(int x, int cap=INF) {
	visited[x] = true;
	if (x==sink) return cap; //If you are done and can only take cap things, return cap(you're all done)

	For (i, 0, adj[x].size()) {
		if (!visited[adj[x][i]]) {
			if (res[x][adj[x][i]] > 0) {
				int cur = dfs(adj[x][i], min(cap, res[x][adj[x][i]]));
				if (cur > 0) {
					res[x][adj[x][i]] -= cur;
					res[adj[x][i]][x] += cur;
					return cur;
				}
			}
		}
	}


	return 0;
}
int maxflow() {
	//Finds the max flow from source to the sink
	int flow = 0;
	while (true) {
		ffi visited[i] = false;
		int cur = dfs(source);
		//cout << cur << endl;
		if (cur == 0) break;
		flow += cur;

	}
	return flow;
}
void search(ll at) {
	if (visited[at]) return;
	visited[at] = true;
	For (i, 0, adj[at].size()) {
		if (res[at][adj[at][i]] > 0) {
			search(adj[at][i]);
		}
	}
}

main() {
	//ifstream cin ("test.in");
	cin >> L >> W >> N;
	For (i, 1, N+1) cin >> inp[i][0] >> inp[i][1];
	source = 1;
	sink = 2*(N+1);

	For (i, 1, N+1) connect(2*i, 2*i+1, 1);
	/// connect source to nodes and nodes to sink
	For (i, 1, N+1) {
        if (inp[i][1] <= 100) connect(1, 2*i, INF);
        if (inp[i][1] >= W-100) connect(2*i+1, 2*(N+1), INF);
	}
	For (i, 1, N+1) For (j, i+1, N+1) {
        if ((inp[i][0] - inp[j][0])*(inp[i][0] - inp[j][0]) + (inp[i][1] - inp[j][1])*(inp[i][1] - inp[j][1]) <= 40000) {
            connect(2*i+1, 2*j, INF);
            connect(2*j+1, 2*i, INF);
        }
	}

	N = 2*N+3;
	w<<maxflow()<<e;
}
