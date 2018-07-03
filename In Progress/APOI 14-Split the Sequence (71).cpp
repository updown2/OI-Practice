/*
dp+convex hull trick
only add lines to the end of the hull bc slopes increase bc pre[i] increases
answer for i is >= answer for i-1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, K+1)
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
//500,000,000 operations
const int MAXN = 100000;
//Global Variables
int from[MAXN][201], N, K;
ll pre[MAXN], BIG=1000000000, dp[MAXN][2];
deque<int> hull; ///(ind)

struct Line { ///Ax+B
    ll A, B, l, r, yb, yl;
    Line() {A=0; B=0;}
    Line(int j, int line) {
        A = pre[j];
        B = dp[j][line%2]-pre[j]*pre[j];
        yb = A*BIG+B;
        //w<< j s ":" s A s B<<e;
        //w<< dp[j][line%2]-pre[j]*pre[j] s B<<e;
    }
}val[MAXN];

void put(int ind, int line, ll X) {
    val[ind] = Line(ind, line);

    while (!hull.empty()) {
        int j = hull.back();
        if (val[j].yl <= val[ind].A*val[j].l+val[ind].B) hull.pop_back();
        else break;
    }
    if (!hull.empty()) {
        int last = hull.back();
        if (val[last].yb < val[ind].yb) {
            /// split the range
            ll x = (val[last].B - val[ind].B)/(val[ind].A - val[last].A);
            hull.pb(ind);
            val[last].r = x;
            val[ind].l = x+1;
            val[ind].yl = val[ind].A*(x+1) + val[ind].B;
            val[ind].r = BIG;
        }
    }
    while (!hull.empty() && val[hull.front()].r < X) hull.pop_front();

    if (hull.empty()) {
        hull.pb(ind);
        ///range: 0-BIG
        val[ind].l = 0;
        val[ind].yl = val[ind].B;
        val[ind].r = BIG;
    }
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	cin >> pre[0];
	For (i, 1, N) {ll a; cin >> a; pre[i] = a+pre[i-1];}
	For (j, 1, K+1) {
        hull.clear();
        put(j-1, j-1, pre[j]);
        For (i, j, N) {
            int k = hull.front();
            dp[i][j%2] = val[k].A*pre[i]+val[k].B;
            from[i][j] = k;
            if (i != N-1) put(i, j-1, pre[i+1]);
            //w<< "dp["<< i+1 <<"]["<<j<<"]:" s dp[i][j%2]<<e;
            //w<< "added" s i s j-1<<e; For(i, 0, hull.size()) {w<<hull[i].a s (i==hull.size()-1? BIG:hull[i+1].a-1) c hull[i].b <<e;}w<<e;
        }
	}
	//ffj {ffi w<< dp[i][j]<< " "; w<<e;}w<<e;
	//ffj {ffi w<< from[i][j]+1<< " "; w<<e;}w<<e;
	//ffi w<< pre[i]<<e;

	w<< dp[N-1][K%2]<<e; ll at = N-1; for (ll j=K; j>=1; j--) {w<< from[at][j]+1<< " ";at = from[at][j];}w<<e;
}
