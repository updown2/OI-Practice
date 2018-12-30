/*
for the vertical line, x=test
move everything to the top, divide the graph into 10 sections relative to the line
for every point, store the x=test needed to move it one section to the left
When a point moves sections, calculate the answer because
the answer has to have a point a line dividing sections
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
#define x first
#define b second
#define y second
#define int ll
const int MAXN=100000, INF=1000000000000000000;
///500,000,000
int N, S, x[10], y[10], out=INF;
pair<int, int> inp[MAXN];
priority_queue<pair<int, int> > sec[10]; /// (-test, index of point)

void add0 (int i) {
    sec[0].push(mp(-(inp[i].x-inp[i].y), i));
    x[0] += inp[i].x;
    y[0] += inp[i].y;
}
void add1 (int i) {
    sec[1].push(mp(-(inp[i].x), i));
    x[1] += inp[i].x;
    y[1] += inp[i].y;
}
void add2 (int i) {
    sec[2].push(mp(-(inp[i].x+inp[i].y), i));
    x[2] += inp[i].x;
    y[2] += inp[i].y;
}
void add3 (int i) {
    sec[3].push(mp(-(INF), i));
    x[3] += inp[i].x;
    y[3] += inp[i].y;
}
void add4 (int i) {
    sec[4].push(mp(-(inp[i].x-S), i));
    x[4] += inp[i].x;
    y[4] += inp[i].y;
}
void add5 (int i) {
    sec[5].push(mp(-(inp[i].x-inp[i].y), i));
    x[5] += inp[i].x;
    y[5] += inp[i].y;
}
void add6 (int i) {
    sec[6].push(mp(-(inp[i].x), i));
    x[6] += inp[i].x;
    y[6] += inp[i].y;
}
void add7 (int i) {
    sec[7].push(mp(-(inp[i].x+inp[i].y), i));
    x[7] += inp[i].x;
    y[7] += inp[i].y;
}
void add8 (int i) {
    sec[8].push(mp(-(inp[i].x+S), i));
    x[8] += inp[i].x;
    y[8] += inp[i].y;
}
void add9 (int i) {
    sec[9].push(mp(-(INF), i));
    x[9] += inp[i].x;
    y[9] += inp[i].y;
}

void calc_ans(int test) {
    int curr = 0;
    curr += y[0];
    curr += x[1] - test*(sec[1].size()-1);
    curr += test*(sec[2].size()-1) - x[2];
    curr += y[3];
    curr += y[4];
    curr += y[5] - x[5] + (S+test)*(sec[5].size()-1);
    curr += x[6] - y[6] + (S-test)*(sec[6].size()-1);
    curr +=-x[7] - y[7] + (S+test)*(sec[7].size()-1);
    curr += x[8] + y[8] - (test-S)*(sec[8].size()-1);
    curr += y[9];
    /*if (test == 6) {
        For (i, 0, 10) w<< i c x[i] s y[i]<<e;
        w<< "8 does" s x[8] + y[8] - (test-S)*(sec[8].size()-1) <<e;
        exit(0);
    }*/
    //w<< test s curr<<e;
    out = min(out, curr);
}

main() {
    //ifstream cin("test.in");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> S;
	For (i, 0, 10) sec[i].push(mp(-INF, -1));
	ffi {
	    cin >> inp[i].y >> inp[i].x; inp[i].y = abs(inp[i].y);
	    if (inp[i].y < S) add4(i);
	    else add0(i);
    }
    int r = 0, val = sec[0].top().a; For (i, 1, 10) if (sec[i].top().a > val) {val = sec[i].top().a; r = i;}
    while (val != -INF) {
        int test = -sec[r].top().a; int pt = sec[r].top().b;
        calc_ans(test); /// on the line is the same in either region
        sec[r].pop(); x[r] -= inp[pt].x; y[r] -= inp[pt].y;
        if (r == 0) add1(pt);
        if (r == 1) add2(pt);
        if (r == 2) add3(pt);
        if (r == 4) add5(pt);
        if (r == 5) add6(pt);
        if (r == 6) add7(pt);
        if (r == 7) add8(pt);
        if (r == 8) add9(pt);
        r = 0, val = sec[0].top().a; For (i, 1, 10) if (sec[i].top().a > val) {val = sec[i].top().a; r = i;}
    }
    w << out<<e;
}
