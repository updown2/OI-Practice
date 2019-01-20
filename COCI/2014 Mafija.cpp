/*
greedily take nodes starting with leaves
when you are left with only cycles, take one node and then repeat the greedy process
*/
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
//#define int ll
const int MAXN=500000, INF=1000000000;
///500,000,000
int N, nex[MAXN], out, und[MAXN];
bool take[MAXN], vis[MAXN], on[MAXN], del[MAXN];
vector<int> in[MAXN];
queue<int> next1;

void rem(int at) {
    if (del[at]) return;
    del[at] = vis[at] = true;
    und[nex[at]] --;
}

void go(int at) {
    if (vis[at]) return;
    vis[at] = true;
    for (int i: in[at]) {
        go(i);
    }
    for (int i: in[at]) if (take[i]) {
        rem(at);
        return;
    }
    if (take[nex[at]]) {
        rem(at);
        return;
    }
    if (und[at] == 0) {
        take[at] = true;
        rem(at);
        //w<< "took" s at+1<<e;
    }
}

main() {
    //ifstream cin("test.in");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	ffi {cin >> nex[i]; nex[i]--; in[nex[i]].pb(i);}
	ffi und[i] = in[i].size();
	ffi go(i);
	ffi vis[i] = false;
	ffi go(i);
	/// take care of any cycles
	ffi vis[i] = false;
	ffi if (!del[i]) {
        take[i] = true;
        go(i);
	}
	//ffi w<< i+1 s take[i] s del[i]<<e;
	/// anything not deleted is part of a cycle
	ffi if (take[i]) out++;
	w<< out<<e;
}
