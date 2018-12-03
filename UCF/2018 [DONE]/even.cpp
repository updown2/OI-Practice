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
#define e endl // "/n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
//500,000,000 operations
const int MAXN = 3000, INF = 100000000000000;
//Global Variables
int T, N, p2[31];

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    p2[0] = 1;
    For (i, 1, 31) p2[i] = 2*p2[i-1];
    For (t, 0, T) {
        cin >> N;
        For (i, 0, 31) if (p2[i] > N) {
            w<< "Pokemon" s t+1<< ":" s p2[i]-N<<e;
            break;
        }
    }
}
