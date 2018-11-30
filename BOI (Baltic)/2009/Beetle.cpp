/*
solution:
http://www.csc.kth.se/contest/boi/beetle-spoiler.pdf
*/
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
#define e endl // "/n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
//#define int ll
//500,000,000 operations
const int MAXN = 301, INF = 1000000000;
//Global Variables
int N, M, st, x[MAXN], L[MAXN][MAXN][2], R[MAXN][MAXN][2], out; /// min to subtract, cannot take in the range i to j

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    ffi cin >> x[i];
    N++;
    sort(x, x+N);
    ffi if (x[i] == 0) st = i;
    For (k, 1, N) {
        ffa {
            if (i == 0 && j == N-1) L[i][j][k%2] = R[i][j][k%2] = INF;
            else if (i == 0) {
                L[i][j][k%2] = R[i][j+1][(k+1)%2] + k*(x[j+1]-x[i]);
                R[i][j][k%2] = R[i][j+1][(k+1)%2] + k*(x[j+1]-x[j]);
            }
            else if (j == N-1) {
                L[i][j][k%2] = L[i-1][j][(k+1)%2] + k*(x[i]-x[i-1]);
                R[i][j][k%2] = L[i-1][j][(k+1)%2] + k*(x[j]-x[i-1]);
            }
            else {
                L[i][j][k%2] = min(L[i-1][j][(k+1)%2] + k*(x[i]-x[i-1]), R[i][j+1][(k+1)%2] + k*(x[j+1]-x[i]));
                R[i][j][k%2] = min(L[i-1][j][(k+1)%2] + k*(x[j]-x[i-1]), R[i][j+1][(k+1)%2] + k*(x[j+1]-x[j]));
            }
        }
        out = max(out, M*k - L[st][st][k%2]);
    }
    w<< out<<e;
}
