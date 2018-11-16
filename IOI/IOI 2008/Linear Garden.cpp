/*
Consider a graph where L is down and P is up. The total difference in height <= 2
add all possibilities
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, K)
#define ffa ffi ffj
#define s <<" "<<
#define c <<" : "<<
#define w cout
#define e endl//"\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
//500,000,000 operations
const int MAXN = 1000000, INF = 1000000000;
//Global Variables
int N, M, out, lo, hi, curr, p2[MAXN];
string in;

main() {
	//ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> in;
    p2[0] = 1;
    For (i, 1, N) p2[i] = (2*p2[i-1])%M;
    ffi {
        if (in[i] == 'P') {
            int ch = hi, cl = min(lo, curr-1), cc = curr-1;
            curr++;
            //w<< "temp" s i s cc c cl s ch<<e;
            if (ch > 2+cl) {}
            else if (ch == 1+cl) out += p2[(N-i)/2]+p2[(N-i-1)/2]-1;
            else if (cc == 1+cl) out += p2[(N-i)/2];
            else out += p2[(N-i-1)/2];
            out %=M;
            //w<< i c out<<e;
        }
        else curr--;
        lo = min(lo, curr); hi = max(hi, curr);
        //w<< "perm" s i s curr c lo s hi<<e;
    }
    if (hi-lo <= 2) out ++;
    out %= M;
    w<< out<<e;
}
