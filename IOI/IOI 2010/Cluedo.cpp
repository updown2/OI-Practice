/*
Every query, eliminate one possibility in any category
19 queries to eliminate, 1 to answer
Don't guess with an option that is known to be incorrect bc it is possible to get no new information
*/
#include "grader.h"
#include "cluedo.h"
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
#define e endl
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
//500,000,000 operations
const int MAXN = 25;//, INF = 1000000000000000000;
//Global Variables
bool a[6], b[10], c[6];

void Solve(){
    For (i, 0, 6) a[i] = c[i] = true;
    For (i, 0, 10) b[i] = true;
    while (true) {
        int r, x, y, z;
        For (i, 0, 6) if (a[i]) {x = i; break;}
        For (i, 0, 10) if (b[i]){y = i; break;}
        For (i, 0, 6) if (c[i]) {z = i; break;}
        r = Theory(x+1, y+1, z+1);
        if (r == 0) return;
        if (r == 1) a[x] = false;
        if (r == 2) b[y] = false;
        if (r == 3) c[z] = false;
    }
}

