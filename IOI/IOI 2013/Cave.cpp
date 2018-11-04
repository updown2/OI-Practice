//#include "grader.h" /// yandex
#include "cave.h" /// oj.uz
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
#define e endl
#define pb push_back
#define mp make_pair
#define a first
#define b second
//#define int ll
const int MAXN = 5000;
//500,000,000 operations
int S[MAXN], D[MAXN];
bool done[MAXN];
void toggle (int a, int b) {
    For (i, a, b+1) if (!done[i]) S[i] = 1-S[i];
}
void exploreCave(int N) {
    ffi {
        /// determine which switch effects this door
        ffj if (!done[j]) S[j] = 0;
        int x = tryCombination(S);
        bool pp = (x == -1 || x > i);
        int a = 0, b = N-1;
        while (a != b) {
            int mid = (a+b)/2;
            toggle(a, mid);
            x = tryCombination(S);
            bool p = (x == -1 || x > i);
            if (pp != p) b = mid;
            else a = mid+1;
            pp = p;
        }
        D[a] = i;
        done[a] = true;
        if (!pp) S[a] = 1-S[a];
    }
    answer(S, D);
}
