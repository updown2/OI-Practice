#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, Q)
#define ffa ffi ffj
#define s <<" "<<
//#define c <<" : "<<
#define w cout
#define e endl // "/n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
//500,000,000 operations
const int MAXN = 2000, INF = 100000000000000;
//Global Variables
int T, N, out;

struct Point {int x,y;} a, b, c, x, y;

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    return (val > 0)? 1: 2;
}

bool hit(Point p1, Point q1, Point p2, Point q2) {
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    return (o1 != o2 && o3 != o4);
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    For (t, 1, T+1) {
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
        cin >> N;
        out = 0;
        ffi {
            cin >> x.x >> x.y >> y.x >> y.y;
            int sum = 0;
            if (hit(a, b, x, y)) sum++;
            if (hit(a, c, x, y)) sum++;
            if (hit(c, b, x, y)) sum++;
            if (sum%2 == 1) out++;
        }
        w<< "Scenario" s t<<":" s out<<e;
    }
}
