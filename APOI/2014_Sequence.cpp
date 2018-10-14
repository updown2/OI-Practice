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
//deque<int> hull; ///(ind)
int hull[MAXN], l=1, r;

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
    ll A = val[ind].A, B = val[ind].B;
    while (l != r+1) {
        int j = hull[r];
        if (val[j].yl <= A*val[j].l+B) r--;
        else break;
    }
    if (l != r+1) {
        int last = hull[r];
        if (val[last].yb < val[ind].yb) {
            /// split the range
            ll x = (val[last].B - B)/(A - val[last].A);
            r++; hull[r] = ind;
            val[last].r = x;
            val[ind].l = x+1;
            val[ind].yl = A*(x+1) + B;
            val[ind].r = BIG;
        }
    }
    while (l != r+1 && val[hull[l]].r < X) l++;

    if (l==r+1) {
        r++; hull[r] = ind;
        ///range: 0-BIG
        val[ind].l = 0;
        val[ind].yl = B;
        val[ind].r = BIG;
    }
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	cin >> pre[0];
	For (i, 1, N) {int a; cin >> a; pre[i] = a+pre[i-1];}
	For (j, 1, K+1) {
        l = 1; r = 0;
        put(j-1, j-1, pre[j]);
        For (i, j, N) {
            int k = hull[l];
            dp[i][j%2] = val[k].A*pre[i]+val[k].B;
            from[i][j] = k;
            if (i != N-1) put(i, j-1, pre[i+1]);
            //w<< l s r<<e;
            //w<< "dp["<< i+1 <<"]["<<j<<"]:" s dp[i][j%2]<<e;
        }
	}
	//ffj {ffi w<< from[i][j]+1<< " "; w<<e;}w<<e;
	//ffi w<< pre[i]<<e;
	w<< dp[N-1][K%2]<<e; int at = N-1; for (int j=K; j>=1; j--) {w<< from[at][j]+1<< " ";at = from[at][j];}w<<e;
}
