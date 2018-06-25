/*
sort by size
use same algo as max continuous subsequence sum
keep adding next picture until it would be better to not take previous
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, M)
#define ffa ffi ffj
#define s <<" "<<
#define w cout
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
const int MAXN=500000, INF=1000000000000000000;
///500,000,000
int N, curr, out;
pair <int, int> inp[MAXN];

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    ffi cin >> inp[i].a >> inp[i].b;
    sort(inp, inp+N);
    curr = out = inp[0].b;
    For (i, 1, N) {
        /// add value, subtract size - size[i-1]
        curr += inp[i].b - (inp[i].a - inp[i-1].a);
        curr = max(curr, inp[i].b);
        out = max(out, curr);
    }
    w<< out<<e;
}
