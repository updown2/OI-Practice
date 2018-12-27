/*
sort the edges by s
binary search on the answer
use union find
*/
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
const int MAXN=100000, INF=100000000;
///500,000,000
int N, M, P, chk[MAXN][2], root[MAXN], siz[MAXN];
pair<int, pair<int, int> > edges[MAXN];

int top(int x) {
    if (root[x] == x) return x;
    return top(root[x]);
}

int main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    ffj {cin >> edges[j].b.a >> edges[j].b.b >> edges[j].a; edges[j].b.a --; edges[j].b.b--;}
    sort(edges, edges+M);
    cin >> P;
    For (i, 0, P) {cin >> chk[i][0] >> chk[i][1]; chk[i][0]--; chk[i][1]--;}
    int a = 1, b = INF;
    while (a != b) {
        int mid = (a+b)/2;
        /// reset
        ffi root[i] = i, siz[i] = 1;
        for (int i=0; i<M && edges[i].a <=mid; i++) {
            int x = top(edges[i].b.a), y = top(edges[i].b.b);
            if (x != y) {
                if (siz[x] > siz[y]) {
                    /// push y into x
                    root[y] = x;
                    siz[x] += siz[y];
                }
                else {
                    /// push x into y
                    root[x] = y;
                    siz[y] += siz[x];
                }
            }
        }
        /// check all pairs
        bool good = true;
        For (i, 0, P) if (top(chk[i][0]) != top(chk[i][1])) good = false;
        if (good) b = mid;
        else a = mid+1;
    }
    if (a == INF) w<< "MISSION IMPOSSIBLE"<<e;
    else w<< a<<e;
}
