/*
use persistence for the location of the beads and the swapper number for the time
*/
#include <bits/stdc++.h>
//#include "lib1739.h"
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 1, N+1)
#define ffj For(j, 1, M+1)
#define ffa ffi ffj
#define s <<" "<<
#define w cout
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
//define int ll
const int MAXN=300001, INF=100000000;
///500,000,000
int N, M, Q, bead[MAXN];
vector<int> loc[MAXN], tim[MAXN];

int main() {
    //ifstream cin("test.in");
    //ofstream cout("test.out");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    ffi {bead[i] = i; loc[i].pb(i); tim[i].pb(0);}
    ffj {
        int a; cin >> a;
        int b1 = bead[a], b2 = bead[a+1];
        bead[a] = b2, bead[a+1] = b1;
        loc[b1].pb(a+1), loc[b2].pb(a);
        tim[b1].pb(j), tim[b2].pb(j);
    }
    //ffi {w<< i s ":" <<e;For (j, 0, loc[i].size()) w<< loc[i][j] s "at" s tim[i][j]<<e;}

    //Q = getNumQuestions();
    cin >> Q;
    For (q, 0, Q) {
        int K, J;
        //getQuestion(K, J);
        cin >> K >> J;
        int a = 0, b = tim[K].size()-1;
        /// find the last tim less than or equal to J
        while (a != b) {
            int mid = (a+b+1)/2;
            if (tim[K][mid] <= J) a = mid;
            else b = mid-1;
        }
        //answer(loc[K][a]);
        w<< loc[K][a]<<e;
    }
}
