#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, O)
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
const int MAXN = 3000, INF = 100000000000000;
//Global Variables
int T, O, N, cnt[10001], inp[MAXN], out;

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    For (t, 1, T+1) {
        cin >> O >> N;
        For (i, 0, 10001) cnt[i] = 0;
        ffj {int a; cin >> a; cnt[a]++;}
        ffi cin >> inp[i];
        sort(inp, inp+N);
        out = 0;
        ffi {
            int favor = 0;
            For (j, 0, inp[i]+1) favor += cnt[j];
            int against = O+out - favor;
            if (favor > against) {
                /// add team
                out++;
                cnt[inp[i]]++;
            }
        }
        w<< "Expansion #"<<t<<":" s out<<e;
    }
}
