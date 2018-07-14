/*
try all pairs 1-2, 3-4, ... and save the values of all the cards
loop through all the letters and turn the pair if it already hasn't been flipped
*/
#include "grader.h"
#include "memory.h"
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
#define e endl
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
//500,000,000 operations
const int MAXN = 25;//, INF = 1000000000000000000;
//Global Variables
vector<int> loc[MAXN];

void play() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    For (i, 0, MAXN) {
        loc[faceup(i*2+1)-'A'].pb(i*2+1);
        loc[faceup(i*2+2)-'A'].pb(i*2+2);
    }
    For (i, 0, MAXN) {
        if (loc[i][0] %2 == 1 && loc[i][0] == loc[i][1]-1) continue;
        faceup(loc[i][0]);
        faceup(loc[i][1]);
    }
}
