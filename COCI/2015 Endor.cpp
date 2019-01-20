/*
instead of collisions, imagine that the ants are walking through each other
for ants moving right, just add the remaining distance to the answer
for ants moving left, sweep left and keep updating with the ants moving right
each ant moving right will be applied for the same amount of time for each ant moving left (unless it's the first or last ant the and moving left collides with)
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
const int MAXN=100000, INF=1000000000;
///500,000,000
int N, K, L, pre[MAXN], have[40];
double out[40], dist[MAXN];
vector<pair<char, pair<int, int> > > inp; /// (dir, (loc, color) )

main() {
    //ifstream cin("test.in");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K >> L;
	ffi {
        int a, b; char d; cin >> a >> b >> d;
        if (d == 'L' && inp.size() == 0) {
            out[b] += a;
            continue;
        }
        inp.emplace_back(d, mp(a, b));
        if (d == 'D') out[b] += L-a;
	}
	N = inp.size();
	//For (i, 0, K) w<< out[i]<<e;
	pre[0] = inp[0].b.b;
	For (i, 1, N) {
        pre[i] = pre[i-1];
        if (inp[i].a == 'D') pre[i] += inp[i].b.b;
	}
	int lr = inp[0].b.a, cr = inp[0].b.a;
	/// deal with first and last segment and create dist[i]
	int cnt = 0;
	for (auto i: inp) {
        if (i.a == 'L') {
            /// keep current value until first right
            double go = (i.b.a-cr)/2.0;
            out[i.b.b] += go;
            /// add pre[i] to value after last collision
            go = lr + (i.b.a-lr)/2.0;
            //w<< cnt c go s (i.b.b+pre[cnt])%K<<e;
            out[(i.b.b+pre[cnt])%K] += go;
        }
        else {
            dist[cnt] = (i.b.a-cr)/2.0;
            //w<< dist[cnt] <<e;
            cr = i.b.a;
        }
        cnt++;
	}
	//For (i, 0, K) w<< out[i]<<e;
	for (int i=N-1; i>=0; i--) {
        if (inp[i].a == 'L') have[inp[i].b.b]++;
        else {
            /// rotate and add to the answer
            int upd[40];
            For (j, 0, K) upd[j] = have[((j-inp[i].b.b)+K)%K];
            For (j, 0, K) {
                have[j] = upd[j];
                out[j] += dist[i]*have[j];
            }
        }
	}
	For (i, 0, K) w<< fixed << setprecision(1)<< round(2*out[i])/2<<e;
}
