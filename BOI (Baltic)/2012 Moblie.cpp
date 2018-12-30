/*
binary search on the answer
to test a value x, for all the circles come up with ranges of the line that is covered if the circle has a radius x
find the minimum value x s.t. the whole line is covered
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
//#define double long double
const int MAXN=1000000;
///500,000,000
int N, L;
pair<int, int> pts[MAXN];
pair<double, double> rng[MAXN];

bool full(double rr) {
    /// make the ranges
    ffi {
        int x = pts[i].a, y = pts[i].b;
        if ((ll)y*y > (long double)rr*rr) {rng[i] = mp(0, 0); continue;}
        double a = sqrt((long double)rr*rr-(long double)y*y);
        double l = x - a; double r = x + a;
        l = max(l, (double) 0); l = min(l, (double)L);
        r = max(r, (double) 0); r = min(r, (double)L);
        rng[i] = mp(l, r);
    }
    //w<< rr<<e; ffi w<< rng[i].a s rng[i].b<<e;
    /// see if the whole range is covered
    double far = 0;
    ffi {
        if (rng[i].a > far) continue;
        far = max(far, rng[i].b);
    }
    return far >=L;
}

main() {
    //ifstream cin("test.in");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> L;
	double a = 2236067978, b = 2236067978;
	ffi {
	    cin >> pts[i].a >> pts[i].b;
	    int x = pts[i].a, y = pts[i].b;
	    double use1 = sqrt((long double)x*x+(long double)y*y);
	    double use2 = sqrt((long double)(x-L)*(x-L)+(long double)y*y);
	    b = min(b, max(use1, use2));
	    a = min(a, min(use1, use2));
	}
	while (b-a > .001) {
        double mid = (a+b)/2;
        if (full(mid)) b = mid;
        else a = mid;
	}
	w<< fixed << setprecision(6) <<a<<e;
}
