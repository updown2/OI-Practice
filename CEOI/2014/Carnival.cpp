/*
Binary search to find the costume
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, M+1)
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
//500,000,000 operations
const int MAXN = 150;
//Global Variables
int N, costume[MAXN], at = 1, ind[MAXN];

int query(int M, int x) {
    printf("%d", M+2);
    //w<< M+2;
    ffj printf(" %d", ind[j]+1);//w s ind[j]+1;
    //w s x+1<<e;
    printf(" %d\n", x+1);
    fflush(stdout);
    int a; cin >> a; return a;
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    For (i, 1, N) {
        if (query(at-1, i) == at+1) {
            /// i is a new costume
            costume[i] = at;
            ind[at] = i;
            at++;
            continue;
        }
        int a = 0, b = at-1;
        while (a != b) {
            int mid = (a+b)/2;
            if (query(mid, i) == mid+2) a = mid+1;
            else b = mid;
        }
        costume[i] = a;
    }
    w<< 0;
    ffi w s costume[i]+1; w<<e;
}
