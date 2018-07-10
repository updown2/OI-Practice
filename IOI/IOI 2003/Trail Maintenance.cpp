/*
Find the Minimum Spanning Tree after each week
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, W)
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
const int MAXN = 200, INF = 1000000000000000000;
//Global Variables
int N, W, edges[6000][3]; /// (cost, a, b)
bool vis[MAXN];
int root[MAXN], siz[MAXN];

int getroot(int i) {
    if (i == root[i]) return i;
    return getroot(root[i]);
}

int compare_first(const void * a, const void * b) {
	const int * ia = (const int *)a;
	const int * ib = (const int *)b;

	return ia[0] - ib[0];
}
int calc(int M) {
    int out = 0;
    ffi root[i] = i, siz[i] = 1;
    For (i, 0, M) {
        int a = getroot(edges[i][1]), b = getroot(edges[i][2]);
        if (a == b) continue;
        out += edges[i][0];
        if (siz[a] < siz[b]) swap(a, b);
        root[b] = a;
        siz[a] += siz[b];
    }
    int a = getroot(0);
    ffi if (getroot(i) != a) return -1;
    return out;
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> W;
    For (i, 0, W) {
        cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
        edges[i][1]--; edges[i][2]--;
        qsort(edges, i+1, 3*sizeof(int), compare_first);
        w<< calc(i+1)<<endl;
    }
}
