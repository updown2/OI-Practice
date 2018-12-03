#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, Q)
#define ffa ffi ffj
#define s <<" "<<
#define c <<" : "<<
#define w cout
#define e endl // "/n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
//500,000,000 operations
const int MAXN = 1000000, MOD = 1000000007;
//Global Variables
int T, N, hsh0, mul= 2, inv[MAXN], hsh[MAXN], p[MAXN];
string a;

int see(int st, int en) {
    if (st == 0) return hsh[en];
    return (((hsh[en]-hsh[st-1]+MOD)%MOD)*inv[st])%MOD;
}
int mI(int x, int y) {
    if (y == 0) return 1;
    int p = mI(x, y/2) % MOD; p = (p * p) % MOD;
    return (y%2 == 0)? p : (x * p) % MOD;
}


main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    p[0] = 1; For (i, 1, MAXN) p[i] = (p[i-1]*mul)%MOD, inv[i] = mI(p[i], MOD-2);
    For (t, 1, T+1) {
        cin >> a; N = a.length();
        hsh[0] = (a[0]-'A'+1); For (i, 1, N) hsh[i] = (hsh[i-1]+ (a[i]-'A'+1)*p[i])%MOD;
        bool ans = false;
        For (len0, (N+1)/2, N) {
            if (len0 == 3) hsh0 = see(0, len0-1);
            bool good = true;
            int st;
            for (st = len0; st+len0 < N; st += len0) {
                if (see(st, st+len0-1) != hsh0) good = false;
            }
            /// check last bit [st, N-1]
            if (see(st, N-1) != see(0, N-1-st)) good = false;
            if (good) {ans = true; break;}
        }
        if (ans) w<< "OK"<<e;
        else w<< "MESSY"<<e;
    }
}
