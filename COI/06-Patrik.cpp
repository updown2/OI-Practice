/*
monotomic queue - the stack has values in decreasing order pair<value, count>
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
#define e endl // "/n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
//500,000,000 operations
const int MAXN = 301, INF = 1000000000;
//Global Variables
int N, out;
stack<pair<int, int> > vals;

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    ffi {
        int a; cin >> a;
        while (!vals.empty() && a > vals.top().a) {out += vals.top().b; vals.pop();}
        if (!vals.empty() && a == vals.top().a) {
            out += vals.top().b;
            vals.top().b++;
            pair<int, int> save = vals.top(); vals.pop();
            if (!vals.empty()) out++;
            vals.push(save);
        }
        else {
            if (!vals.empty()) out++;
            vals.push(mp(a, 1));
        }
        //w<< a c out<<e;
    }
    w<< out<<e;
}
