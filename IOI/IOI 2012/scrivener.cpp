/*
store what letter is 2^0 ahead, 2^1 ahead, ...
*/

#include "grader.h"
char last;

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, M)
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
const int MAXN=1000001;
///500,000,000
int N, pt[MAXN], len[MAXN], up[MAXN][20];
char let[MAXN];
bool num[MAXN];

void Init() {}
void TypeLetter(char L) {
    N++;
    let[N] = L;
    if (num[N-1]) up[N][0] = pt[N-1];
    else up[N][0] = N-1;
    len[N] = 1+len[up[N][0]];
    For (k, 1, 20) up[N][k] = up[up[N][k-1]][k-1];
}
void UndoCommands(int U) {
    N++;
    pt[N] = N-U-1;
    num[N] = true;
    if (num[pt[N]]) pt[N] = pt[pt[N]];
}
char GetLetter(int P) {
    int at = N;
    if (num[at]) at = pt[at];
    int x = len[at]-1-P;
    for (int k=19; k>=0; k--) if (x & (1<<k)) at = up[at][k];
    return let[at];
}
