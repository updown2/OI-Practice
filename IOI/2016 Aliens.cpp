#include "aliens.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(ll i=a; i<b; i++)
#define ffi For(i, 0, n)
#define ffj For(j, 0, K)
#define ffa ffi ffj
#define s <<" "<<
//#define c <<" : "<<
#define w cout
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
//#define int ll
//500,000,000 operations
const ll MAXN = 100001, INF = 1000000000000000000;
vector<pair<ll, ll> > pts, inp;
ll dp[MAXN], cnt[MAXN], M;


struct Line {
    ll A, B, l, r, ccc;
    Line() {}
    Line (ll a, ll b, ll c, ll d, ll x) {
        A = a; B = b; l = c; r = d, ccc=x;
    }
};

vector<Line> lines;

bool under(ll A1, ll B1, ll c1, ll A2, ll B2, ll c2, ll x) {
    ll y1 = A1*x+B1, y2 = A2*x+B2;
    return (y1 < y2 || (y1 == y2 && c1 <= c2));
}

void addline(ll i) {
    ll y = 0;
    if (i != 0 && inp[i-1].b >= inp[i].a ) y = (inp[i-1].b-inp[i].a+1)*(inp[i-1].b-inp[i].a+1);
    ll A = -2*inp[i].a; ll B = dp[i]-y + inp[i].a*inp[i].a - 2*inp[i].a;
    while (!lines.empty() && under(A, B, cnt[i], lines.back().A, lines.back().B, lines.back().ccc, lines.back().l)) lines.pop_back();
    y = 0;
    if (!lines.empty()) {
        ll A2 = lines.back().A, B2 = lines.back().B;
        if (under(A2, B2, lines.back().ccc, A, B, cnt[i], M-1)) return;
        ll meet = (B2-B)/(A-A2);
        lines.back().r = meet;
        y = meet+1;
    }
    //w<< "Line" s i+1 s ":" s A s B<<e;
    lines.emplace_back(Line(A, B, y, M-1, cnt[i]));
}

pair<ll, ll> query(ll x) {
    ll a = 0, b = lines.size()-1;
    while (a != b) {
        ll mid = (a+b+1)/2;
        if (lines[mid].l > x) b = mid-1;
        else a = mid;
    }
    return mp(lines[a].A*x+lines[a].B, lines[a].ccc);
}

ll calc(ll C) {
    //w<< "testing" s C<<e;
    ll len = inp.size();
    lines.clear();
    For (i, 1, len+1) {
        addline(i-1);
        pair<ll, ll> use = query(inp[i-1].b);
        //w<< "got" s i s ":" s use.a s use.b<<e;
        dp[i] = use.a + inp[i-1].b*inp[i-1].b + 2*inp[i-1].b+1+C;
        cnt[i] = use.b+1;
        //w<< dp[i] s cnt[i]<<e;
    }
    //w<< C s cnt[inp.size()]<<e;
    return cnt[inp.size()];
}

long long take_photos(int n, int m, int k, std::vector<int> r, std::vector<int> c) {
    ffi pts.pb(mp(min(r[i], c[i]), max(r[i], c[i]))); sort(pts.begin(), pts.end());
    M = m;
    for (auto i: pts) {
        if (inp.empty()) inp.pb(i);
        else if (i.b <= inp[inp.size()-1].b) continue; /// don't add it
        else {
            while (!inp.empty() && i.a == inp[inp.size()-1].a && i.b >= inp[inp.size()-1].b) inp.pop_back();
            inp.pb(i);
        }
        //w<< i.a s i.b<<e;
    }
    //w<<"keep"<<e; for (auto i: inp) w<< i.a s i.b<<e;
    /// binary search on C
    ll a = 0, b = m*(ll)m;
    while (a != b) {
        ll mid = (a+b+1)/2;
        if (calc(mid) < k) b = mid-1;
        else a = mid;
    }
    calc(a); ll p1 = cnt[inp.size()]; ll f1 = dp[inp.size()] - a*p1;
    calc(a+1); ll p2 = cnt[inp.size()]; ll f2 = dp[inp.size()] - (a+1)*p2;
    //w<< "C:" s a s ":" s p1 s p2<<e;
    if (p1 == p2) return f1;
    //w<< f1 s f2 s p1 s p2<<e;
    return f1 + (f2-f1)/(p2-p1) * (k-p1);
}
