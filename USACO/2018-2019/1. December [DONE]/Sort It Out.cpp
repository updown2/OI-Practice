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
#define e endl//"\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int unsigned long long
const int MAXN=100001, INF = 1000000000000000000;
///500,000,000
int N, K, inp[MAXN], sm[MAXN], len, loc1[MAXN], loc2[MAXN], ind[MAXN], prevv;
vector<int> vals[MAXN], ft[MAXN];
/// vals is sorted
bool dont[MAXN];

void update(int y, int x, int v) {while(x<=ft[y].size()-1) ft[y][x]= ft[y][x] + v, x+=(x&-x);}
int query (int y, int x) { return x>0 ? ft[y][x]+query(y, x-(x&-x)):0;}

void go(int at) {
    //w<< at<<e;
    if (at > len) return;
    int x = vals[at].size()-1;
    for (int i=x; i>=1; i--) {
        if (prevv > ind[vals[at][i]]) continue;
        int y = query(at, i) - query(at, i-1);
        //w<< K s y<<e;
        if (K > y) K = K-y;
        else {
            /// take val[at][i] in lis
            //w<< "removing" s vals[at][i]<<e;
            dont[vals[at][i]] = true;
            prevv = ind[vals[at][i]];
            go(at+1);
            return;
        }
    }
    assert(false);
    //w<< "DASa"<<e;
}

main() {
    //ifstream cin("test.in");
    ifstream cin("itout.in"); ofstream cout("itout.out");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	ffi {cin >> inp[i]; sm[i+1] = INF; ind[inp[i]] = i;}
	For (i, 0, N+1) {vals[i].pb(0); ft[i].pb(0);}
	ffi {
        /// find ind w sm[ind] < inp[i]
        int a = 0, b = N;
        while (a != b) {
            int mid = (a+b+1)/2;
            if (sm[mid] < inp[i]) a = mid;
            else b = mid-1;
        }
        a++;
        loc1[inp[i]] = a;
        vals[a].pb(inp[i]); sm[a] = inp[i]; ft[a].pb(0);
        len = max(len, a);
	}
	For (i, 1, len+1) sort(vals[i].begin(), vals[i].end());
	For (i, 1, len+1) {
        For (j, 1, vals[i].size()) loc2[vals[i][j]] = j;
	}
	//w<< len<<e; For (i, 0, len+1) {w<< i << ":"; for (int j: vals[i]) w s j; w<<e;}
	bool st = true;
	for (int i=N-1; st; i--) {
        if (i == 0) st = false;
        /// turn on inp[i]
        int j = inp[i];
        if (loc1[j] == len) {
            /// set to 1
            update(loc1[j], loc2[j], 1);
        }
        else {
            /// binary search and suffix sum
            int k = loc1[j];
            if (vals[k+1][vals[k+1].size()-1] < j) continue; /// stays at 0
            /// find vals[k+1][ind] > j
            int a = 1, b = vals[k+1].size()-1;
            while (a != b) {
                int mid = (a+b)/2;
                if (vals[k+1][mid] < j) a = mid+1;
                else b = mid;
            }
            //w<< "updating" s inp[i]<<e;
            update(k, loc2[j], min(INF, query(k+1, ft[k+1].size()-1) - query(k+1, a-1)));
        }
	}
	//For (i, 1, len+1) {w<< i << ":"; for (int j: vals[i]) w s j; w<<e;}
	//For (i, 1, len+1) {w<< i << ":"; For (j, 1, ft[i].size()) w s query(i, j)-query(i, j-1); w<<e;}
	go(1);
	w<< N-len<<e;
	For (i, 1, N+1) if (!dont[i]) w<< i<<e;
}
