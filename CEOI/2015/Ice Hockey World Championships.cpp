/*
come up with all combinations of money for the left and right half
count the total ways by binary searching the right values for each left value
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, K)
#define ffa ffi ffj
#define s <<" "<<
#define c <<" : "<<
#define w cout
#define e endl//"\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
//500,000,000 operations
const int MAXN = 40, INF = 1000000000;
//Global Variables
int N, M, inp[MAXN], out;
vector<int> le, ri;

main() {
	//ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    ffi cin >> inp[i];
    le.pb(0), ri.pb(0);
    For (i, 0, N/2) {
        /// left half
        for (int j=le.size()-1; j>=0; j--) le.pb(le[j]+inp[i]);
    }
    //for (int i: le) w<< i<< " "; w<<e;
    For (i, N/2, N) {
        /// right half
        for (int j=ri.size()-1; j>=0; j--) ri.pb(ri[j]+inp[i]);
    }
    //for (int i: ri) w<< i<< " "; w<<e;
    /// combine left and right sides
    sort(ri.begin(), ri.end());
    for (int i: le) {
        if (i > M) continue;
        /// find biggest val in right s.t. i+val <= M, no edge cases bc 0 is a value
        int a = 0, b = ri.size()-1;
        while (a != b) {
            int mid = (a+b+1)/2;
            if (i+ri[mid] <= M) a = mid;
            else b = mid-1;
        }
        out += a+1;
    }
    w<< out<<e;
}
