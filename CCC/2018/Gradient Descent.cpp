/*
binary search using a box of 4 squares
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, M)
#define ffa ffi ffj
#define s <<" "<<
#define w cout
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
const int MAXN=100, INF=1000000000000000000;
///500,000,000
int N, M, K;
map<pair<int, int>, int> have;

int get(int x, int y) {
    if (have.find(mp(x, y)) != have.end()) return have[mp(x, y)];
    printf("? %I64d %I64d\n", x, y);
    //w<< '?' s x s y<<e;
    fflush(stdout);
    int a; cin >> a;
    have[mp(x, y)] = a;
    return a;
}

void solve(int x1, int x2, int y1, int y2) {
    //w<< x1 s x2 s "," s y1 s y2<<e;
    if (x1 == x2 && y1 == y2) {
        /// done
        int a = get(x1, y1);
        printf("! %I64d\n", a);
        //w<< '!' s a<<e;
        fflush(stdout);
        return;
    }
    if (x1 == x2) {
        int m1 = (y1+y2)/2; int m2 = m1+1;
        int q1 = get(x1, m1), q2 = get(x1, m2);
        if (q1 == q2) solve(x1, x2, m1, m1);
        else if (q1 < q2) solve(x1, x2, y1, m1);
        else solve(x1, x2, m2, y2);
        return;
    }
    if (y1 == y2) {
        int m1 = (x1+x2)/2; int m2 = m1+1;
        int q1 = get(m1, y1), q2 = get(m2, y1);
        if (q1 == q2) solve(m1, m1, y1, y2);
        else if (q1 < q2) solve(x1, m1, y1, y2);
        else solve(m2, x2, y1, y2);
        return;
    }
    int m1x = (x1+x2)/2, m2x = m1x+1, m1y = (y1+y2)/2, m2y = m1y+1;


    int q11 = get(m1x, m1y), q12 = get(m1x, m2y), q21 = get(m2x, m1y);

    if ( (q11 == q12 && q11 == q21) || (q11 >= max(q12, q21)) ) solve(m2x, x2, m2y, y2);
    else if (q11 <= min(q21, q12)) solve(x1, m1x, y1, m1y);
    else if (q12 <= min(q21, q11)) solve(x1, m1x, m2y, y2);
    else solve(m2x, x2, y1, m1y);
}

main() {
    //ifstream cin("test.out");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K;
    solve(1, N, 1, M);
}
