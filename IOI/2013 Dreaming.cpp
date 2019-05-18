/*
- find a node x in each component such that the max distance from x to a leaf
is minimized
- connect the x's from all the components to the x in the biggest component
- ans = max(path in one component, biggest depth + 2nd biggest depth + L, 2nd biggest depth + 3rd biggest depth + 2*L
*/
//#include "dreaming.h"
#include "grader.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(ll i=a; i<b; i++)
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
const ll MAXN = 100000, MAX_N = 100000, INF = 1000000000000000000;
//500,000,000 operations
ll farund[MAXN], far2[MAXN], out, sm;
pair<ll, ll> far1[MAXN]; /// (value, child)
vector<ll> vals;
bool vis[MAXN];
vector<pair<ll, ll> > adj[MAXN];

void go1(ll at) {
    if (vis[at]) return;
    vis[at] = true;
    for (auto i: adj[at]) if (!vis[i.a]) {
        go1(i.a);
        farund[at] = max(farund[at], i.b+farund[i.a]);
    }
}
void go2(ll at, ll p, ll d) {
    if (vis[at]) return;
    vis[at] = true;
    for (auto i: adj[at]) if (i.a != p) {
        ll len = farund[i.a] + i.b;
        if (len > far1[at].a) {
            far2[at] = far1[at].a;
            far1[at] = mp(len, i.a);
        }
        else if (len > far2[at]) far2[at] = len;
    }
    if (at != p) {
        ll up;
        if (far1[p].b == at) up = far2[p]+d;
        else up = far1[p].a + d;
        if (up > far1[at].a) {
            far2[at] = far1[at].a;
            far1[at] = mp(up, p);
        }
        else if (up > far2[at]) far2[at] = up;
        //w<< "up" s at c up<<e;
    }
    for (auto i: adj[at]) if (i.a != p) go2(i.a, at, i.b);
}
void go3(ll at) {
    if (vis[at]) return;
    vis[at] = true;
    sm = min(sm, far1[at].a);
    for (auto i: adj[at]) go3(i.a);
}


int travelTime(int N, int M, int L, int A[], int B[], int T[]) {
    ffj {
        ll a = A[j], b = B[j], d = T[j];
        adj[a].emplace_back(b, d);
        adj[b].emplace_back(a, d);
    }
    ffi go1(i);
    ffi vis[i] = false;
    ffi go2(i, i, 0);
    //ffi w<< i c far1[i].a<<e;
    ffi out = max(out, far1[i].a);
    ffi vis[i] = false;
    ffi if (!vis[i]) {
        sm = INF;
        go3(i);
        vals.pb(sm);
        //w<< i c sm<<e;
    }
    sort(vals.begin(), vals.end());
    reverse(vals.begin(), vals.end());
    if (vals.size() >= 2) out = max(out, vals[0]+vals[1]+L);
    if (vals.size() >= 3) out = max(out, vals[1]+vals[2]+2*L);
    return out;
}
