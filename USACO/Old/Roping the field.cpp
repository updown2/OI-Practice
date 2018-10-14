/*
dp[pole1][pole2] = max number of lines in this region
*/
//#include <bits/stdc++.h>
#include<iostream>
#include<assert.h>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
#include<queue>
#include<math.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(ll i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, G)
#define ffa ffi ffj
#define s <<" "<<
#define c <<" : "<<
#define w cout
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
//#define double long double
//#define ll ll
const ll MAXN=150, INF=1000000000;
///500,000,000
ll N, G, posts[MAXN][2], circles[MAXN][2], R, dp[MAXN][MAXN], out;

ll dist(ll x1, ll y1, ll x2, ll y2) {
    return (y2-y1)*(y2-y1) + (x2-x1)*(x2-x1);
}

bool line(int a, int b) {
    /// can i put a line from post a to post b
    if(abs(a-b) <= 1 || abs(a-b) >= N-1) return false;
    ffj {
        /// check if the line llersects the circle
        /// first check if either of the endpts are in the circle
        if (dist(posts[a][0], posts[a][1], circles[j][0], circles[j][1]) <= R*R) return false;
        if (dist(posts[b][0], posts[b][1], circles[j][0], circles[j][1]) <= R*R) return false;
        /// find the closest pt on the line to the circle using ternary search
        ll x1 = posts[a][0], x2 = posts[b][0], y1 = posts[a][1], y2 = posts[b][1], x0 = circles[j][0], y0 = circles[j][1];
        //assert(((y2-y1)*x0 - (x2-x1)*y0 + x2*y1 - y2*x1)*((y2-y1)*x0 - (x2-x1)*y0 + x2*y1 - y2*x1) > 0);
        ll d = ceil( abs((double)(y2-y1)*x0 - (x2-x1)*y0 + x2*y1 - y2*x1) /sqrt((double)(y2-y1)*(y2-y1) + (x2-x1)*(x2-x1))); ///distance squared
        //w<< "d" c d<<e;
        if (d > R) continue;
        double m1 = (y2-y1)/(double)(x2-x1);
        double m2 = -1/m1;
        double x = (y1-y0+m2*x0 - m1*x1)/(double)(m2-m1);

        if (x1 == x2) {
            ///closest y is circle[j][1]
            ll y = circles[j][1];
            //w<< "same x, y =" s y<<e;
            if (y < max(y1, y2) && y > min(y1, y2)) return false;
            continue;
        }
        if (y1 == y2) {
            x = circles[j][0];
        }
        //w<< a s b s j c x<<e;
        //w<< "circle" s j s "is closest at point" c x<<e;
        if (x > min(x1, x2) && x < max(x1, x2)) return false;

    }
    return true;
}

int main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> G >> R;
    ffi cin >> posts[i][0] >> posts[i][1];
    ffj cin >> circles[j][0] >> circles[j][1];
    //ffi {For (j, i+1, N) {w<< i s j c line(i, j)<<e;}}
    For (siz, 2, N+1) {
        For (st, 0, N) { /// i is the start
            /// loop through all llermediate for break pts
            ll en = (st+siz);
            if (en >= N) break;
            //w<< "going" c st s en<<e;
            For (j, st+1, st+siz) {
                //w<< "j" c j s dp[st][j] s dp[j+1][en]<<e;
                dp[st][en] = max(dp[st][en], dp[st][j]+dp[j][en]);
            }
            if (line(st, en)) dp[st][en]++;
            //w<< "dp" s st s en c line(st, en) s dp[st][en]<<e;
            out = max(out, dp[st][en]);
        }
    }
    w<< out <<e;
}
