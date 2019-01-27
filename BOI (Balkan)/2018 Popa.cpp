/*
https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/Balkan/official/2018/popa_solution.pdf
*/
#include <popa.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, P)
#define ffa ffi ffj
#define s <<" "<<
//#define c <<" : "<<
#define w cout
#define e endl//"\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
//#define int ll
//500,000,000 operations
const int MAXN = 1000;
//Global Variables
int solve(int N, int* l, int* r) {
    int par[MAXN];
    ffi l[i] = r[i] = par[i] = -1;
    int root = 0;
    For (i, 1, N) {
        /// start at i-1 and go up to the root
        /// going to be a right child or the root
        int at = i-1;
        if (!query(at, i, i, i)) {
            r[at] = i;
            par[i] = at;
            //w<< "added" s i s "to the right of" s at<<e;
        }
        else {
            while (at != root && query(par[at], i, i, i)) at = par[at];
            /// i is the parent of at
            if (at == root) {
                l[i] = at;
                par[at] = i;
                root = i;
                //w<< "made" s i s "the root"<<e;
            }
            else {
                /// replace the right child of the parent
                r[par[at]] = i;
                par[i] = par[at];
                par[at] = i;
                l[i] = at;
            }
        }
    }
    return root;
}
    ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    ffi cin >> inp[i];
    w<< "Root =" s solve(N, L, R)<<e;
    ffi w<< L[i] s R[i]<<e;
}
