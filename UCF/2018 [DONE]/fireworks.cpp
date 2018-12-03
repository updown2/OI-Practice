#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, Q)
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
const int MAXN = 2000, INF = 100000000000000;
//Global Variables
int T, N;
pair<int, int> inp[MAXN];

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    For (t, 1, T+1) {
        w<< "Scenario" s "#"<<t<<":"<<e;
        cin >> N;
        ffi {cin >> inp[i].a; inp[i].b = i+1;}
        sort(inp, inp+N);
        w<< "Highest Firework:" s inp[N-1].b<<e;
        w<< "Earliest Firework:" s inp[0].b<<e;
        w<<e;
    }
}
