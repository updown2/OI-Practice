/*
https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/COCI/official/2009/contest3_solutions/solutions.pdf
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
//500,000,000 operations
const int MAXN = 5000, MOD = 1000000007;
//Global Variables
int N, M, dist[MAXN], dpin[MAXN], dpout[MAXN], out[MAXN], edges[MAXN][3];
bool visin[MAXN], visout[MAXN], take[MAXN];
vector<pair<int, int> > adj[MAXN];
vector<int> gra[MAXN], bck[MAXN];
priority_queue<pair<int, int> > nex; /// (-dist, node)

void dfsin(int at) {
    if (visin[at]) return;
    visin[at] = true;
	for (int i: bck[at]) {dfsin(i); dpin[at] += dpin[i];}
	if (dist[at] == -1) dpin[at] = 0;
}
void dfsout(int at) {
    if (visout[at]) return;
    visout[at] = true;
	dpout[at] = 1;
	for (int i: gra[at]) {dfsout(i); dpout[at] += dpout[i];}
	if (dist[at] == -1) dpout[at] = 0;
}

main() {
	//ifstream cin ("test.in");
	ios_base::sync_with_stdio; cin.tie(0);
	cin >> N >> M;
	ffj {int a, b, d; cin >> a >> b >> d; a--; b--; adj[a].pb(mp(b, d)); edges[j][0] = a; edges[j][1] = b; edges[j][2] = d;}
	ffi {
		For (j, 0, N) {dist[j] = -1; gra[j].clear(); bck[j].clear(); dpin[j] = dpout[j] = 0; visin[j] = visout[j] = false;}
		ffj take[j] = false;
		nex.push(mp(0, i));
		while (!nex.empty()) {
			int d = nex.top().a, at = nex.top().b; nex.pop();
			if (dist[at] != -1) continue;
			dist[at] = -d;
			for (auto j: adj[at]) nex.push(mp(d-j.b, j.a));
		}
		//w<< "starting at" s i+1<<e;
		ffj {
			if (dist[edges[j][0]] + edges[j][2] == dist[edges[j][1]]) {
                //w<< "adding edge" s j+1<<e;
				gra[edges[j][0]].pb(edges[j][1]);
				bck[edges[j][1]].pb(edges[j][0]);
				take[j] = true;
			}
		}
		dpin[i] = 1; visin[i] = visout[i] = true;
		For (j, 0, N) {dfsin(j); dfsout(j);}
		//For (j, 0, N) w<< j+1 s dist[j] s dpin[j] s dpout[j]<<e;
		ffj if (take[j]) {
			out[j] += dpin[edges[j][0]] * dpout[edges[j][1]];
			out[j] %= MOD;
		}
	}
	ffj w<< out[j]<<e;
}
