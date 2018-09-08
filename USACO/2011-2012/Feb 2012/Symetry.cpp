/*
lines are perpendicular from all pairs of points
remove pt on the center. All lines have to intersect on the center
every pt (except removed center) can be at most on one line
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 1, N+1)
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
#define int ll
const int MAXN=1001, INF=1000000000, MOD = 1000000007;
///500,000,000
int N, pts[MAXN][2];
set<pair<int, pair<int, int> > > lines;//, fail;
int gcd(int a, int b) { return a==0 ? b:gcd(b%a, a); }

bool on(int ind, pair<int, pair<int, int> > line) {
    /// check that Ax + By = C
    return line.a*pts[ind][0] + line.b.a*pts[ind][1] == line.b.b;
}

pair<int, pair<int, int> > red(pair<int, pair<int, int> > i) {
    if (i.a < 0) {
        i.a *= -1;
        i.b.a *= -1;
        i.b.b *= -1;
    }
    if (i.a == 0 && i.b.a < 0) {
        i.b.a *= -1;
        i.b.b *= -1;
    }
    /// two zeros
    if (i.b.a == 0 && i.b.b == 0) i.a = 1;
    if (i.a == 0 && i.b.b == 0) i.b.a = 1;
    /// one zero
    if (i.a == 0) {
        int save = gcd(i.b.a, i.b.b);
        i.b.a /= save;
        i.b.b /= save;
    }
    if (i.b.a == 0) {
        int save = gcd(i.a, i.b.b);
        i.a /= save;
        i.b.b /= save;
    }
    if (i.b.b == 0) {
        int save = gcd(i.a, i.b.a);
        i.a /= save;
        i.b.a /= save;
    }
    /// no zeros
    int save = gcd(i.a, gcd(i.b.a, i.b.b));
    i.a /= save;
    i.b.a /= save;
    i.b.b /= save;
    return i;
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    ffi cin >> pts[i][0] >> pts[i][1];
    ffi {
    //For (i, 1, 3) {
        //w<< "i = " << i<<e;
        set<pair<int, pair<int, int> > > temp, del;
        For (j, 1, N+1) {
            if (i == j) continue;
            /// try adding the perpendicular to pts i & j
            /// check if the line already exists
            int k = i;
            int l = j;
            //if (pts[i][0] < pts[j][0] || (pts[i][0] == pts[j][0] && pts[i][1] < pts[j][1])) swap(k, l);
            pair<int, pair<int, int> > cur = red(mp(2*(pts[k][0]-pts[l][0]), mp(2*(pts[k][1]-pts[l][1]), pts[k][0]*pts[k][0]-pts[l][0]*pts[l][0]+pts[k][1]*pts[k][1]-pts[l][1]*pts[l][1])));
            //w<< "got line" c cur.a s cur.b.a s cur.b.b<<e;
            if (lines.find(cur) != lines.end()) {
                temp.insert(cur);
                continue;
            }
            //if (fail.find(cur) != fail.end()) continue;
            /// check if the previous points are on the line

            for ( k=i-1; k>=1 && on(k, cur); k--) {}
            //w<< "k" c k<<e;
            if (k == 0) temp.insert(cur);
            //else fail.insert(cur);
        }
        /// see if all the existing lines work with the current pt
        for (auto j: lines) {
            if (temp.find(j) != temp.end()) {
                temp.erase(j); /// we don't need to verify this line with the previous pts or add it
                continue;
            }
            else if (on(i, j)) {}
            else del.insert(j);
        }
        for (auto j: del) {
            //w<< "deleting" c j.a s j.b.a s j.b.b<<e;
            lines.erase(j);
            //fail.insert(j);
        }
        for (auto j: temp) lines.insert(j);
        //w<< "lines" c lines.size()<<e;
    }
    //w<< "lines.size() is currently" s lines.size()<<e;
    /// check if all on the same line
    int k = 1;
    int l = 2;
    pair<int, pair<int, int> > best = red(mp(pts[k][1]-pts[l][1], mp(pts[l][0]-pts[k][0], (pts[k][1]-pts[l][1])*pts[k][0]+(pts[l][0]-pts[k][0])*pts[k][1] )));
    For (i, 3, N+1) {
        int k = 1;
        int l = i;
        //if (pts[k][0] < pts[l][0] || (pts[k][0] == pts[l][0] && pts[k][1] < pts[l][1])) swap(k, l);
        pair<int, pair<int, int> > cur = red(mp(pts[k][1]-pts[l][1], mp(pts[l][0]-pts[k][0], (pts[k][1]-pts[l][1])*pts[k][0]+(pts[l][0]-pts[k][0])*pts[k][1] )));
        if (cur != best) {
            //w<< "needed" s best.a s best.b.a s best.b.b<<e;
            //w<< "at i =" s i s ", got" s cur.a s cur.b.a s cur.b.b<<e;
            w<< lines.size()<<e; return 0;
        }
    }
    w<< lines.size()+1<<e;
}
