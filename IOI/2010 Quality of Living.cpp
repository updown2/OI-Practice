/*
https://luckytoilet.wordpress.com/2010/08/18/ioi-2010-quality-of-living/
*/
#include "grader.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 1, N+1)
#define ffj For(j, 1, M+1)
#define ffa ffi ffj
#define s <<" "<<
#define c <<" : "<<
#define w cout
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
//#define int ll
const int MAXN = 3001, MAXR = 25000;
//500,000,000 operations
int N, M, H1, W1, grid[MAXN][MAXN], pre[MAXN][MAXN];

bool bet(int x) {
    //w<< "at" s x<<e;
    ffa {
        if (grid[i][j] > x) pre[i][j] = 1;
        else if (grid[i][j] == x) pre[i][j] = 0;
        else pre[i][j] = -1;
    }
    //ffi {ffj w<< pre[i][j]<< " "; w<<e;}
    ffa pre[i][j] += pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
    For (i, H1, N+1) For (j, W1, M+1) if (pre[i][j] - pre[i-H1][j] - pre[i][j-W1] + pre[i-H1][j-W1] < 0) {
        //w<< x c i s j<<e;
        return true;
    }
    return false;
}


int rectangle(int R, int C, int H, int W, int Q[3001][3001]) {
    N = R, M = C, H1 = H, W1 = W;
    ffa grid[i][j] = Q[i-1][j-1];
    //ffi {ffj w<< grid[i][j]<< " "; w<<e;}
    int a = 1, b = N*M;
    while (a != b) {
        int mid = (a+b+1)/2;
        if (bet(mid)) b = mid-1;
        else a = mid;
        //w<< mid c bet(mid)<<e;
    }
    return a;
}
