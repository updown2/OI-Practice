/*
sort edges by ending time
dp[edge] = min wasted time if we take this edge (up to d[edge])
dp[x] = min(dp[y] + a[x]-d[y] for all y where there is an edge from y -- x and d[y] <= a[x])
      = min(dp[y]-d[y] + a[x]) so we can store dp[y]-d[y] for all edges
add dp values to the node that the edge ends on (also store d[edge])
dp values form a monotomic queue (don't store all the values)
can binary search on a node to get the minimum value
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
//#define int ll
const int MAXN=100000, INF=1000000000;
///500,000,000
struct Edge {
    int a, b, c, d, loc1, loc2; /// loc1 --> loc2
} vals[MAXN];
bool comp(Edge a, Edge b) {
    return a.d < b.d;
}
int N, M, reach, T, out;
vector<pair<int, int> > nod[MAXN]; /// (dp[x] - d[x], d[x])

main() {
    //ifstream cin("test.in");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> reach >> T; reach--;
	For (i, 0, M) {
	    cin >> vals[i].loc1 >> vals[i].loc2 >> vals[i].a >> vals[i].b >> vals[i].c >> vals[i].d;
	    vals[i].loc1--; vals[i].loc2--;
	}
	sort(vals, vals+M, comp);
	nod[0].pb(mp(0, 0));
	ffj {
        int x = vals[j].loc1, y = vals[j].loc2;
        if (vals[j].d > T) continue;
        if (nod[x].size() == 0) continue;
        if (nod[x][0].b > vals[j].a) continue;
        //w<< "looking at" s j+1<<e;
        int a = 0, b = nod[x].size()-1;
        while (a != b) {
            int mid = (a+b+1)/2;
            if (nod[x][mid].b > vals[j].a) b = mid-1;
            else a = mid;
        }
        int dp = nod[x][a].a + vals[j].b - vals[j].c;
        if (nod[y].size() == 0 || nod[y][nod[y].size()-1].a > dp) {
            nod[y].emplace_back(dp, vals[j].d);
            //w<< "dp =" s dp+vals[j].d s dp s "d =" s vals[j].d<<e;
        }
	}
	if (nod[reach].size() == 0) w<< -1<<e;
	else w<< T + nod[reach][nod[reach].size()-1].a <<e;
}
