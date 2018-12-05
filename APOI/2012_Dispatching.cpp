/*
https://github.com/timpostuvan/CompetitiveProgramming/blob/master/Olympiad/APIO/Dispatching2012.cpp
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
#define int ll
const int MAXN=100000, INF=1000000000000000000;
///500,000,000
int N, M, C[MAXN], L[MAXN], out, tot[MAXN];
vector<int> und[MAXN];
multiset<int> vals[MAXN];
multiset<int>::iterator it;

void go(int at) {
    int big = 0, cnt = 0; tot[at] = C[at];
    for (int i: und[at]) {
        go(i);
        tot[at] += tot[i];
        if ((int)vals[i].size() > cnt) {
            cnt = vals[i].size();
            big = i;
        }
    }
    swap(vals[at], vals[big]);
    vals[at].insert(C[at]);
    for (int i: und[at]) if (i != big) {for (int x: vals[i]) vals[at].insert(x);}
    while (tot[at] > M) {
        it = vals[at].end(); it--;
        tot[at] -= (*it);
        vals[at].erase(it);
    }
    out = max(out, (int)vals[at].size()*L[at]);
}


main() {
    //ifstream cin("test.in");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	ffi {int a; cin >> a >> C[i] >> L[i]; if (a != 0) und[a-1].pb(i);}
	go(0);
	w<< out<<e;
}
