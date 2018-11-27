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
#define e endl//"\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
//#define int ll
const int MAXN=1000000;
///500,000,000
int N, comp[MAXN], cat, nonn[MAXN], nd[MAXN], v[MAXN];
ll siz[MAXN], out;
vector<ll> pre, ans;
vector<int> st;
bool vis[MAXN], cyc[MAXN];
queue<int> next1;
vector<pair<int, int> > adj[MAXN]; /// (node, cost)

void go(int at) {
    if (comp[at] != -1) return;
    comp[at] = cat;
    for (auto i: adj[at]) go(i.a);
}
void calc_size(int at) {
    if (vis[at]) return;
    vis[at] = true;
    if (adj[at].size() == 1) return;
    ll b1 = 0, b2 = 0;
    for (auto i: adj[at]) if (!cyc[i.a] && !vis[i.a]) {
        calc_size(i.a);
        siz[at] = max(siz[at], i.b+siz[i.a]);
        if (siz[i.a]+i.b >= b1) {b2 = b1; b1 = i.b+siz[i.a];}
        else if (siz[i.a]+i.b > b2) {b2 = i.b+siz[i.a];}
    }
    //w<< at+1 c b1 s b2<<e;
    ans[comp[at]] = max(ans[comp[at]], b1+b2);
}
ll solve (int x) {
    ll ret = 0;
    int loc = 0; int at = st[x];
    //w<< "comp" s x <<e;
    while (at != st[x] || loc == 0) {
        //w<< at+1<<e;
        v[loc] = at;
        vis[at] = true;
        bool found = false;
        for (auto i: adj[at]) if (!vis[i.a]) {
            nd[loc] = i.b;
            at = i.a;
            found = true;
            break;
        }
        if (!found) {
            vis[st[x]] = false;
            for (auto i: adj[at]) if (!vis[i.a]) {
                nd[loc] = i.b;
                at = i.a;
            }
        }
        loc++;
    }
    if (loc == 1) {while (true){}} /// basically an assert
    while (pre.size() < loc) pre.pb(0);
    //For (i, 0, loc) w<< ns[i] s nd[i]<<e;
    pre[0] = siz[v[0]];
    ll curr = 0;
    For (i, 1, loc) {
        curr += nd[i-1];
        pre[i] = max(pre[i-1], curr+siz[v[i]]);
        ret = max(ret, curr+siz[v[0]] + siz[v[i]]);
    }
    //For (i, 0, loc) w<< "pre" s i c pre[i]<<e;
    ll y = nd[loc-1] + siz[v[loc-1]];
    curr = nd[loc-1];
    for (int i=loc-2; i>=0; i--) {
        curr += nd[i];
        ret = max(ret, pre[i] + y);
        y = max(y, curr+siz[v[i]]);
    }
    //For (i, 0, loc) w<< "suf1" s i c suf1[i]<<e;
    //w<< "from pass 1, ret =" s ret<<e;

    pre[0] = siz[v[0]];
    For (i, 1, loc) pre[i] = max(pre[i-1]+nd[i-1], siz[v[i]]);
    //For (i, 0, loc) w<< "pre" s i c pre[i]<<e;
    ret = max(ret, pre[loc-1]);
    y = 0;
    for (int i=loc-2; i>=0; i--) {
        y = max(y+nd[i], siz[v[i+1]]+nd[i]);
        ret = max(ret, pre[i]+y);
    }
    //For (i, 0, loc) w<< "suf2" s i c suf2[i]<<e;
    //w<< "after pass 2, ret =" s ret<<e;
    return max(ret, ans[x]);
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    ffi {cyc[i] = true; comp[i] = -1; int b, d; cin >> b >> d; b--; adj[i].pb(mp(b, d)); adj[b].pb(mp(i, d));}
    ffi if (comp[i] == -1) {go(i); cat++;}
    For (i, 0, cat) ans.pb(0), st.pb(0);
    ffi if (adj[i].size() == 1) {next1.push(i); cyc[i] = false;}
    while (!next1.empty()) {
        int at = next1.front(); next1.pop();
        for (auto i: adj[at]) {
            nonn[i.a]++;
            if (cyc[i.a] && nonn[i.a] == adj[i.a].size()-1) {next1.push(i.a); cyc[i.a] = false;}
        }
    }
    ffi vis[i] = false;
    //ffi w<< i+1 c cyc[i]<<e;
    ffi if (cyc[i]) {st[comp[i]] = i; calc_size(i);}
    //ffi w<< i+1 c siz[i]<<e;
    ffi {
        vis[i] = false;
        if (!cyc[i]) vis[i] = true;
    }
    For (i, 0, cat) out += solve(i);
    w<< out <<e;
}
