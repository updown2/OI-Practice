/*
https://www.oi.edu.pl/old/ioi/downloads/ioi2005-tasks-and-solutions-a5.pdf
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
const int MAXN=1000000;
///500,000,000
int N, C, out, b[MAXN], vals[MAXN];

main() {
    //ifstream cin("test.in");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	ffi {
	    int a; cin >> a; a--; b[i] = a;
	    int cw, ccw;
	    if (i <= a) {
            cw = a-i;
            ccw = -(N+i-a);
	    }
	    else {
            ccw = a-i;
            cw = a+N-i;
	    }
	    //w<< cw s ccw<<e;
	    if (abs(ccw) < cw) vals[i] = ccw;
	    else vals[i] = cw;
	}
	sort(vals, vals+N);
	//for (int i: vals) w<<i<<e;
	bool diff = false;
	For (i, 1, N) {
	    C = max(C, vals[i]-vals[i-1]-1);
	    if (vals[i] != vals[0]) diff = true;
	}
	C = max(C, (N+1)/2-vals[N-1] + vals[0]-(1-(N+1)/2));
	if (!diff) C++;
	//w<< "C:" s C<<e;
	out = (N-C)/2;

	For (i, 0, N/2) swap(b[i], b[N-i-1]);
	ffi {
	    int a = b[i];
	    int cw, ccw;
	    if (i <= a) {
            cw = a-i;
            ccw = -(N+i-a);
	    }
	    else {
            ccw = a-i;
            cw = a+N-i;
	    }
	    //w<< cw s ccw<<e;
	    if (abs(ccw) < cw) vals[i] = ccw;
	    else vals[i] = cw;
	}
	C = 0;
    sort(vals, vals+N);
	//for (int i: vals) w<<i<<e;
	diff = false;
	For (i, 1, N) {
	    C = max(C, vals[i]-vals[i-1]-1);
	    if (vals[i] != vals[0]) diff = true;
	}
	C = max(C, (N+1)/2-vals[N-1] + vals[0]-(1-(N+1)/2));
	if (!diff) C++;
	out = min(out, (N-C)/2);
	w<< out<<e;
}
