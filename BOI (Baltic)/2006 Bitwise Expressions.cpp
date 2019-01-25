/*
https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/Baltic/official/boi2006_solutions/bitwise_sol.pdf
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, P)
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
const int MAXN = 100, K=30;
//Global Variables
int N, P, siz[MAXN], sm[MAXN], big[MAXN], out;

bool works(int k) {
    int at = 0;
    bool ret = true;
    ffj {
        bool poss = false;
        For (x, at, at+siz[j]) if (big[x] & (1<<k)) poss = true;
        at += siz[j];
        if (!poss) ret = false;
    }
    if (!ret) {
        at = 0;
        ffj {
            For (x, at, at+siz[j]) if (big[x] & (1<<k) && (sm[x] & (1<<k)) == 0) {
                /// put a zero
                for (int y=k-1; y>=0; y--) big[x] |= (1<<y);
                //w<< "for" s (1<<k) s "skipped" s x+1<<e;
            }
            at += siz[j];
        }
        return false;
    }
    /// true but need to update for it
    at = 0;
    ffj {
        bool done = false;
        For (x, at, at+siz[j]) if (big[x] & (1<<k) && sm[x] & (1<<k)) done = true;
        For (x, at, at+siz[j]) if (big[x] & (1<<k) && (sm[x] & (1<<k)) == 0) {
            if (!done) {
                /// take the one
                done = true;
                sm[x] = 0;
                //w<< "for" s (1<<k) s "took" s x+1<<e;
            }
            else {
                /// put a zero
                for (int y=k-1; y>=0; y--) big[x] |= (1<<y);
                //w<< "for" s (1<<k) s "skipped" s x+1<<e;
            }
        }
        at += siz[j];
    }
    return true;
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> P; ffj cin >> siz[j]; ffi cin >> sm[i] >> big[i];
    for (int k=K; k>=0; k--) if (works(k)) out |= (1<<k);
    w<< out<<e;
}
