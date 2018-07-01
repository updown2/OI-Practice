/*
Disjoint sets. Say yes and combining two sets if all other siz[i]*siz[j]-1 queries are no
*/
#include "grader.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, N)
#define ffa ffi ffj
#define w cout
#define e "\n"
#define s <<" "<<
#define pb push_back
const int MAXN = 1500;
int N, root[MAXN], siz[MAXN], no[MAXN][MAXN];

int getroot(int x) {
    if (root[x] == x) return x;
    return getroot(root[x]);
}

void initialize(int n) {
    N = n;
    ffi root[i] = i, siz[i] = 1;
}

int hasEdge(int u, int v) {
    u = getroot(u); v = getroot(v);
    if (u == v) return 1;
    if (no[u][v] < siz[u]*siz[v]-1) {
        /// not all no's
        no[u][v]++; no[v][u]++;
        return 0;
    }
    /// say yes and combine
    if (siz[u] < siz[v]) swap(u, v);
    /// combine into u
    siz[u] += siz[v];
    root[v] = u;
    ffi no[u][i] += no[v][i];
    ffi no[i][u] += no[v][i];
    return 1;
}