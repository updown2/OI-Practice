/*
http://ceoi2013.hsin.hr/tasks/tasks_and_solutions.pdf
*/
#include "treasure.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 1, N+1)
#define ffj For(j, 1, N+1)
#define ffa ffi ffj
#define s <<" "<<
#define c <<" : "<<
#define w cout
#define e endl//"\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
int pre[101][101]; /// prefix sums
void findTreasure (int N) {
    //int cnt = countTreasure(1, 1, N, N);
    //Report (2, 1);
    for (int i=N; i>=1; i--) for (int j=N; j>=1; j--) {
        if (i <= N/2 && j <= N/2) pre[i][j] = pre[N][j] + pre[i][N] + countTreasure(i+1, j+1, N, N) - pre[N][N];
        else if (i <= N/2) pre[i][j] = pre[N][j] - countTreasure(i+1, 1, N, j);
        else if (j <= N/2) pre[i][j] = pre[i][N] - countTreasure(1, j+1, i, N);
        else pre[i][j] = countTreasure(1, 1, i, j);
        //w<< i s j c pre[i][j] <<e;
    }
    ffa if (pre[i][j] - pre[i-1][j] - pre[i][j-1] + pre[i-1][j-1] == 1) Report(i, j);
}
