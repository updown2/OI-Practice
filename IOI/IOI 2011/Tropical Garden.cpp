/*
solution: https://www.ioi2011.or.th/hsc/tasks/solutions/garden.pdf
df[i].a = distance to 2*P
df[i].b = distance to 2*P twice
ds[i].a = distance to 2*P+1
ds[i].b = distance to 2*P+1 twice
*/
#include "grader.h"
//#include "garden.h"
//#include "gardenlib.h"
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
#define e endl//"\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
const ll MAXN=300000, INF = 1000000000;
int edges[MAXN][2], nex[MAXN];
bool open[MAXN];
vector<int> adj[MAXN]; /// value is index/2, want minimum next one
pair<int, int> ds[MAXN], df[MAXN];

void go11 (int at) {
    if (df[at].a != INF) return;
    if (open[at]) {df[at].a = -INF; return;}
    open[at] = true;
    go11 (nex[at]);
    /// set df[at]
    df[at].a = 1+df[nex[at]].a;
    open[at] = false;
}
void go12 (int at) {
    if (df[at].b != INF) return;
    if (open[at]) {df[at].b = -INF; return;}
    open[at] = true;
    go12 (nex[at]);
    /// set df[at]
    df[at].b = 1+df[nex[at]].b;
    open[at] = false;
}

void go21 (int at) {
    if (ds[at].a != INF) return;
    if (open[at]) {ds[at].a = -INF; return;}
    open[at] = true;
    go21 (nex[at]);
    /// set ds[at]
    ds[at].a = 1+ds[nex[at]].a;
    open[at] = false;
}
void go22 (int at) {
    if (ds[at].b != INF) return;
    if (open[at]) {ds[at].b = -INF; return;}
    open[at] = true;
    go22 (nex[at]);
    /// set ds[at]
    ds[at].b = 1+ds[nex[at]].b;
    open[at] = false;
}



void count_routes(int N, int M, int P, int R[][2], int Q, int G[]) {
    for (int j=M-1; j>=0; j--) {
        edges[2*j][0] = edges[2*j+1][1] = R[j][0];
        edges[2*j][1] = edges[2*j+1][0] = R[j][1];
        adj[R[j][0]].pb(2*j);
        adj[R[j][1]].pb(2*j+1);
    }
    ffi {
        sort(adj[i].begin(), adj[i].end());
        while (adj[i].size() > 2) adj[i].pop_back();
        if (adj[i].size() == 1) adj[i].pb(adj[i][0]); /// repeat the element
    }
    ffi {
        int x = adj[i][0]; /// edge
        int a = edges[x][1]; /// node
        int y = adj[a][0]; /// edge
        if (x/2 == y/2) nex[2*i] = 2*a+1;
        else nex[2*i] = 2*a;
        x = adj[i][1]; /// edge
        a = edges[x][1]; /// node
        y = adj[a][0]; /// edge
        //w<< i s a c x s y<<e;
        if (x/2 == y/2) nex[2*i+1] = 2*a+1;
        else nex[2*i+1] = 2*a;
        ds[2*i] = ds[2*i+1] = df[2*i] = df[2*i+1] = mp(INF, INF);
    }
//For (i, 0, 2*N) w<< i/2 c nex[i]/2 s nex[i]%2<<e;

    df[2*P].a = 0; /// we are already at P
    For (i, 0, 2*N) go11(i);
//For (i, 0, 2*N) w<< i/2 c df[i].a<<e;
    df[2*P].b = 1+ df[nex[2*P]].a;
    For (i, 0, 2*N) go12(i);
//For (i, 0, 2*N) w<< i/2 c df[i].b<<e;
    ds[2*P+1].a = 0; /// we are already at P
    For (i, 0, 2*N) go21(i);
//For (i, 0, 2*N) w<< i/2 c ds[i].a<<e;
    ds[2*P+1].b = 1+ ds[nex[2*P+1]].a;
    For (i, 0, 2*N) go22(i);
//For (i, 0, 2*N) w<< i/2 c ds[i].b<<e;


    for(int i=0; i<Q; i++) {
        int x = G[i];
        int out = 0;
        for (int j=0; j<2*N; j+= 2) {
            if (x == df[j].a) {out++; continue;}
            else if (x < df[j].a || df[j].a < 0 || df[j].b < 0) {}
            else {
//w<< j c df[j].a s df[j].b<<e;
                if (df[j].b != df[j].a && (x-df[j].a) % (df[j].b - df[j].a) == 0) {out++; continue;}
            }

            if (x == ds[j].a) {out++; continue;}
            else if (x < ds[j].a || ds[j].a < 0 || ds[j].b < 0) {}
            else {
//w<< j c ds[j].a s ds[j].b<<e;
                if (ds[j].b != ds[j].a && (x-ds[j].a) % (ds[j].b - ds[j].a) == 0) {out++; continue;}
            }
        }
//w<< "got" s i c out<<e;
        answer(out);
    }
}
