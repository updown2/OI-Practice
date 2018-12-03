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
queue<string> q;

void R(int a) {q.push("R"+to_string(a));}
void L(int a) {q.push("L"+to_string(a));}
void si(int i, int j);
void solve(int i, int j) {
    if (i == j) {R(i); return;}
    if (j == i+1) {R(i); R(i+1); L(i); L(i+1); return;}
    solve(i, (i+j)/2); solve((i+j)/2 + 1, j); si(i, (i+j)/2); si((i+j)/2 + 1, j);
}
void si(int i, int j) {
    if (i == j) {L(i); return;}
    if (j == i+1) {R(i+1); R(i); L(i+1); L(i); return;}
    solve((i+j)/2 + 1, j); solve(i, (i+j)/2); si((i+j)/2 + 1, j); si(i, (i+j)/2);
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    For (t, 1, T+1) {
        cin >> N;
        w<< "Picture #" << t<<":";
        solve(1, N);
        w s q.size(); while (!q.empty()) {w s q.front(); q.pop();} w<<e;
    }
}
