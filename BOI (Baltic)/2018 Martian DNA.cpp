#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, 100001)
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
const int MAXN=200000, INF=1000000000;
///500,000,000
int N, K, R, inp[MAXN], need[MAXN], more, out=INF;

void take (int x) {
    if (need[x] > 0) more--;
    need[x] --;
}
void del (int x) {
    if (need[x] >= 0) more++;
    need[x]++;
}

main() {
    //ifstream cin("test.in");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K >> R;
	ffi cin >> inp[i];
	For (i, 0, R) {
        int a, b; cin >> a >> b; need[a] += b; more += b;
	}
	int a = 0, b = 0;
	take(inp[0]);
	while (b < N-1 ) {
        while (more == 0) {
            out = min(out, b-a+1);
            del(inp[a]);
            a++;
        }
        while (more > 0 && b+1 < N) {
            b++;
            take(inp[b]);
        }
        if (more == 0) out = min(out, b-a+1);
	}
	if (out == INF) w<< "impossible"<<e;
	else w<< out<<e;
}
