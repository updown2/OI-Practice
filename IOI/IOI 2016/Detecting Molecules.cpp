/*
Sort and two pointers
*/
#include <bits/stdc++.h>
#include "molecules.h"
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, M)
#define ffa ffi ffj
#define s <<" "<<
#define c <<" : "<<
//#define w cout
#define e endl
#define pb push_back
#define mp make_pair
#define a first
#define b second
//#define int ll
const int MAXN = 3000000;
//500,000,000 operations



std::vector<int> find_subset(int l, int u, std::vector<int> w) {
    //return std::vector<int>(0);
    vector<pair<int, int> > vals;
    For (i, 0, w.size()) vals.pb(mp(w[i], i));
    sort(vals.begin(), vals.end());
    ll lll = 0, sum = 0;
    For (r, 0, w.size()) {
        sum += vals[r].a;
        while (sum > u) {sum -= vals[lll].a; lll++;}
        if (sum >= l) {
            vector<int> ret;
            For (i, lll, r+1) ret.pb(vals[i].b);
            return ret;
        }
        //cout<< lll s r c sum s l s u<<e;
    }
    return std::vector<int>(0);
}
