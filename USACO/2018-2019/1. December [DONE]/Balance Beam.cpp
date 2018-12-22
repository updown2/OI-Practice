#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 1, N+1)
#define ffj For(j, 0, M)
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
#define double long double
const int MAXN=100002;
///500,000,000
int N, inp[MAXN], l, r, big=-1, ans[MAXN];
vector<int> vals;

main() {
    //ifstream cin("test.in");
    ifstream cin("balance.in"); ofstream cout("balance.out");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	ffi {
	    cin >> inp[i];
	    if (inp[i] > big) {
            big = inp[i];
            l = r = i;
	    }
	    if (inp[i] == big) r = i;
	}
	For (i, l, r+1) ans[i] = 100000*big;
	vals.pb(0);
	For (i, 1, l+1) {
        while (vals.size() >= 2 && (inp[i] - inp[vals[vals.size()-2]])/(double)(i - vals[vals.size()-2]) < (inp[i] - inp[vals[vals.size()-1]])/(double)(i - vals[vals.size()-1])) {
            vals.pop_back();
        }
        vals.pb(i);
	}
	//for (int i: vals) w<< i<<e;
	int at = 1;
	For (i, 1, l) {
        if (vals[at] == i) at++;
        int a = vals[at-1], b = vals[at];
        double m = (inp[b] - inp[a]) / (double)(b-a);
        double x = inp[a] + m*(i-a);
        ans[i] = 100000*(x+.0000000001);
	}
	vals.clear();
	vals.pb(N+1);
	for (int i=N; i>=r; i--) {
        while (vals.size() >= 2 && (inp[i] - inp[vals[vals.size()-2]])/(double)(i - vals[vals.size()-2]) > (inp[i] - inp[vals[vals.size()-1]])/(double)(i - vals[vals.size()-1])) {
            vals.pop_back();
        }
        vals.pb(i);
	}
	reverse(vals.begin(), vals.end());
	//for (int i: vals) w<< i<<e;
	at = 1;
	For (i, r+1, N+1) {
        if (vals[at] == i) at++;
        int a = vals[at-1], b = vals[at];
        double m = (inp[b] - inp[a]) / (double)(b-a);
        double x = inp[a] + m*(i-a);
        ans[i] = 100000*(x+.0000000001);
	}
	//w<< 6 c ans[6] <<e<<11 c ans[11]<<e;
	ffi w<<ans[i]<<e;
}
