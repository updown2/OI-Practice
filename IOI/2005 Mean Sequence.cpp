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
//500,000,000 operations
const int MAXN = 5000001, INF=2000000000;
//Global Variables
int N, inp[MAXN], upd[MAXN], outbi = INF, outsm;

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N; ffi cin >> inp[i];
    upd[0] = inp[0];
    For (i, 1, N+1) {
        upd[i] = inp[i-1]*2 - upd[i-1];
        if (upd[i] < upd[i-1]) outsm = max(outsm, (1+upd[i-1]-upd[i])/2);
    }
    N++;
    //ffi w<< upd[i]<<" "; w<<e;
    for (int i=1; i+1<N; i+= 2) {
        outbi = min(outbi, 1+(upd[i+1]-upd[i])/2);
    }
    w<< max(0, outbi-outsm)<<e;
    //w<< outsm s outbi<<e;
}
