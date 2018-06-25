/*
greedily remove gaps between people
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
const int MAXN=100000, INF=2000000000000000000;
///500,000,000
int N, K, inp[MAXN], out;
priority_queue<int> gap;

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    ffi cin >> inp[i]; sort(inp, inp+N);
    For (i, 1, N+1) gap.push(inp[i] - inp[i-1]-1);
    out = inp[N-1]-inp[0]+1;
    For (i, 1, K) {
        int x = gap.top(); gap.pop(); out -= x;
        //w<< x<<e;
    }
    w<< out<<e;
}
