/*
look at every node as a starting point and loop downwards to nodes with the same value to use them
(dont look at those nodes as starting nodes in the future though bc too slow then, just count everything at once)
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
const int MAXN=1000, INF=1000000000;
///500,000,000
int N, M, inp[MAXN][MAXN], cnt[MAXN][MAXN], out;
bool done[MAXN][MAXN];

stack<pair<int, int> > open;

main() {
    //ifstream cin("test.in");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	ffa cin >> inp[i][j];
	ffa cnt[i][j] = 1;
	ffi for (int j=M-2; j>=0; j--) if (inp[i][j] == inp[i][j+1]) cnt[i][j] = 1+cnt[i][j+1];
	//ffa w<< i s j s cnt[i][j]<<e;
	ffa if (!done[i][j]) {
	    while (!open.empty()) open.pop();
	    //w<< "checking out" s i s j<<e;
        int running = 0;
        for (int k=i; k<N && inp[k][j] == inp[i][j]; k++) {
            done[k][j] = true;
            int hv = 1;
            while (!open.empty() && open.top().a >= cnt[k][j]) {
                running -= open.top().a * open.top().b;
                hv += open.top().b;
                open.pop();
            }
            running += cnt[k][j]*hv;
            //w<< k c running<<e;
            open.push(mp(cnt[k][j], hv));
            out += running;
        }
        //w<< "got" s out<<e;
	}
	w<< out<<e;
}
