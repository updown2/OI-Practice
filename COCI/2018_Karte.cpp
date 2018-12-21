/*
last N-K are pass and are the smallest N-K (order doesn't matter)
first K are fail, from smallest to biggest
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
const int MAXN = 500000, INF = 10000000000;
//Global Variables
int N, K, a[MAXN], ans[MAXN];

void fail() {w<<-1<<e; exit(0);}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    ffi cin >> a[i];
    sort(a, a+N);
    For (i, 0, N-K) {
        ans[i] = a[i];
        if (ans[i] > K) fail();
    }
    For (i, N-K, N) {
        ans[i] = a[N-1+N-K-i];
        /// position is N-i-1
        if (ans[i] <= N-i-1) fail();
    }
    ffi w<< ans[i]<< " "; w<<e;
}
