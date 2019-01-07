/*
https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/COCI/official/2017/contest6_solutions/solutions.pdf
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
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
//#define int ll
const int MAXN=100000, MM = 10000001, INF=1000000000;
///500,000,000
int N, big, par[MAXN], siz[MAXN], go[MM], prea, prex, preadd;
ll out;
set<int> inp;
vector<int> vals;
vector< pair<int, int> > edges[MM]; /// [weight] = (n1, n2)

void make(int n1, int x, int add=0) {
    int a;
    if (x > big) a = N;
    else a = go[x];
    if (add == 0) {
        if (a != prea) {
            edges[vals[prea]-prex+preadd].emplace_back(n1, prea);
            //w<< "connecting" s n1+1 s prea+1 c vals[prea]-prex+preadd<<e;
        }
    }
    prea = a;
    prex = x;
    preadd = add;
}

int root (int x) {
    if (par[x] == x) return x;
    par[x] = root(par[x]);
    return par[x];
}
int join(int a, int b) {
    if (siz[a] > siz[b]) {
        /// push b into a
        siz[a] += siz[b];
        par[b] = a;
    }
    else {
        /// push a into b
        siz[b] += siz[a];
        par[a] = b;
    }
}

main() {
    //ifstream cin("test.in");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	ffi {int a; cin >> a; inp.insert(a); par[i] = i; siz[i] = 1;}
	for (int i: inp) vals.pb(i); vals.pb(INF);
	big = vals[vals.size()-2];
	N = vals.size()-1;
	go[MM-1] = N;
	for (int i=MM-2; i>=0; i--) {
        go[i] = go[i+1];
        if (go[i+1] != 0 && i == vals[go[i+1]-1]) go[i]--;
	}
	ffi {
        int x = vals[i];
        make(i, x+1, 1);
        for (int j=x+x; j<=big+x; j+=x) {
            make(i, j);
        }
	}
	For (i, 0, MM) for (auto j: edges[i]) {
        int a = j.a, b = j.b;
        if (root(a) == root(b)) continue;
        out += i;
        join(par[a], par[b]); /// just called root so this should be fine
	}
	w<< out<<e;
}
