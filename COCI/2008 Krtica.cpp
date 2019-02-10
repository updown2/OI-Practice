/*
https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/COCI/official/2009/contest1_solutions/solutions.pdf
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
#define e endl//"\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
//#define int ll
//500,000,000 operations
const int MAXN = 300000, INF = 1000000000;
//Global Variables
int N, out=INF, d1[MAXN], o1, o2, sd1, sd2, o3, o4, dist[MAXN];
vector<int> adj[MAXN];
int und[MAXN][3];

void ans(int d1, int d2, int s1, int s2) {
    int x = max(d1, max(d2, (d1+1)/2+1+(d2+1)/2));
    if (x < out) {
        out = x;
        o1 = s1, o2 = s2;
        sd1 = d1, sd2 = d2;
    }
}
void go1(int at, int p) {
    /// set und & d1
    for (auto i: adj[at]) if (i != p) {
        go1(i, at);
        d1[at] = max(d1[at], d1[i]);
        if (und[i][0]+1 > und[at][2]) {
            und[at][2] = und[i][0]+1;
            if (und[at][2] > und[at][1]) swap(und[at][2], und[at][1]);
            if (und[at][1] > und[at][0]) swap(und[at][0], und[at][1]);
        }
    }
    d1[at] = max(d1[at], und[at][0]+und[at][1]);
}
void go2(int at, int p, int best, int d2) {
    //w<< at+1 c best s d2<<e;
    multiset<int> vals; /// technically only need top 2, not all
    multiset<int>::iterator it;
    for (int i: adj[at]) if (i != p) vals.insert(d1[i]);
    /// set up for children
    for (auto i: adj[at]) if (i != p) {
        vals.erase(vals.find(d1[i]));
        int x = 0;
        if (!vals.empty()) {it = vals.end(); it--; x = *it;}
        if (at == 0) {
            if (und[i][0]+1 == und[at][0]) {
                /// take second best
                int use = max(x, und[at][1]+und[at][2]);
                ans(d1[i], use, i, at);
                go2(i, at, und[at][1]+1, use);
            }
            else if (und[i][0]+1 == und[at][1]) {
                /// take best and third best
                int use = max(x, und[at][0]+und[at][2]);
                ans(d1[i], use, i, at);
                go2(i, at, und[at][0]+1, use);
            }
            else {
                /// take best and second best
                int use = max(x, und[at][0]+und[at][1]);
                ans(d1[i], use, i, at);
                go2(i, at, und[at][0]+1, use);
            }
        }
        else {
            if (und[i][0]+1 == und[at][0]) {
                /// take the second best and third best
                int use = max(d2, max(x, max(best, und[at][2]) + und[at][1]));
                ans(d1[i], use, i, at);
                go2(i, at, max(und[at][1], best)+1, use);
            }
            else if (und[i][0]+1 == und[at][1]) {
                /// take the best and third best
                int use = max(d2, max(x, max(best, und[at][2]) + und[at][0]));
                ans(d1[i], use, i, at);
                go2(i, at, max(und[at][0], best)+1, use);
            }
            else {
                /// take the best and second best
                int use = max(d2, max(x, max(best, und[at][1]) + und[at][0]));
                ans(d1[i], use, i, at);
                go2(i, at, max(und[at][0], best)+1, use);
            }
        }
        vals.insert(d1[i]);
    }
}
bool go3(int at, int p, int d) {
    if (d == sd1) return true;
    bool ret = false;
    for (int i: adj[at]) if (i != p && go3(i, at, d+1)) ret = true;
    if (ret && d==sd1/2) o3 = at;
    return ret;
}
bool go4(int at, int p, int d) {
    if (d == sd2) return true;
    bool ret = false;
    for (int i: adj[at]) if (i != p && go4(i, at, d+1)) ret = true;
    if (ret && d==sd2/2) o4 = at;
    return ret;
}
void sd (int at, int p, int d) {
    dist[at] = d;
    for (int i: adj[at]) if (i != p) sd(i, at, d+1);
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    For (i, 1, N) {int a, b; cin >> a >> b; a--; b--; adj[a].pb(b); adj[b].pb(a);}
    go1(0, -1);
    //ffi w<< d1[i]<<e;
    go2(0, -1, 0, 0);
    w<< out<<e << o1+1 s o2+1<<e;
    /// delete the edge
    adj[o1].erase(find(adj[o1].begin(), adj[o1].end(), o2));
    adj[o2].erase(find(adj[o2].begin(), adj[o2].end(), o1));
    sd(o1, -1, 0);
    int big = 0, at = 0;
    ffi if (dist[i] > big) {
        big = dist[i];
        at = i;
    }
    o1 = at;
    ffi dist[i] = 0;
    sd(o2, -1, 0);
    big = 0, at = 0;
    ffi if (dist[i] > big) {
        big = dist[i];
        at = i;
    }
    o2 = at;
    go3(o1, -1, 0); go4(o2, -1, 0);
    w<< o3+1 s o4+1<<e;
}
