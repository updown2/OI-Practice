/*
save the last row and col update and the time of the update
after all updates, loop through the grid and take the value of the row or col, whichever has the greatest time
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, N)
#define ffa ffi ffj
#define s <<" "<<
#define w cout
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
//#define int ll
const int MAXN=6000, INF=1000000000000000000;
///500,000,000
ll N, P, col[MAXN], row[MAXN], rt[MAXN], ct[MAXN], out;

int main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> P;
    For (p, 1, P+1) {
        string a; int b, c; cin >> a >> b >> c; b--;
        if (a[0] == 'C') {col[b] = c; ct[b] = p;}
        else {row[b] = c; rt[b] = p;}
    }
    ffa {
        if (rt[i] > ct[j]) out += row[i];
        else out += col[j];
    }
    w<< out<<e;
}
